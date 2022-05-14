/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:44:57 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/24 21:30:41 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_mitoa(int nb);
int	ft_pourcent(void);
int	ft_uitoa(int unsigned nb);
int	ft_itohex(unsigned long long nbr, const char c);
int	ft_callhex(unsigned int nbr, const char c);

#endif
