/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:31:04 by etornay-          #+#    #+#             */
/*   Updated: 2024/05/08 17:39:30 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Comprueba si hay un cruce o intersección en una dirección específica

int	check_cross(float angle, float *cross, float *step_size, int horizon)
{
	if (horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*cross += SIZE;
			return (-1);
		}
		*step_size *= -1;
	}
	else
	{
		if (angle > (M_PI / 2) && angle < ((3 * M_PI) / 2))
		{
			*cross += SIZE;
			return (-1);
		}
		*step_size *= -1;
	}
	return (0);
}

//Comprueba que el ángulo esté de 0º a 360º

void	check_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

//Comprueba que el archivo del mapa sea .cub

int	check_map_name(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i] != 'b' || name[i - 1] != 'u'
		|| name[i - 2] != 'c' || name[i - 3] != '.')
		return (false);
	return (true);
}
