/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:03:57 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/12 18:12:54 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*int	main(void)
{
	char	uppercase = 'A';
	char	lowercase = tolower(uppercase);

	printf("Caractère en majuscule : %c\n", uppercase);
	printf("Caractère converti en minuscule : %c\n", lowercase);
	return (0);
}*/
