/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:29:36 by orbiay            #+#    #+#             */
/*   Updated: 2022/01/04 12:00:00 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include"get_next_line.h"

int	keys(int key, char **s)
{
	g_keycode = key;
	if ((g_keycode == 126 || g_keycode == 13) && (s[g_px - 1][g_py] != '1'
		&& (s[g_px - 1][g_py] != 'E' || g_count_c == 0)))
		move_up(s);
	else if ((g_keycode == 1 || g_keycode == 125) && (s[g_px + 1][g_py] != '1'
		&& (s[g_px + 1][g_py] != 'E' || g_count_c == 0)))
		move_down(s);
	else if ((g_keycode == 2 || g_keycode == 124) && (s[g_px][g_py + 1] != '1'
		&& (s[g_px][g_py + 1] != 'E' || g_count_c == 0)))
		move_right(s);
	else if ((g_keycode == 0 || g_keycode == 123) && (s[g_px][g_py - 1] != '1'
		&& (s[g_px][g_py - 1] != 'E' || g_count_c == 0)))
		move_left(s);
	else if (g_keycode == 53)
	{
		ft_free(s);
		exit(0);
	}
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}

void	so_long(char *s)
{
	init(s);
	g_img.window = mlx_new_window
		(g_img.mlx, g_img.x * 80, g_img.y * 80, "SO_LONG");
	g_i = 0;
	g_img.y = 0;
	g_split = ft_split(s, '\n');
	while (g_i < g_count)
	{
		g_j = 0;
		g_img.x = 0;
		while (g_split[g_i][g_j])
		{
			render(g_split, g_i, g_j);
			g_j++;
			g_img.x += 80;
		}
		g_img.y += 80;
		g_i++;
	}
	mlx_key_hook (g_img.window, keys, g_split);
	mlx_hook(g_img.window, 17, 0, ft_exit, NULL);
	mlx_loop(g_img.mlx);
}

int	counting(void)
{
	char	*line;

	g_i = 0;
	g_j = 0;
	line = check_map();
	g_count = 0;
	while (line[g_i])
	{
		if (line[g_i] == '\n' || line[g_i + 1] == '\0')
				g_count++;
		g_i++;
	}
	free(line);
	return (g_count);
}
