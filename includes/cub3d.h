/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:12 by anshimiy          #+#    #+#             */
/*   Updated: 2022/11/22 13:34:32 by anshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ****** INCLUDES ****** */

# include 	"my_lib/mylib.h"
# include	<stdarg.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<math.h>
# include	<complex.h>
# include	<fcntl.h>
# include	"./mlx/include/MLX42/MLX42.h"
# include	"cub3d_struct.h"

typedef enum e_game_status {
    RUNNING,
    OVER,
} t_game_status;

/* ****** STRUCTS ****** */



typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		init;
} t_mlx;

typedef struct s_map
{
	t_img	back;
	int		height;
	int		width;
	char	*tiles;
	int		*tiles_coll;
	int		size;
	int		floor_color;
	int		ceiling_color;
} t_map;

typedef struct s_player
{
	t_pos	pos;
	double	rot;
	double	vel_r;
	double	vel_l;
	double	vel_u;
	double	vel_d;
	double	turn_l;
	double	turn_r;
} t_player;

typedef struct s_game
{
	t_map			map;
	t_player		player;
	t_mlx			*mlx;
	t_img			game_img;
	t_img			texture[4];
	t_resolution	res;
} t_game;

/* ****************************** FUNCTIONS ****************************** */

/* ******   CUB3D   ****** */

/* ******    PARSING    ****** */

/* ******     INIT      ****** */

/* ******     UTILS     ****** */

/* ******      MLX      ****** */
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		exit_game(t_mlx mlx);
int	key_release(int key, t_mlx mlx);

#endif