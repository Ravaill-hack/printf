/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:52:02 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/11 15:19:43 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "libftprintf.h"

static int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i ++;
	}
	return (i);
}

static int	ft_putdec(int d)
{
	int			i;
	long int	nbr;

	i = 0;
	nbr = (long int) d;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		i ++;
	}
	if (nbr >= 10)
	{
		i += ft_putdec(nbr / 10);
	}
	ft_putchar(nbr % 10 + 48);
	i ++;
	return (i);
}

static int	ft_putundec(unsigned int u)
{
	int	i;

	i = 0;
	if (u >= 10)
		i += ft_putundec(u / 10);
	ft_putchar(u % 10 + 48);
	i ++;
	return (i);
}

static int	ft_putlowhexa(unsigned int x)
{
	int			i;
	long int	nbr;
	char		*hexa;

	i = 0;
	nbr = (long int) x;
	hexa = "0123456789abcdef";
	if (nbr >= 16)
	{
		i += ft_putlowhexa(nbr / 16);
	}
	ft_putchar(hexa[nbr % 16]);
	i ++;
	return (i);
}

static int	ft_putuphexa(unsigned int X)
{
	int			i;
	long int	nbr;
	char		*hexa;

	i = 0;
	nbr = (long int) X;
	hexa = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		i += ft_putuphexa(nbr / 16);
	}
	ft_putchar(hexa[nbr % 16]);
	i ++;
	return (i);
}

static int	ft_putadrhexa(void *p)
{
	int					i;
	unsigned long long	ptr;
	char				*hexa;

	i = 0;
	ptr = (unsigned long long) p;
	hexa = "0123456789abcdef";
	if (!ptr)
		return (ft_putstr("(nil)"));
	if (ptr == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	if (ptr >= 16)
	{
		i += ft_putlowhexa(((unsigned int)ptr) / 16);
	}
	ft_putchar(hexa[ptr % 16]);
	i ++;
	return (i + 2);
}

static int	ft_findset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	ft_symb(const char *arg, int i)
{
	if (arg[i] && (arg[i] != '\%'))
		return ('c');
	if ((arg[i] == '\%') && (ft_findset(arg[i + 1], "cspdiuxX\%") == 1))
		return (arg[i + 1]);
	return ('c');
}

static int	ft_isvar(const char *s, int i)
{
	if (s[i] == '\%')
	{
		if (s[i + 1] && (ft_findset(s[i + 1], "cspdiuxX\%") == 1))
			return (1);
	}
	return (0);
}

static int	ft_print_sth(va_list elem, const char *arg, char symb)
{
	int	ret;

	ret = 0;
	if (symb == 'c')
		ret = ft_putchar (va_arg(elem, int));
	if (symb == 's')
		ret = ft_putstr (va_arg(elem, char *));
	if (symb == 'p')
		ret = ft_putadrhexa(va_arg(elem, void *));
	if (symb == 'd' || symb == 'i')
		ret = ft_putdec(va_arg(elem, int));
	if (symb == 'u')
		ret = ft_putundec(va_arg(elem, unsigned int));
	if (symb == 'x')
		ret = ft_putlowhexa(va_arg(elem, unsigned int));
	if (symb == 'X')
		ret = ft_putuphexa(va_arg(elem, unsigned int));
	if (symb == '\%')
		ret = ft_putchar('\%');
	return (ret);
}

int	ft_printf(const char *arg, ...)
{
	va_list	elem;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(elem, arg);
	while (arg[i])
	{
		if ((ft_isvar(arg, i) == 0) && arg[i])
		{
			ft_putchar(arg[i]);
			i ++;
			ret ++;
		}
		if ((ft_isvar(arg, i) == 1) && arg[i] && arg[i + 1])
		{
			ret += ft_print_sth(elem, arg, ft_symb(arg, i));
			i = i + 2;
		}
	}
	va_end(elem);
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	void	*Test = (void *)123456;

	printf("%d\n",printf("Te%%st%s%p\n", (char *)NULL, NULL));
	printf("%d\n",ft_printf("Te%%st%s%p\n", (char *)NULL, NULL));
}
*/
