/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:13:46 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/21 17:06:17 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == 0)
		return ((char *)(s + i));
	return (NULL);
}
/*int	main(void)
{
	const char	*str = "Bonjour le monde";
	char		c = 'l';
	char		*result = ft_strchr(str, c);
	char		*result2 = strchr(str, c);

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
