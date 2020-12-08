/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:15:22 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/20 11:51:10 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*out;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(out = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(out, s1, ft_strlen(s1) + 1);
	ft_strlcat(out, s2, len);
	return (out);
}
