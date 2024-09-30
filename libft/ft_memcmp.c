/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:11:57 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/21 16:31:20 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char	*str1 = "Hello";
	const char	*str2 = "World";
	size_t		n = 5;
	int			result = ft_memcmp(str1, str2, n);

	if (result == 0)
	{
		printf("Les cinq premiers octets de str1 et str2 sont identiques.\n");
	}
	else if (result < 0)
	{
		printf("Les cinq premiers octets de str1 sont inférieurs à str2.\n");
	}
	else
	{
		printf("Les cinq premiers octets de str1 sont supérieurs à str2.\n");
	}
	return (0);
}*/
