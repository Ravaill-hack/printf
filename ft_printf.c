/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:52:02 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/11 16:20:11 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_findset(char c, char *set)
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

char	ft_symb(const char *arg, int i)
{
	if (arg[i] && (arg[i] != '\%'))
		return ('c');
	if ((arg[i] == '\%') && (ft_findset(arg[i + 1], "cspdiuxX\%") == 1))
		return (arg[i + 1]);
	return ('c');
}

int	ft_isvar(const char *s, int i)
{
	if (s[i] == '\%')
	{
		if (s[i + 1] && (ft_findset(s[i + 1], "cspdiuxX\%") == 1))
			return (1);
	}
	return (0);
}

int	ft_print_sth(va_list elem, char symb)
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
			ret += ft_print_sth(elem, ft_symb(arg, i));
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
	printf("Test single character c\n\n");
	printf(" %d\n",ft_printf("ft_printf  %c", 'a'));
	printf(" %d\n",printf("print_f    %c", 'a'));
	printf("\n\n");
	printf("Test string s\n\n");
	printf(" %d\n",ft_printf("ft_printf  %s", "Test"));
	printf(" %d\n",printf("print_f    %s", "Test"));
	printf("\n\n");
	printf("Test adresse p\n\n");
	printf(" %d\n",ft_printf("ft_printf  %p", Test));
	printf(" %d\n",printf("print_f    %p", Test));
	printf("\n\n");
	printf("Test decimal d\n\n");
	printf(" %d\n",ft_printf("ft_printf  %d", -1458));
	printf(" %d\n",printf("print_f    %d", -1458));
	printf("\n\n");
	printf("Test integer i\n\n");
	printf(" %d\n",ft_printf("ft_printf  %i", -1458));
	printf(" %d\n",printf("print_f    %i", -1458));
	printf("\n\n");
	printf("Test unsigned decimal u\n\n");
	printf(" %d\n",ft_printf("ft_printf  %u", 1458));
	printf(" %d\n",printf("print_f    %u", 1458));
	printf("\n\n");
	printf("Test hexadecimal lowercase x\n\n");
	printf(" %d\n",ft_printf("ft_printf  %x", 44));
	printf(" %d\n",printf("print_f    %x", 44));
	printf("\n\n");
	printf("Test hexadecimal uppercase X\n\n");
	printf(" %d\n",ft_printf("ft_printf  %X", 44));
	printf(" %d\n",printf("print_f    %X", 44));
	printf("\n\n");
	printf("Test percent %%\n\n");
	printf(" %d\n",ft_printf("ft_printf  %%"));
	printf(" %d\n",printf("print_f    %%"));
	printf("\n\n");
	printf("Tests divers \n\n");
	printf(" %d\n",ft_printf("ft_printf  Te%%st%s%p%p\n", "Je suis", NULL, Test));
	printf(" %d\n",printf("print_f    Te%%st%s%p%p\n", "Je suis", NULL, Test));
	printf("\n\n");
}
*/