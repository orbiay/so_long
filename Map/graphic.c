/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:23:18 by orbiay            #+#    #+#             */
/*   Updated: 2022/01/03 17:41:32 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<mlx.h>

void	get_mlx(t_list *img, char *line, char *relative_path)
{
	int		img_width;
	int		img_height;
	char	**str;

	str = ft_split(line, '\n');
	img->y = counting();
	img->x = (ft_strlen(str[0]));
	img->mlx = mlx_init();
	img->img = mlx_xpm_file_to_image
		(img->mlx, relative_path, &img_width, &img_height);
	ft_free(str);
}

void	init(char *s)
{
	get_mlx(&g_img, s, "../image.xpm/boxe.xpm");
	get_mlx(&g_img2, s, "../image.xpm/soil.xpm");
	get_mlx(&g_img3, s, "../image.xpm/coin.XPM");
	get_mlx(&g_img4, s, "../image.xpm/door.XPM");
	get_mlx(&g_img5, s, "../image.xpm/super.XPM");
}

void	render(char **split, int i, int j)
{
	if (split[i][j] == '1')
		mlx_put_image_to_window
			(g_img.mlx, g_img.window, g_img.img, g_img.x, g_img.y);
	if (split[i][j] != '1')
		mlx_put_image_to_window
			(g_img.mlx, g_img.window, g_img2.img, g_img.x, g_img.y);
	if (split[i][j] == 'E')
		mlx_put_image_to_window
			(g_img.mlx, g_img.window, g_img4.img, g_img.x, g_img.y);
	if (split[i][j] == 'C')
	{
		mlx_put_image_to_window
			(g_img.mlx, g_img.window, g_img3.img, g_img.x, g_img.y);
		g_count_c++;
	}
	if (split[i][j] == 'P')
	{
		g_pos_x = g_img.x;
		g_pos_y = g_img.y;
		mlx_put_image_to_window
			(g_img.mlx, g_img.window, g_img5.img, g_img.x, g_img.y);
	}
}
