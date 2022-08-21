/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:53:24 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/24 21:30:40 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hex(unsigned long long nb)
{
	long	len;

	len = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_itohex(unsigned long long nbr, const char c)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_itohex(nbr / 16, c);
		i += ft_itohex(nbr % 16, c);
	}
	else
	{
		i++;
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		if (nbr >= 10 && nbr <= 15)
		{
			if (c == 'x')
				ft_putchar(nbr - 10 + 'a');
			if (c == 'X')
				ft_putchar(nbr - 10 + 'A');
		}
	}
	return (len_hex(nbr));
}
