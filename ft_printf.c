/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:52:02 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/09 10:42:53 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "libftprintf.h"
#include <unistd.h>

static int	ft_putchar(char	c)
{
	char	ch;

	ch = c;
	write (1, &ch, 1);
}

/*
static int	ft_putstr(char *s)
{
	
}

static int	ft_puthexa(void *p)
{
	
}

static int	ft_putdec(int d)
{
	
}

static int	ft_putint10(int	i)
{
	
}

static int	ft_putundec(unsigned int u)
{
	
}

static int	ft_putlowhexa(unsigned int x)
{
	
}

static int	ft_putuphexa(unsigned int X)
{
	
}

/*
static int	ft_putpercent(char *perc)
{

}
*/

static int	ft_findset(char	c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i] == c)
			return (1);
	return (0);
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

static char ft_symb(const char *arg, int i)
{
	if (arg[i] && (arg[i] != '\%'))
		return ('c');
	if ((arg[i] == '\%') && (ft_findset(arg[i+1], "cspdiuxX\%") == 1))
		return (arg[i+1]);
	return ('c');
}

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
	char	symb;

	i = 	0;
	symb =	'c';
	va_start(elem, arg);
	while (arg[i])
	{
		if ((ft_isvar(arg, i) == 0) && arg[i])
		{
			ft_putchar(arg[i]);
			i++;
		}
		/*
		while(elem)
		{
			type = ft_symb(arg, i);
			ft_print_sth(va_arg(elem, char *), ft_type(symb));
			i = i + ft_incremi(arg, i);
		}
		*/
	}
	va_end(elem);
	return (1);
}


#include <stdio.h>

int	main(void)
{
	ft_printf("Test");
}
