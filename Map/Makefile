SRCS = map_wall.c so_long.c map.c moving.c graphic.c ft_split.c get_next_line.c get_next_line_utils.c ft_itoa.c norminette.c ft_strncmp.c ft_strrchr.c
FLAGS = -Wall -Wextra -Werror
CC = cc
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = so_long

all:	$(NAME)
$(NAME):	$(SRCS)
		$(CC) $(FLAGS) $(SRCS) $(MLX) -o $(NAME)

clean :

fclean:	clean
	rm -f $(NAME)
re:	fclean all