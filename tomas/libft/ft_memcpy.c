/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:23:40 by ccardozo          #+#    #+#             */
/*   Updated: 2019/11/11 19:27:33 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	pdst = (void*)dst;
	psrc = (void*)src;
	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
