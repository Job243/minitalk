/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:28:49 by jmafueni          #+#    #+#             */
/*   Updated: 2023/12/04 17:25:01 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{	
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		size;

	i = 0;
	while (ft_charset(s1[i], set))
			i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_charset(s1[i], set))
		i--;
	size = (i + 1) - start;
	str = ft_substr(s1, start, size);
	return (str);
}

/*int	main(void)
{
	char	str[] = " !.-job-.! ";
	char	set[] = " !.-";
	char	*str2;

	str2 = ft_strtrim(str, set);
	printf("%s\n", str2);
}*/
