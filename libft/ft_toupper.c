/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:41:52 by jmafueni          #+#    #+#             */
/*   Updated: 2023/11/12 18:03:20 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*int	main(void)
{
	char	lowercase = 'q';
	char	uppercase = ft_toupper(lowercase);

	printf("Caractère en minuscule : %c\n", lowercase);
	printf("Caractère converti en majuscule : %c\n", uppercase);
	return (0);
}*/
