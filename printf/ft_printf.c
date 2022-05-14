/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:44:54 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/24 21:30:38 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_cdt(char *str, int i, va_list args)
{
	int	print_count;

	print_count = 0;
	if (str[i] == 'c')
		print_count += ft_putchar((int) va_arg(args, int));
	else if (str[i] == 's')
		print_count += ft_putstr((char *) va_arg(args, char *));
	else if (str[i] == 'p')
	{
		ft_putstr("0x");
		print_count += ft_itohex(va_arg(args, unsigned long long), 'x') + 2;
	}
	else if (str[i] == 'd' || str[i] == 'i')
		print_count += ft_mitoa(va_arg(args, int));
	else if (str[i] == 'u')
		print_count += ft_uitoa(va_arg(args, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		print_count += ft_itohex(va_arg(args, unsigned int), str[i]);
	else if (str[i] == '%')
		print_count += ft_pourcent();
	else
		return (-1);
	return (print_count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i++])
			count += ft_print_cdt((char *)str, i, args);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (count);
}
