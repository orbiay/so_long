/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:21:32 by orbiay            #+#    #+#             */
/*   Updated: 2022/01/03 18:17:57 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*check_map(void)
{
	char	*line;
	char	*str;
	int		fd;

	str = NULL;
	fd = open(g_l, 0);
	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("Error\nMAP INVALID");
		exit(0);
	}
	while (line != NULL)
	{
		str = ft_strjoin(str, line);
		if (line[0] == '\n')
		{
			free(line);
			printf("Error\nPlz no empty");
			exit(0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

int	chek_wall(void)
{
	char	**line;
	char	*rsv;
	int		i;
	char	*str;

	i = 0;
	str = check_map();
	line = ft_split(str, '\n');
	if (loop_1(line[0]) == 0)
		return (0);
	while (line[i] != NULL)
	{
		rsv = line[i];
		i++;
	}
	if (loop_1(rsv) == 0)
	{
		ft_free(line);
		return (0);
	}
	ft_free(line);
	free(str);
	return (1);
}

int	rectongle(char *buff)
{
	char	**split;
	int		lenght_buff;
	int		j;

	lenght_buff = 0;
	j = 0;
	while (buff[lenght_buff] != '\n')
		lenght_buff++;
	split = ft_split(buff, '\n');
	while (split[j])
	{
		if (ft_strlen(split[j]) != lenght_buff || (split[j][0] != '1'
			|| split[j][ft_strlen(split[j]) - 1] != '1'))
		{
			ft_free(split);
			return (0);
		}
		j++;
	}
	ft_free(split);
	return (1);
}

int	main(int ac, char **av)
{
	char	*s;
	char	*str;
	int		l;

	if (ac == 2)
	{
		str = ft_strrchr(av[1], '.');
		if (str == 0)
		{
			printf("\033[0;31mError\nYour extention is wrong");
			return (0);
		}
		if (ft_strncmp(str, ".ber", 5) == 0 && open(av[1], 0) != -1)
		{
			g_l = av[1];
			s = check_map();
			l = check_all(s);
			position_player();
			if (l <= 8)
				so_long(s);
		}
		else
			printf("\033[0;31mError\nYour extention is wrong");
	}
	return (0);
}
