NAME		= cub3d
SRCS		= $(addprefix srcs/, main.c)
OBJS		= $(SRCS:.c=.o)
INCL		= -I includes -I lib/minilibx-linux -I lib/libft
LIBFTDIR	= lib/libft
LIBFT		= $(LIBFTDIR)/libft.a
MLXDIR		= lib/minilibx-linux
MLX			= $(MLXDIR)/libmlx.a
LIBS		= -L$(MLXDIR) -L$(LIBFTDIR) -lmlx -lXext -lX11
CC			= clang
CFLAGS		= -Wall -Wextra -O3
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all:		$(MLX) $(LIBFT) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(MLX):
			make -C $(MLXDIR)

$(LIBFT):
			make -C $(LIBFTDIR)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
