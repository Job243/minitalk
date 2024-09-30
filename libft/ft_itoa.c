/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:40:43 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/24 14:12:15 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(int n)
{
	int			i;
	long int	num;

	i = 1;
	num = n;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			len;
	int			i;
	char		*str;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	num = n;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	i = 1;
	str[len] = '\0';
	while (num >= 10)
	{
		str[len - i] = num % 10 + 48;
		num /= 10;
		i++;
	}
	str[len - i] = num % 10 + 48;
	return (str);
}

/*int	main(void)
{
	int		i;
	char	*str;

	i = 42;
	str = ft_itoa(i);
	printf("%s", str);
}*/
