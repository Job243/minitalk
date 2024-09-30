/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:47:39 by jmafueni          #+#    #+#             */
/*   Updated: 2024/01/19 11:25:34 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	else
	{
		i += ft_putstr("0x");
		i += ft_puthex(n);
	}
	return (i);
}

/*int	main(void)
{
	int	i = 15;

	ft_putptr(i);
	return (0);
}*/
