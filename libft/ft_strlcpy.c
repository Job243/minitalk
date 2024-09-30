/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:49:17 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/22 14:13:37 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size -1)
	{
		((unsigned char *)des)[i] = ((unsigned char *)src)[i];
		i++;
	}
	((unsigned char *)des)[i] = '\0';
	return (ft_strlen(src));
}

/*int	main(void)
{
	char		destination[20];
	const char	*source = "Hello, World!";
	size_t		length;

	length = ft_strlcpy(destination, source, sizeof(destination));
	if (length >= sizeof(destination))
	{
		fprintf(stderr, "String truncated! Destination buffer is too small.\n");
		return (1);
	}
	printf("Source: %s\n", source);
	printf("Destination: %s\n", destination);
	printf("Length of the copied string: %zu\n", length);
	return (0);
}*/
