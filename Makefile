NAME		= cub3d
SRCS		= main.c init.c\
			error_handling.c \
			parsing.c file_check.c parse_settings.c parse_colors.c \
				settings_check.c parse_map.c save_map.c check_map.c floodfill.c \
			start.c render.c mlx_tools.c input.c movement.c \
				raycast.c three_dimensions.c \
			textures.c	\
			ft_strlen.c ft_strncmp.c ft_isdigit.c ft_atoi.c ft_strdup.c ft_isspace.c ft_isprint.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
			get_next_line.c get_next_line_utils.c \
			free.c
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
OBJSDIR		= objs
INCL		= -I includes -I lib/minilibx-linux
MLXDIR		= lib/minilibx-linux
MLX			= $(MLXDIR)/libmlx.a
LIBS		= -L$(MLXDIR) -lmlx -lXext -lX11 -lm
CC			= gcc
CFLAGS		= -Wall -Wextra -g3 -o3 #-fsanitize=address
RM			= rm -f

vpath %.c srcs/ srcs/errors/ srcs/parsing/ srcs/graphics/ srcs/raycasting srcs/utils srcs/utils/get_next_line

$(OBJSDIR)/%.o:		%.c
			$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all:		$(MLX) $(NAME)

$(OBJS): | $(OBJSDIR)

$(OBJSDIR):
			mkdir $(OBJSDIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(MLX):
			make -C $(MLXDIR)

clean:
			$(RM) $(OBJS)
			rm -rf $(OBJSDIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
