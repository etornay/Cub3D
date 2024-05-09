/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:56:35 by etornay-          #+#    #+#             */
/*   Updated: 2024/05/09 17:25:45 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Comprueba el cuadrante del ángulo

int	angle_circle(float angle, char axis)
{
	if (axis == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (axis == 'y')
	{
		if (angle > (M_PI / 2) && angle < ((3 * M_PI) / 2))
			return (1);
	}
	return (0);
}

//Comprueba si el cruce o intersección es en una vertiente vertical del cubo

float	get_vertical_cross(t_data *data, float angle)
{
	float	ver_x;
	float	ver_y;
	float	x_limit;
	float	y_limit;
	int		pixel;

	x_limit = SIZE;
	y_limit = SIZE / tan(angle);
	ver_x = floor(data->person->pers_x / SIZE) * SIZE;
	pixel = check_cross(angle, &ver_x, &x_limit, 0);
	ver_y = data->person->pers_y + (ver_x - data->person->pers_x)
		* tan(data->ray->ray_angle);
	if ((angle_circle(angle, 'x') && y_limit < 0)
		|| (!angle_circle(angle, 'x') && y_limit > 0))
		y_limit *= -1;
	(INTRODUCIR WALL HIT)
}

//Comprueba si el cruce o intersección es en una vertiente horizontal del cubo

float	get_horizontal_cross(t_data *data, float angle)
{
	float	hor_x;
	float	hor_y;
	float	x_limit;
	float	y_limit;
	int		pixel;

	x_limit = SIZE / tan(angle);
	y_limit = SIZE;
	hor_y = floor(data->person->pers_y / SIZE) * SIZE;
	pixel = check_cross(angle, &hor_y, &y_limit, 0);
}

void	raycasting(t_data *data)
{
	double	hor_cross;
	double	ver_cross;
	int		ray;

	ray = 0;
	data->ray->ray_angle = data->person->angle - (data->person->vis_rd / 2);
	while (ray < WIDTH)
	{
		data->ray->flag = 0;
		hor_cross = get_horizontal_cross();
		ver_cross = get_vertical_cross();
	}
}
