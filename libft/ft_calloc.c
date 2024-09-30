/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:49:15 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/26 21:16:18 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	ptr = ((void *) malloc(nmemb * size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*int	main(void)
{
	char	*tableau = (char*)ft_calloc(8, sizeof(char));

	if (tableau == NULL)
	{
		fprintf(stderr, "Échec de l'allocation mémoire\n");
		return (1);
	}
	for (size_t i = 0; i < 8; i++)
	{
		tableau[i] = 'A';
	}
	for (size_t i = 0; i < 8; i++)
	{
		printf("%c ", tableau[i]);
	}
	free(tableau);
	return (0);
}*/
