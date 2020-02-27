/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:58:52 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 15:37:07 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx_opengl/mlx.h"
# include "libft/srcs/libft.h"
# include "keycode.h"
# include "libft/srcs/ft_printf/srcs/ft_printf.h"
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define ERROR -1
# define FOV 0.66
# define RAYONS 1440
# define ANGLE 0.04
# define VITESSE 0.13
# define QUARTER 39
# define TITLE CUB3D

/*
**fov = field of view = 60degree
**p_height = player_height = 32
**c_side = cube_side = 64
**p_a = player_angle he's facing to
**c_xmax = number of cube units on x
**c_ymax = number of cube units on y
** map_x_y == nombre de char de la map
**p_x = player_x position + conversion de la map (*64)
**p_y = player_y position + + conversion de la map (*64)
*/

typedef struct	s_struct_projection
{
	double				pos_x;
	double				pos_y;
	double				item_x;
	double				item_y;
	double				dir_x;
	double				dir_y;
	double				olddir_x;
	double				oldplan_x;
	double				plan_x;
	double				plan_y;
	double				camera_x;
	double				raydir_x;
	double				raydir_y;
	double				map_x;
	double				map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_w_dist;
	double				wall_x;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	double				*zbuffer;
	double				*s_distance;
	int					*s_order;
	int					nbitems;
	int					s_screen_x;
	int					sprite_height;
	int					sprite_width;
	int					start_y;
	int					end_y;
	int					start_x;
	int					end_x;
	int					tex_x;
	int					tex_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					draw_start;
	int					draw_end;
	int					line_height;
}				t_pro;

typedef struct	s_verif
{
	char				token_res;
	char				token_cel;
	char				token_flo;
	char				token_map;
	char				token_no;
	char				token_so;
	char				token_we;
	char				token_ea;
	char				token_sprite;
	char				token_player;
}				t_verif;

typedef struct	s_struct_parse
{
	int					x_max;
	int					y_max;
	int					res_max;
	int					fl[3];
	int					cl[3];
	char				*t[4];
	char				*s;
	char				dir;
	char				**map;
	char				*tmp;
	char				*free_tmp;
	unsigned int		count;
	void				*textures[5];
	int					*text_i[5];
	int					w_text;
	int					h_text;
}				t_parse;

typedef struct	s_struct_map
{
	void				*mlx_ptr;
	void				*win_ptr;
	unsigned int		cell_x;
	unsigned int		cell_y;
	int					sl;
	int					bpp;
	int					endi;
	unsigned int		color;
	void				*image;
	int					*image_i;
	int					starter;
	int					text_starter;
}				t_map;

typedef struct	s_struct_key
{
	char				top;
	char				bot;
	char				left;
	char				right;
}				t_key;

typedef struct	s_struct_sprite
{
	double					x;
	double					y;
}				t_sprite;

typedef struct	s_struct_bag
{
	t_pro				*pro;
	t_parse				*da;
	t_map				*map;
	t_key				keys;
	t_verif				*verif;
	t_sprite			*sprite;
}				t_bag;

/*
** 		Initialisation des valeurs des structures
**			|	|	|	|	|	|	|
**			v	v	v	v	v	v	v
*/

int				ft_init_parse(t_bag *b);
int				ft_init_textures(t_bag *b);
int				init_verification(t_bag *b);
int				ft_cat_int(int one, int two, int tree);
int				ft_pos_item(t_bag *b);
int				ft_pos_player(t_bag *b, int o);
int				sort_items(t_bag *b);
int				ft_item_nb(t_bag *b);
void			ft_init_dir(t_bag *b);
void			ft_init_prostruct(t_bag *b);
int				ft_final_init(t_bag *b);

/*
** 			Fonctions de parsing
** 			|	|	|	|	|	|
** 			v	v	v	v	v	v
*/

int				scan_tmp_map(char *str);
int				parse_dotcub(char *dotcub, t_bag *b);
int				ft_map_parse(char *str, t_bag *b);
int				map_verification(t_bag *b);
int				ft_map_to_tab(t_bag *b);
char			*ft_del_char(t_bag *b);
int				global_verification(t_bag *b);
int				point_cub(char *str);
char			*ft_strjoin_free(char const *s1, char const *s2);
int				skip_all_useless_info(char *str);
int				skip_white_space(char *str);
int				catch_flag(char *str, t_bag *b);
void			catch_texture(char *str, t_bag *b);
int				check_max_value(t_bag *b);
int				rgb_max_value(t_bag *b);
int				map_output_error(char verif);

/*
** 			Fonctions graphiques
** 			|	|	|	|	|	|
** 			v	v	v	v	v	v
*/

int				mlx_starter(t_bag *b, char token);
int				minimap_drawing(t_bag *b);
int				ft_color_background(t_bag *b);
void			ft_raycasting(t_bag *b);
int				sprite(t_bag *b);
int				ft_img_bmp(t_bag *b);

/*
** 			 Gestion des inputs
** 			|	|	|	|	|	|
** 			v	v	v	v	v	v
*/

int				move_up(t_bag *b);
int				move_back(t_bag *b);
int				move_right(t_bag *b);
int				move_left(t_bag *b);

/*
** 			  Fin de programme
** 			|	|	|	|	|	|
** 			v	v	v	v	v	v
*/

int				first_free(t_bag *b);
int				second_free(t_bag *b, char verif);
int				destroy_and_free(t_bag *b);

#endif
