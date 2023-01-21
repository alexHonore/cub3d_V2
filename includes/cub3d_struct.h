/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:21:30 by anshimiy          #+#    #+#             */
/*   Updated: 2022/11/21 16:27:01 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

/* linux */
/*
# define ESC 			65307
# define SPACE_KEY 		32
# define A_KEY			97
# define D_KEY			100
# define E_KEY			101
# define M_KEY			109
# define R_KEY	 		114
# define S_KEY			115
# define W_KEY			119
# define SHIFT_KEY		65505
# define RIGHT_KEY		65363
# define LEFT_KEY		65361  
# define DOWN_KEY		65362 
# define UP_KEY			65364 
*/

/* mac */
# define ESC 			53
# define SPACE_KEY 		49
# define A_KEY			0
# define D_KEY			2
# define E_KEY			14
# define M_KEY			46
# define R_KEY	 		15
# define S_KEY			1
# define W_KEY			13
# define SHIFT_KEY		257
# define RIGHT_KEY		124
# define LEFT_KEY		123
# define UP_KEY			126
# define DOWN_KEY		125

/* Colors */
# define TRANS			0x980088
# define WHITE			0xffffff
# define BLACK			0x000000
# define RED			0xFF0000
# define GRAY			0xAAAAAA
# define FLOOR_C		0x303030
# define CEILING_C		0x909090
# define BLUE			0x0000ff
# define YELLOW			0xf0de18

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		height;
	int		width;
	int		endian;
}   t_img;

typedef struct	s_resolution 
{
	int		width_x;
	int		height_y;
}	t_resolution;

typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
} t_pos;

typedef struct s_size
{
	double	x;
	double	y;
	double	z;
} t_size;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
} t_rgb;


#endif