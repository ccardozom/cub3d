/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 09:21:53 by ccardozo          #+#    #+#             */
/*   Updated: 2019/11/21 17:37:56 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *ls, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*aux;

	if (!ls && !del)
		return (NULL);
	aux = ls;
	if (!(new = ft_lstnew(f(aux->content))))
		return (NULL);
	aux = aux->next;
	while (aux)
	{
		if (!(tmp = ft_lstnew(f(aux->content))))
			return (NULL);
		ft_lstadd_back(&new, tmp);
		aux = aux->next;
	}
	return (new);
}
