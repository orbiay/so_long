/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:25:26 by orbiay            #+#    #+#             */
/*   Updated: 2022/01/03 16:48:16 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5

# include <stdlib.h>
# include <unistd.h>
# include<fcntl.h>
# include <stdio.h>
# include<mlx.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strchr(char *str);
char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);
char	*line(void);
char	**ft_split(char const *s, char c);
int		rectongle(char *buff);
int		loop_1(char *str);
int		check_all(char *str);
int		check_yes(char *str, char c);
int		check_no(char *str);
int		chek_wall(void);
void	so_long(char *s);
void	wall_2d(char *s);
void	b_ground_2d(char *s);
int		counting(void);
char	*check_map(void);
void	init(char *s);
void	render(char **split, int i, int j);
void	move_up(char **s);
void	move_down(char **s);
void	move_right(char **s);
void	move_left(char **s);
void	position_player(void);
int		ft_exit(void);
char	*ft_itoa(int n);
void	move_up2(void);
void	move_down2(void);
void	move_right2(void);
void	move_left2(void);
char	*ft_strrchr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	ft_free(char	**str);

typedef struct s_list
{
	int		x;
	int		y;
	void	*mlx;
	void	*img;
	void	*window;
}t_list;

int		g_count;
int		g_i;
int		g_j;
int		g_pos_x;
int		g_pos_y;
int		g_px;
int		g_py;
int		g_count_c;
int		g_count_m;
int		g_f ;
int		g_k;
int		g_keycode;
char	**g_split;
char	*g_l;

t_list	g_img;
t_list	g_img2;
t_list	g_img3;
t_list	g_img4;
t_list	g_img5;
#endif
