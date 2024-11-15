/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:14:27 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/11/15 12:15:13 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putdec(int d);
int		ft_putundec(unsigned int u);
int		ft_putlowhexa(unsigned long x);
int		ft_putuphexa(unsigned long X);
int		ft_putadrhexa(void *p);
int		ft_findset(char c, char *set);
char	ft_symb(const char *arg, int i);
int		ft_isvar(const char *s, int i);
int		ft_print_sth(va_list elem, char symb);
int		ft_printf(const char *arg, ...);
void	ft_cpy(char *dest, char *src);

#endif
