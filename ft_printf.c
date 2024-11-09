/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:52:02 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/09 12:04:47 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libft.h"
#include "libftprintf.h"

static char	*ft_type(char c)
{
	if (c == 'c')
		return ("char");
	if (c == 's')
		return ("char *");
	if (c == 'p' )
		return ("void *");
	if ((c == 'd') || (c == 'i'))
		return ("int");
	if ((c == 'u') || (c == 'x' ) || (c == 'X' ))
		return ("unsigned int");
}

static int	ft_putpercent(char *perc)
{

}

static int	ft_incremi(const char *arg, int i)
{
	while (arg[i] != '\0')
	{
		if((arg[i] == '\%') && (ft_findset(arg[i+1], "cspdiuxX\%") == 1))
			return (2);
		return (1);
	}
}



*/
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

static int	ft_putchar(int	c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i ++;
	}
	return (i);
}

static int	ft_puthexa(void *p)
{
	int	i;

	i = 0;
	return (i);	
}

static int	ft_putdec(int d)
{
	int	i;

	i = 0;
	return (i);		
}

static int	ft_putint10(int	i)
{
	int	i;

	i = 0;
	return (i);		
}

static int	ft_putundec(unsigned int u)
{
	int	i;

	i = 0;
	return (i);			
}

static int	ft_putlowhexa(unsigned int x)
{
	int	i;

	i = 0;
	return (i);		
}

static int	ft_putuphexa(unsigned int X)
{
	int	i;

	i = 0;
	return (i);		
}

static int	ft_findset(char	c, char *set)
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

static char ft_symb(const char *arg, int i)
{
	if (arg[i] && (arg[i] != '\%'))
		return ('c');
	if ((arg[i] == '\%') && (ft_findset(arg[i+1], "cspdiuxX\%") == 1))
		return (arg[i+1]);
	return ('c');
}

static int ft_isvar(const char *s, int i)
{
	if (s[i] == '\%')
	{
		if (s[i+1] && (ft_findset(s[i+1], "cspdiuxX") == 1))
			return (1);
	}
	return (0);
}

int	ft_printf(const char *arg, ...)
{
	va_list	elem;
	int		i;
	int		ret;
	char	symb;

	i = 	0;
	symb =	'c';
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
		if ((ft_isvar(arg, i) == 1) && arg[i] && arg[i+1])
		{
			symb = ft_symb(arg, i);
			if (symb == 'c')
				ret = ret + ft_putchar (va_arg(elem, int));
			if (symb == 's')
				ret = ret + ft_putstr (va_arg(elem, char *));
			if (symb == 'p')
				ret = ret + ft_puthexa(va_arg(elem, void *));
			if (symb == 'd')
				ret = ret + ft_putdec(va_arg(elem, int));
			if (symb == 'i')
				ret = ret + ft_putint10(va_arg(elem, int));
			if (symb == 'u')
				ret = ret + ft_putundec(va_arg(elem, unsigned int));
			if (symb == 'x')
				ret = ret + ft_putlowhexa(va_arg(elem, unsigned int));
			if (symb == 'X')
				ret = ret + ft_putuphexa(va_arg(elem, unsigned int));
			i = i + 2;
		}
	}
	va_end(elem);
	return (ret);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n",ft_printf("Test%s%c\n", "Code", 'a'));
	printf("%d\n",printf("Test%s%c\n", "Code", 'a'));
}
