/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:22:50 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/22 15:47:48 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len +1));
	if (!str)
		return (NULL);
	while (s[start + i] && i < len)
	{
			str[i] = s[start + i];
			i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;
	int		start;
	int		end;

	start = 100;
	end = 1;
	str1 = "tripouille";
	str2 = ft_substr(str1, start, end);
	printf("%s\n", str2);
}*/
