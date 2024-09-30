/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:54:36 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/12 21:05:54 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	int		i;
	size_t	n;

	char	str[] = "bonjour";
	i = 'j';
	n = 3;
	ft_memset(str, i, n);
	printf("resultat %s\n", ((char *)str));
	return (0);
}*/
