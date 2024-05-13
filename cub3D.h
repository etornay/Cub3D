/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:04:58 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/13 19:41:39 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define W_NAME		1 //nombre del archivo invalido
# define W_ARG		2 //argumentos invalidos
# define N_OFD		3 //archivo inexistente
# define O_MAP		4 //error abriendo el mapa
# define E_GNL		5 //error de get next line
# define E_IMG		6 //error de  imagen
# define D_CLRS		7 //Texturas o colores duplicados
# define E_LINE		8 //error en line
# define E_CLRS		9 //error en los colores
# define E_WALL		10 //error en los muros
# define E_VYH		11 //error horizontal y vertical
# define E_SPC		12 //error de espacios
# define E_ELMNT	13 //error de elementos
# define E_TEXT		14 //error de texturas
# define E_LIM		15 //error en los limites de la ventana

# define WIDTH		2500
# define HEIGHT		1300
# define SIZE		30
# define VISION		60
# define SPEED		3
# define ROTATION	0.05

typedef struct s_person
{
	int		pers_x;// player x position in pixels
	int		pers_y;// player y position in pixels
	double	ang;// player angle
	float	vis_rd;// field of view (vision) in radians
	int		rot;// rotation flag
	int		lf_rt;// left right flag
	int		up_dw;// up down flag
}	t_person;

typedef struct s_ray
{
	double	ang;// ray angle
	double	distan;// distance to the wall
	int		flag;// flag for the wall
	double	ver_x;
	double	ver_y;
	double	hor_x;
	double	hor_y;
	int		index;
}	t_ray;

typedef struct s_data
{
	char			**map;// the map
	int				p_x;// player x position in the map
	int				p_y;// player y position in the map
	int				w_map;// map width
	int				h_map;// map height
	int				fd;
	int				e_counter; //Contador de los elementos del mapa, c_pos
	char			orientation; // Caracter de la orientacion del personaje
	char			*line;
	int				count_textures;
	int				i;
	int				j;
	int				k;
	char			c;
	char			**f_rgb;
	char			**c_rgb;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	mlx_image_t		*img; // the image
	mlx_t			*mlx;// the mlx pointer
	t_ray			*ray;// the ray structure
	t_person		*person;// the player structure
}	t_data;

//check_map.c
int		check_map(t_data *d);
int		check_elements(t_data *data, char **text);
int		check_only_spaces_fl(t_data *d);
int		check_elements_map(t_data *d);
int		check_colors(t_data *d, char *tc, char *split_text);

//error.c
int		ft_error(int e);
int		ft_error2(int e);

//main.c
int		main(int argc, char **argv);
int		check_map_name(char *name);
void	ft_leaks(void);
int		initialize_game(t_data *data);
void	ft_angle(t_data *data);
void	print_map(void *ks);
void	init_data(t_data *data);

//map.c
int		save_map(t_data *data);
int		fix_map(t_data *d);
int		read_map(t_data *data, char *map_fd);
int		save_textures(t_data *data, char *text);
int		save_textures_2(t_data *data, char **split_text, char **tc);

//camera.c
void	all_movement(t_data *data, double x, double y);
void	cam_rotation(t_data *data, int i);
void	movement(t_data *data, double x, double y);

//utils.c
void	free_array(char ***s);
void	free_data(t_data *d);
void	free_data2(t_data *d);

//keys.c
void	keys(mlx_key_data_t k, void *ks);
void	keys2(mlx_key_data_t k, void *ks);

//raycasting.c
void	raycasting(t_data *data);
float	horizontal_cross(t_data *data, float angle);
float	vertical_cross(t_data *data, float angle);
int		check_cross(float angle, float *cross, float *step_size, int horizon);
int		angle_circle(float angle, char axis);
int		check_wall_hit(t_data *data, float x, float y);
float	check_angle(float angle);

//render.c
void			render_walls(t_data *data, int ray);
void			create_walls(t_data *data, double wall_h, int t_pix, int b_pix);
mlx_texture_t	*get_texture(t_data *data, int flag);
double			get_x_coor(t_data *data, mlx_texture_t *texture);
void			create_pixels(t_data *data, int x, int y, int color);
int				reverse_bytes(int i);
int				get_colors(int r, int g, int b, int a);

#endif