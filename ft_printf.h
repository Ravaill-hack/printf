/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:14:27 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/11/15 20:30:05 by Lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXALOW "0123456789abcdef"
# define HEXAUP "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putdec(int d);
int		ft_putundec(unsigned int u);
int		ft_putlowhexa(unsigned int x);
int		ft_putuphexa(unsigned int X);
int		ft_putadr(void *p);
int		ft_adrhexa(unsigned long X);
int		ft_findset(char c, char *set);
char	ft_symb(const char *arg, int i);
int		ft_isvar(const char *s, int i);
int		ft_print_sth(va_list elem, char symb);
int		ft_printf(const char *arg, ...);

#endif
