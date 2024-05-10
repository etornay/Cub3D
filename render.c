/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:46:33 by etornay-          #+#    #+#             */
/*   Updated: 2024/05/10 16:37:48 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_walls(t_data *data, int ray)
{
	double	wall_height;
	double	top_pixel;
	double	bottom_pixel;

	data->ray->distance *= cos(data->ray->ray_angle - data->person->angle);
	wall_height = ((SIZE / data->ray->distance)
			* ((HEIGHT / 2) / tan(data->person->vis_rd / 2)));
	top_pixel = ((HEIGHT / 2) - (wall_height / 2));
	bottom_pixel = ((HEIGHT / 2) + (wall_height / 2));
	if (top_pixel < 0)
		top_pixel = 0;
	if (bottom_pixel > HEIGHT)
		bottom_pixel = HEIGHT;
}
