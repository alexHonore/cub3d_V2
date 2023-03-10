/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:14:48 by anshimiy          #+#    #+#             */
/*   Updated: 2023/01/22 23:34:31 by alexnshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
 
typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;
*/
// Written by Bruh

#include "../includes/mlx/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1080
#define HEIGHT 720

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x += 5;
}

uint32_t get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
uint32_t	color_to_rgb(uint32_t r, uint32_t g, uint32_t b)
{
	return (0xFF | (r << 24) | g << 16 | (b << 8));
}

void	draw_square(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t color)
{
	uint32_t	i;
	uint32_t	j;

	i = x;
	j = y;
	while (i <= height)
	{
		j = y;
		while (j <= width)
		{
			mlx_put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "raycaster", 0);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 50, 50);
	//ft_memset(g_img->pixels, get_rgba(255, 0, 0, 122), (g_img->width * g_img->height) * sizeof(int));
	draw_square(g_img, 5, 5, 50, 50, 0xFF0000FF);
	mlx_image_to_window(mlx, g_img, 1, 1);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}