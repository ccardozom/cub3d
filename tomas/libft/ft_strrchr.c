/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:17:38 by ccardozo          #+#    #+#             */
/*   Updated: 2019/11/12 12:01:55 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;

	ps = 0;
	while (*s)
	{
		if (*s == c)
			ps = (char*)s;
		++s;
	}
	if (ps)
		return (ps);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
