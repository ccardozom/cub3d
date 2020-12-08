/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:58:38 by ccardozo          #+#    #+#             */
/*   Updated: 2019/11/19 17:34:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*n == '\0' || n == NULL)
		return ((char*)h);
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (n[j] == h[i + j] && i + j < len)
		{
			if (n[j + 1] == '\0')
			{
				return ((char*)h + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
