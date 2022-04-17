/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:59:38 by orbiay            #+#    #+#             */
/*   Updated: 2022/01/03 18:17:20 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	loop_1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_yes(char *str, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_no(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'P' && str[i] != 'C' && str[i] != '0'
			&& str[i] != 'C' && str[i] != '1'
			&& str[i] != 'E' && str[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	check_all(char *str)
{
	int	i;

	i = 0;
	if (check_yes(str, '0') <= 0)
		i = printf("Error\nmust have at least one 0");
	else if (chek_wall() == 0 || rectongle(str) == 0)
		i = printf("Error\nfix your wall");
	else if (check_yes(str, 'C') <= 0)
		i = printf("Error\nmust have at least one collectible");
	else if (check_yes(str, 'E') <= 0)
		i = printf("Error\nmust have at least one exit");
	else if (check_yes(str, 'P') <= 0)
		i = printf("Error\nmust have one Player");
	else if (check_yes(str, 'P') > 1)
		i = printf("Error\nyou have more than one player");
	else if (check_no(str) == -1)
		i = printf("MAP INVALID");
	else
		i = printf("GOOD MAP");
	return (i);
}

void	position_player(void)
{
	char	*str;
	char	**s;
	int		i;
	int		j;
	int		count;

	i = -1;
	str = check_map();
	s = ft_split(str, '\n');
	count = counting();
	while (++i < count)
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == 'P')
			{
				g_py = j;
				g_px = i;
			}
		}
	}
	ft_free(s);
	free(str);
}
