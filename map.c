/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:18:09 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/06 16:12:10 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Esta funcion analiza y carga texturas */

int	save_textures_2(t_data *data, char **split_text, char **t_c)
{
	data->j = 2;
	while (split_text[data->i][data->j] == ' '
	|| (split_text[data->i][data->j] >= 9
		&& split_text[data->i][data->j] <= 13))
		data->j++;
	*t_c = ft_strdup(split_text[data->i] + data->j);
	if (!*t_c)
		return (1);
	if (!ft_strncmp(split_text[data->i], "NO ", 3))
		data->no = mlx_load_png(*t_c);
	else if (!ft_strncmp(split_text[data->i], "SO ", 3))
		data->so = mlx_load_png(*t_c);
	else if (!ft_strncmp(split_text[data->i], "WE ", 3))
		data->we = mlx_load_png(*t_c);
	else if (!ft_strncmp(split_text[data->i], "EA ", 3))
		data->ea = mlx_load_png(*t_c);
	return (0);
}

/* Esta funcion procesa un bloque de texto que contiene definiciones de texturas
y colores, luego asigna esas texturas y colores dentro de t_data */

int	save_textures(t_data *data, char *text)
{
	char	**split_text;
	char	*t_c;

	t_c = NULL;
	split_text = ft_split(text, '\n');
	data->i = -1;
	while (split_text && split_text[++data->i])
	{
		data->j = data->i;
		while (split_text[++data->j])
			if (!ft_strncmp(split_text[data->i], split_text[data->j], 2))
				return (free_array(&split_text), free(text),
					free(data->line), ft_error(D_CLRS));
		if (split_text[data->i][data->j])
		{
			if (save_textures_2(data, split_text, &t_c))
				return (free_array(&split_text), free(t_c), free(text), 1);
			if ((!ft_strncmp(split_text[data->i], "F ", 2)
					|| !ft_strncmp(split_text[data->i], "C ", 2))
				&& check_colors(data, t_c, split_text[data->i]))
				return (free_array(&split_text), free(t_c), free(text), 1);
			free(t_c);
		}
	}
	return (free_array(&split_text), free(text), 0);
}

int	read_map(t_data *data, char *map_fd)
{
	char	*texture;

	texture = NULL;
	data->count_textures = 0;
	data->fd = open(map_fd, O_RDONLY);
	if (data->fd == -1)
		ft_error(O_MAP);
	data->line = get_next_line(data->fd);
	if (!data->line)
		return (ft_error(E_GNL));
	if (check_elements(data, &texture))
		return (1);
	if (save_textures(data, texture))
		return (1);
	if (!data->no || !data->so || !data->we || !data->ea)
		return (free(data->line), ft_error(E_TEXT));
	return (0);
}
