/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:48:05 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/26 17:17:31 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_parms(int i, char str, va_list args)
{
	if (str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		i += ft_putunsigned(va_arg(args, unsigned int));
	else if (str == 'p')
		i += ft_putptr(va_arg(args, unsigned long long));
	else if (str == 'x')
		i += ft_puthex(va_arg(args, unsigned int));
	else if (str == 'X')
		i += ft_puthex2(va_arg(args, unsigned long));
	else if (str == '%')
		i += ft_putchar(str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int			j;
	int			i;
	va_list		args;

	i = 0;
	j = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[j])
	{
		if (str[j] == '%')
		{
			j++;
			i = ft_parms(i, str[j], args);
		}
		else
		{
			i += write(1, &str[j], 1);
		}
		j++;
	}
	va_end(args);
	return (i);
}
