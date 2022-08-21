/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:47:04 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/24 21:30:39 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_nb(unsigned int nb)
{
	long	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	i = len_nb(n);
	if (n == 0)
		return (ft_putchar('0'));
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = 0;
	while (n > 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	i = ft_putstr(str);
	free (str);
	return (i);
}
