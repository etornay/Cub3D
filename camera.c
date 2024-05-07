/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:20:45 by etornay-          #+#    #+#             */
/*   Updated: 2024/05/06 18:45:24 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Esta función se encarga de la visión del jugador en movimiento de un punto a otro
siempre que no se tope con un obstáculo */

void	movement(t_data *data, double x, double y)
{
	int	pos_x;
	int	pos_y;
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = roundf(data->person->pers_x + x);
	new_pos_y = roundf(data->person->pers_y + y);
	pos_x = (new_pos_x / SIZE);
	pos_y = (new_pos_y / SIZE);
	if (data->map[pos_y][pos_x] != '1'
		&& data->map[pos_y][data->person->pers_x / SIZE] != '1'
		&& data->map[data->person->pers_y / SIZE][pos_x] != '1')
	{
		data->person->pers_x = new_pos_x;
		data->person->pers_y = new_pos_y;
	}
}

/* Esta función se encarga de la visión de rotación del jugador al pulsar DERECHA o IZQUIERDA */

void	cam_rotation(t_data *data, int i)
{
	if (i == 1)
	{
		data->person->angle += ROTATION;
		if (data->person->angle > (2 * M_PI))
			data->person->angle -= (2 * M_PI);
	}
	else
	{
		data->person->angle -= ROTATION;
		if (data->person->angle < 0)
			data->person->angle += (2 * M_PI);
	}
}

/* Esta función se encarga de la visión de rotación del jugador y movimiento */

void	rotation(t_data *data, double x, double y)
{
	if (data->person->rot == 1)
		cam_rotation(data, 1);
	if (data->person->rot == -1)
		cam_rotation(data, 0);
	if (data->person->up_dw == 1)
	{
		x = cos(data->person->angle) * SPEED;
		y = sin(data->person->angle) * SPEED;
	}
	if (data->person->up_dw == -1)
	{
		x = -cos(data->person->angle) * SPEED;
		y = -sin(data->person->angle) * SPEED;
	}
	if (data->person->lf_rt == 1)
	{
		x = cos(data->person->angle) * SPEED;
		y = -sin(data->person->angle) * SPEED;
	}
	if (data->person->lf_rt == -1)
	{
		x = -cos(data->person->angle) * SPEED;
		y = sin(data->person->angle) * SPEED;
	}
	movement(data, 0, 0);
}