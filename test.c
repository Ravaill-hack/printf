/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:10:08 by lmatkows          #+#    #+#             */
/*   Updated: 2024/11/11 11:20:44 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_putchar(int	c)
{
	write (1, &c, 1);
	return (1);
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

int main (void)
{
	ft_putuphexa(15);
}