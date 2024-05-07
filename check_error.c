/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:41:45 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/06 16:00:03 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_error(int e)
{
	if (e == W_NAME)
		printf("Error\nInvalid map format\n");
	else if (e == W_ARG)
		printf("Error\nInvalid arguments\n");
	else if (e == N_OFD)
		printf("Error\nInvalid file\n");
	else if (e == O_MAP)
		printf("Error\nFailed opening map\n");
	else if (e == E_GNL)
		printf("Error\nget_next_line failed\n");
	else if (e == E_IMG)
		printf("Error\nImage error\n");
	else if (e == D_CLRS)
		printf("Error\nDuplicate colors or textures\n");
	else if (e == E_LINE)
		printf("Error\nFailed obtaining line\n");
	else if (e == E_CLRS)
		printf("Error\nError in colors\n");
	else if (e == E_WALL)
		printf("Error\nMap not closed by walls\n");
	else if (e == E_VYH)
		printf("Error\nMap H/V incorrect element\n");
	else if (e == E_SPC)
		printf("Error\nOnly spaces in first line\n");
	return (ft_error2(e));
}

int	ft_error2(int e)
{
	if (e == E_ELMNT)
		printf("Error\nIncorrect map elements\n");
	else if (e == E_TEXT)
		printf("Error\nIncorrect textures or colors\n");
	else if (e == E_LIM)
		printf("Error\nHeight, width or fov out of limits\n");
	return (1);
}
