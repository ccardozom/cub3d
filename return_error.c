/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:01:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/11 11:24:58 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	error_map(int x)
{
	if (x == 3)
		ft_putstr_fd("Error\n ¡¡Te he dicho que esto esta" 
		" pro-hi-bi-do!! Existe lineas vacias al final mapa\n", 1);
	if (x == 12)
		ft_putstr_fd("Error\n ¡¡Algo falla...!!" 
		" El mapa no es valido. Falta Jugador\n", 1);
	if (x == 14)
		ft_putstr_fd("Error\n ¡¡Algo falla...!!" 
		" El mapa no es valido. No esta rodeado de muros\n", 1);
}
void	return_error(int x)
{
	error_map(x);
	if (x == 1)
		ft_putstr_fd("Error\n ¡¡Estamos jodidos!! No existe argumento\n", 1);
	if (x == 2)
		ft_putstr_fd("Error\n ¡¡jajaja sin algo que leer no" 
		" hacemos nada!! No se puede leer el archivo .cub\n", 1);
	if (x == 4)
		ft_putstr_fd("Error\n No se a podido reservar memoria\n", 1);
	if (x == 5)
		ft_putstr_fd("Error\n ¡¡Asi no se puede!! No se" 
		" encuentra el path de la textura norte\n", 1);
	if (x == 6)
		ft_putstr_fd("Error\n ¡¡Estamos jodidos!! No se encuentra" 
		" el path de la textura sur\n", 1);
	if (x == 7)
		ft_putstr_fd("Error\n ¿ Y ahora que....?¡Reparalo! No" 
		" se encuentra el path de la textura oeste\n", 1);
	if (x == 8)
		ft_putstr_fd("Error\n ¡¡Corre y repara esto!! No se" 
		" encuentra el path de la textura este\n", 1);
	if (x == 9)
		ft_putstr_fd("Error\n ¡¡Esto esta mas vacio que 42 en la pandemia!!" 
		" No se encuentra el path de la textura del sprite\n", 1);
	if (x == 10)
		ft_putstr_fd("Error\n ¡¡Crees que me la vas a colar!!" 
		" El argumento correcto es --save\n", 1);
	if (x == 11)
		ft_putstr_fd("Error\n ¡¡Sabes que es lo que quiero....?!!" 
		" Faltan datos para arrancar el juego ¿[R,NO,SO,EA,WE,F,S,C]?\n", 1);
	if (x == 13)
		ft_putstr_fd("Error\n ¡¡Los datos de la resolucion no son correctos!!" 
		" verifica eso ya...\n", 1);
	//system("leaks cub3D");
	exit(0);
}
