/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:21 by jmafueni          #+#    #+#             */
/*   Updated: 2024/10/01 16:52:23 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
	{
		ft_putchar(n + 48);
		i++;
	}
	else
	{
		i += ft_putunsigned(n / 10);
		i += ft_putunsigned(n % 10);
	}
	return (i);
}
