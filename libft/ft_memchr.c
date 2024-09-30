/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:34:47 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/21 17:08:24 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	*str = "Hello, World!";
	char		c = 'W';
	size_t		n = strlen(str);
	void		*result = ft_memchr(str, c, n);

	if (result != NULL)
	{
		printf("'%c' a été trouvé à la position : %ld\n", c, (char *)result - str);
	}
	else
	{
		printf("L'octet '%c' n'a pas été trouvé dans la zone de mémoire.\n", c);
	}
	return (0);
}*/
