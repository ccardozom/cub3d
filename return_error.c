/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:01:27 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:22:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	error_map(int x)
{
	if (x == 3)
		ft_putstr_fd("Error\n ¡¡Te he dicho que esto esta"
		" pro-hi-bi-do!! Existe lineas vacias al final mapa\n", 1);
	else if (x == 12)
		ft_putstr_fd("Error\n ¡¡Algo falla...!!"
		" El mapa no es valido. Falta o sobra un Jugador\n", 1);
	else if (x == 14)
		ft_putstr_fd("Error\n ¡¡Algo falla...!!"
		" El mapa no es valido. No esta rodeado de muros\n", 1);
	else if (x == 15)
		ft_putstr_fd("Error\n ¡¡Si sabes que eso no esta permitido...!!"
		" El mapa contiene caracteres no validos\n", 1);
}

void	error_textura(int x)
{
	if (x == 5)
		ft_putstr_fd("Error\n ¡¡Asi no se puede!! No se"
		" encuentra el path de la textura norte\n", 1);
	else if (x == 6)
		ft_putstr_fd("Error\n ¡¡Estamos jodidos!! No se encuentra"
		" el path de la textura sur\n", 1);
	else if (x == 7)
		ft_putstr_fd("Error\n ¿ Y ahora que....?¡Reparalo! No"
		" se encuentra el path de la textura oeste\n", 1);
	else if (x == 8)
		ft_putstr_fd("Error\n ¡¡Corre y repara esto!! No se"
		" encuentra el path de la textura este\n", 1);
	else if (x == 9)
		ft_putstr_fd("Error\n ¡¡Esto esta mas vacio que 42 en la pandemia!!"
		" No se encuentra el path de la textura del sprite\n", 1);
}

void	return_error(int x)
{
	error_map(x);
	error_textura(x);
	if (x == 1)
		ft_putstr_fd("Error\n ¡¡Estamos jodidos!! No existe argumento\n", 1);
	else if (x == 2)
		ft_putstr_fd("Error\n ¡¡jajaja sin algo que leer no"
		" hacemos nada!! No se puede leer el archivo .cub o .bmp\n", 1);
	else if (x == 4)
		ft_putstr_fd("Error\n No se a podido reservar memoria\n", 1);
	else if (x == 10)
		ft_putstr_fd("Error\n ¡¡Crees que me la vas a colar!!"
		" El argumento correcto es --save\n", 1);
	else if (x == 11)
		ft_putstr_fd("Error\n ¡¡Sabes que es lo que quiero....?!!"
		" Faltan o sobran datos para arrancar el"
		"juego ¿[R,NO,SO,EA,WE,F,S,C]?\n", 1);
	else if (x == 13)
		ft_putstr_fd("Error\n ¡¡Los datos de la resolucion no son correctos!!"
		" Verifica eso ya...\n", 1);
	else if (x == 16)
		ft_putstr_fd("Error\n Datos incorrectos en suelo o el cielo :-(", 1);
	exit(0);
}
