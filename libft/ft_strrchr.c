/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:48:26 by jmafueni          #+#    #+#             */
/*   Updated: 2023/12/05 18:51:31 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
/*int	main(void)
{
	const char	*str = "Bonjour le mondel";
	char		c = 'l';
	char		*result = strrchr(str, c);
	char		*result2 = ft_strrchr(str, c);

	if (result != NULL)
	{
		printf("'%c' a été trouvé à la position : %ld\n", c, result - str);
		printf("'%c' a ete trouve a la position : %ld\n", c, result2 - str);
	}
	else
	{
		printf("Le caractère '%c' n'a pas été trouvé dans la chaîne.\n", c);
	}
	return (0);
}*/
