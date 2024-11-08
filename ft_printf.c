/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:52:02 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/08 12:03:13 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static int	ft_putchar(int	c)
{
	
}

static int	ft_putstr(char *s)
{
	
}

static int	ft_puthexa(int p)
{
	
}

static int	ft_putdec(float d)
{
	
}

static int	ft_putint10(int	i)
{
	
}

static int	ft_putundec(float u)
{
	
}

static int	ft_putlowhexa(int x)
{
	
}

static int	ft_putuphexa(int X)
{
	
}

static int	ft_putpercent(char *perc)
{

}

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

int	ft_printf(const char *arg, ...)
{
	va_list	elem;
	int		i;
	char	symb;

	i = 	0;
	symb =	'c';
	va_start(elem, arg);
	while(elem)
	{
		type = ft_symb(arg, i);
		ft_print_sth(va_arg(elem, char *), ft_type(symb));
		i = i + ft_incremi(arg, i);
	}
	va_end(elem);
}
