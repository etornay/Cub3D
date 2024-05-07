/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:31:04 by etornay-          #+#    #+#             */
/*   Updated: 2024/05/06 13:31:17 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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