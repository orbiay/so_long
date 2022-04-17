/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:49:16 by orbiay            #+#    #+#             */
/*   Updated: 2021/12/24 16:19:20 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	move_up2(void)
{
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/super.XPM", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x, g_pos_y - 80);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/soil.xpm", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x, g_pos_y);
}

void	move_down2(void)
{
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/super.XPM", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x, g_pos_y + 80);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/soil.xpm", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x, g_pos_y);
}

void	move_right2(void)
{
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/super.XPM", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x + 80, g_pos_y);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/soil.xpm", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x, g_pos_y);
}

void	move_left2(void)
{
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/super.XPM", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x - 80, g_pos_y);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/soil.xpm", &g_f, &g_k);
	mlx_put_image_to_window
		(g_img.mlx, g_img.window, g_img.img, g_pos_x, g_pos_y);
}
