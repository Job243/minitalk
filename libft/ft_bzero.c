/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:55:48 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/12 17:54:20 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*m;
	unsigned char	c;
	size_t			i;

	m = (unsigned char *)s;
	c = '\0';
	i = 0;
	while (i < n)
	{
		m[i] = c;
		i++;
	}
}

/*int	main(void)
{
	char	buffer[10];

	ft_bzero(buffer, sizeof(buffer));
	for (int i = 0; i < sizeof(buffer); ++i) 
	{
		printf("%c", buffer[i]);
	}
	return (0);
}*/
