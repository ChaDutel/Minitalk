NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
FLAGS = -Wall -Werror -Wextra

DIR_SRCS = sources
DIR_OBJS = .objets
DIR_INCS = includes

DIR_LIBFT = libft

LST_SRCS_CLIENT = client.c
LST_SRCS_SERVER = server.c

LST_OBJS_CLIENT = $(LST_SRCS_CLIENT:.c=.o)
LST_OBJS_SERVER = $(LST_SRCS_SERVER:.c=.o)

LST_INCS = minitalk.h

SRCS_CLIENT = $(addprefix $(DIR_SRCS)/,$(LST_SRCS_CLIENT))
SRCS_SERVER = $(addprefix $(DIR_SRCS)/,$(LST_SRCS_SERVER))

OBJS_CLIENT = $(addprefix $(DIR_OBJS)/,$(LST_OBJS_CLIENT))
OBJS_SERVER = $(addprefix $(DIR_OBJS)/,$(LST_OBJS_SERVER))

INCS = $(addprefix $(DIR_INCS)/,$(LST_INCS))

AR_LIBFT = $(DIR_LIBFT)/libft.a

all : make_libft $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(AR_LIBFT) $(OBJS_CLIENT)
				$(CC) $(FLAGS) $^ -o $@

$(NAME_SERVER) : $(AR_LIBFT) $(OBJS_SERVER)
				$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_OBJS)
				$(CC) $(FLAGS) -I $(INCS) -c $< -o $@

$(AR_LIBFT) : 
			$(MAKE) -C $(DIR_LIBFT)

$(DIR_OBJS) :
			mkdir -p $@

make_libft :
		$(MAKE) -C $(DIR_LIBFT)

clean :
		rm -rf $(DIR_OBJS)
		$(MAKE) clean -C $(DIR_LIBFT)

fclean : clean
		rm -rf $(NAME_CLIENT) $(NAME_SERVER)
		$(MAKE) fclean -C $(DIR_LIBFT)

re : fclean all

.PHONY : clean fclean re all









