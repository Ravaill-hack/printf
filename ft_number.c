/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:25 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/12 09:31:11 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(int d)
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

int	ft_putundec(unsigned int u)
{
	int	i;

	i = 0;
	if (u >= 10)
		i += ft_putundec(u / 10);
	ft_putchar(u % 10 + 48);
	i ++;
	return (i);
}

int	ft_putlowhexa(unsigned int x)
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

int	ft_putuphexa(unsigned int X)
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

int	ft_putadrhexa(void *p)
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
