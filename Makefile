NAME		= cub3d
SRCS		= $(addprefix srcs/, main.c)
OBJS		= $(SRCS:.c=.o)
INCL		= -I includes -I lib/minilibx-linux
MLXDIR		= lib/minilibx-linux
MLX			= $(MLXDIR)/libmlx.a
LIBS		= -L$(MLXDIR) -L$(LIBFTDIR) -lmlx -lXext -lX11
CC			= clang
CFLAGS		= -Wall -Wextra -O3
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
