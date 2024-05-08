/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:56:35 by etornay-          #+#    #+#             */
/*   Updated: 2024/05/08 17:52:44 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
}

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
