/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:21:17 by etornay-          #+#    #+#             */
/*   Updated: 2024/05/06 16:01:15 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Esta funcion lee lineas del fd, las junta en una string y luego la divide en
lineas individuales para almacenarlas en data->map. */

int	save_map(t_data *data)
{
	char	*map_join;

	map_join = NULL;
	while (data->line)
	{
		map_join = ft_strjoin(map_join, data->line);
		if (!map_join)
			return (1);
		if (data->line[0] == '\n')
			return (free(map_join), free(data->line), ft_error(E_LINE));
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	close(data->fd);
	if (map_join)
	{
		data->map = ft_split(map_join, '\n');
		if (!data->map)
			return (free(map_join), 1);
		if (check_map(data))
			return (free(map_join), 1);
	}
	return (free(map_join), 0);
}

/* Esta funcion se asegura de que todas las lineas del mapa tengan la
misma longitud, rellenando las lineas mas cortas con espacios en blanco */

int	fix_map(t_data *dta)
{
	size_t	max_l;
	char	*new;

	dta->i = -1;
	max_l = 0;
	while (dta->map[++dta->i])
		if (max_l < ft_strlen(dta->map[dta->i]))
			max_l = ft_strlen(dta->map[dta->i]);
	dta->i = -1;
	while (dta->map[++dta->i])
	{
		dta->j = ft_strlen(dta->map[dta->i]);
		new = ft_calloc(1, max_l + 1);
		if (!new)
			return (1);
		ft_strlcpy(new, dta->map[dta->i], ft_strlen(dta->map[dta->i]) + 1);
		while ((size_t)dta->j < max_l)
			new[dta->j++] = ' ';
		new[dta->j] = '\0';
		free(dta->map[dta->i]);
		dta->map[dta->i] = new;
		dta->h_map = dta->i;
		dta->w_map = max_l - 1;
	}
	return (0);
}
