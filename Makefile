NAME		= cub3d
SRCS		= $(addprefix srcs/, main.c init.c\
			$(addprefix errors/, error_handling.c) \
			$(addprefix parsing/, parsing.c file_check.c parse_settings.c parse_colors.c \
				settings_check.c parse_map.c save_map.c check_map.c) \
			$(addprefix raycasting/, start.c windows_tools.c input.c draw_map.c movement.c) \
			$(addprefix utils/, ft_strlen.c ft_strncmp.c ft_isdigit.c ft_atoi.c ft_strdup.c\
			$(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)))
OBJS		= $(SRCS:.c=.o)
INCL		= -I includes -I lib/minilibx-linux
MLXDIR		= lib/minilibx-linux
MLX			= $(MLXDIR)/libmlx.a
LIBS		= -L$(MLXDIR) -lmlx -lXext -lX11
CC			= clang
CFLAGS		= -Wall -Wextra -g3 #-fsanitize=address
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all:		$(MLX) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(MLX):
			make -C $(MLXDIR)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
