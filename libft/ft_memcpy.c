/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:15 by jmafueni          #+#    #+#             */
/*   Updated: 2023/12/05 18:55:52 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int main() {
//     // Source data
//     const char source[] = "Hello, World!";

//     // Déterminer la taille de la source
//     size_t source_size = ft_strlen(source) + 1;
//     char destination[source_size];

//     // Utiliser memcpy pour copier les données de la source à la destination
//     ft_memcpy(destination, source, source_size);

//     // Afficher la destination pour vérifier la copie
//     printf("Source: %s\n", source);
//     printf("Destination: %s\n", destination);

//     return 0;
// }
