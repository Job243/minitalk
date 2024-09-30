/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:35:19 by jmafueni          #+#    #+#             */
/*   Updated: 2023/12/06 17:21:30 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		while (big[i + j] && little[j] == big[i + j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return (((char *)big) + i);
		i++;
		j = 0;
	}
	return (NULL);
}

/*int	main(void)
{
	char		haystack[30] = "aaabcabcd";
	size_t		n = strlen(haystack);
	char		*result = ft_strnstr(haystack, "cd", 8);

	if (result != NULL)
	{
		printf("'%s' a été trouvée à la position : %ld\n", "cd", result - haystack);
	}
	else
	{
		printf("'%s' n'a pas été trouvée dans la chaîne.\n", "cd");
	}
	return (0);
}*/
