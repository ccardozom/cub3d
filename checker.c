/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:00:59 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/01 14:48:43 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		check_data(int *checker)
{
	int i;

	i = 0;
	while (checker[i])
	{
		if (checker[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int		checker(int *checker)
{
	int check;
	
	check = 0;
	check = check_data(checker);
	return (check);
}