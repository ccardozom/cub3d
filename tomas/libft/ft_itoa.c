/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:48:45 by ccardozo          #+#    #+#             */
/*   Updated: 2019/11/21 10:57:07 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char		*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	if (nbr < 0)
		nb = (unsigned int)(nbr * -1);
	else
		nb = (unsigned int)nbr;
	size = (unsigned int)count_len(nb);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
