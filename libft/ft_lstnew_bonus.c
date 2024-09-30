/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:46:06 by jmafueni          #+#    #+#             */
/*   Updated: 2023/12/01 16:08:05 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nv;

	nv = (t_list *)malloc(sizeof(t_list));
	if (!nv)
		return (NULL);
	nv->content = content;
	nv->next = NULL;
	return (nv);
}
