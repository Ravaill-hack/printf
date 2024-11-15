/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:24:25 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/15 17:22:14 by lmatkows         ###   ########.fr       */
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

int	ft_putlowhexa(unsigned long x)
{
	int			i;

	i = 0;
	if (x >= 16)
	{
		i += ft_putlowhexa(x / 16);
	}
	ft_putchar(HEXALOW[x % 16]);
	i ++;
	return (i);
}

int	ft_putuphexa(unsigned long X)
{
	int			i;

	i = 0;
	if (X >= 16)
	{
		i += ft_putuphexa(X / 16);
	}
	ft_putchar(HEXAUP[X % 16]);
	i ++;
	return (i);
}

int	ft_putadrhexa(void *p)
{
	int				i;
	unsigned long	ptr;

	i = 0;
	ptr = (unsigned long) p;
	if (!ptr)
		return (ft_putstr("(nil)"));
	i = ft_putstr("0x");
	i = i + ft_putlowhexa(ptr);
	return (i);
}
