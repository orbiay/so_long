/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:20:10 by orbiay            #+#    #+#             */
/*   Updated: 2022/01/03 16:12:59 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<mlx.h>

void	move_up(char **s)
{
	char	*nbr;

	if (s[g_px - 1][g_py] == 'C')
	{
		s[g_px - 1][g_py] = '0';
		g_count_c--;
	}
	move_up2();
	g_px -= 1;
	if (s[g_px][g_py] == 'E' && g_count_c == 0)
	{
		printf("\033[0;32m\n\nCOUNGRATULATION!!!");
		ft_free(s);
		exit(0);
	}
	g_pos_y -= 80;
	g_keycode = 42;
	g_count_m++;
	nbr = ft_itoa(g_count_m);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/boxe.xpm", &g_f, &g_k);
	mlx_put_image_to_window(g_img.mlx, g_img.window, g_img.img, 0, 0);
	mlx_string_put(g_img.mlx, g_img.window, 10, 10, 0, nbr);
	free(nbr);
}

void	move_down(char **s)
{
	char	*nbr;

	move_down2();
	g_px += 1;
	if (s[g_px][g_py] == 'C')
	{
		s[g_px][g_py] = '0';
		g_count_c--;
	}
	if (s[g_px][g_py] == 'E' && g_count_c == 0)
	{
		printf("\033[0;32m\n\nCONGRATULATION!!!");
		ft_free(s);
		exit(0);
	}
	g_pos_y += 80;
	g_keycode = 42;
	g_count_m++;
	nbr = ft_itoa(g_count_m);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/boxe.xpm", &g_f, &g_k);
	mlx_put_image_to_window(g_img.mlx, g_img.window, g_img.img, 0, 0);
	mlx_string_put(g_img.mlx, g_img.window, 10, 10, 0, nbr);
	free(nbr);
}

void	move_right(char **s)
{
	char	*nbr;

	move_right2();
	g_py += 1;
	if (s[g_px][g_py] == 'C')
	{
		s[g_px][g_py] = '0';
		g_count_c--;
	}
	if (s[g_px][g_py] == 'E' && g_count_c == 0)
	{
		printf("\033[0;32m\n\nCOUNGRATULATION!!!");
		ft_free(s);
		exit(0);
	}
	g_pos_x += 80;
	g_keycode = 42;
	g_count_m++;
	nbr = ft_itoa(g_count_m);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/boxe.xpm", &g_f, &g_k);
	mlx_put_image_to_window(g_img.mlx, g_img.window, g_img.img, 0, 0);
	mlx_string_put(g_img.mlx, g_img.window, 10, 10, 0x000000, nbr);
	free(nbr);
}

void	move_left(char **s)
{
	char	*nbr;

	move_left2();
	g_py -= 1;
	if (s[g_px][g_py] == 'C')
	{
		s[g_px][g_py] = '0';
		g_count_c--;
	}
	if (s[g_px][g_py] == 'E' && g_count_c == 0)
	{
		printf("\033[0;32m\n\nCONGRATULATION!!!");
		ft_free(s);
		exit(0);
	}
	g_pos_x -= 80;
	g_keycode = 42;
	g_count_m++;
	nbr = ft_itoa(g_count_m);
	g_img.img = mlx_xpm_file_to_image
		(g_img.mlx, "../image.xpm/boxe.xpm", &g_f, &g_k);
	mlx_put_image_to_window(g_img.mlx, g_img.window, g_img.img, 0, 0);
	mlx_string_put(g_img.mlx, g_img.window, 10, 10, 0x000000, nbr);
	free(nbr);
}

void	ft_free(char	**str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
