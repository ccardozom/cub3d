/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:20:37 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/01 13:31:31 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsearch(const char *s1, const char *s2)
{
	int cont;

	cont = 0;
	while (*s1)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			s1++;
		else
		{	
			cont++;
			s2++;
		}
		if (cont == 4)
			return (1);
	}
	return (0);
}