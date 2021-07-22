NAME		:= push_swap

SRCSDIR		:= ./srcs/
SRCS		:= push_swap.c \
				op_rotate.c \
				op_rrotate.c \
				op_swap.c \
				sort_2.c \
				sort.c \
				stack.c \
				utils.c \
				validator.c \
				circular_dlist/circular_dlist.c
SRCS		:= $(addprefix $(SRCSDIR), $(SRCS))
OBJS		:= $(SRCS:.c=.o)

INCLUDE		:= -I./includes/ -I./libft/

LIBDIR		:= ./libft
LIBPATH		:= $(LIBDIR)/libft.a
LFLAGS		:= -L${LIBDIR} -lft

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
DEBUG		:=

RM			:= rm -f
C_GREEN		:= "\x1b[32m"
C_DEFAULT	:= "\x1b[39m"
C_RESET		:= "\x1b[0m"


.c.o:
			$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBPATH)
			$(CC) $(CFLAGS) $(DEBUG) $(OBJS) $(LFLAGS) -o $@
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

$(LIBPATH):	init
			$(MAKE) -C $(LIBDIR)

init:		## git clone --recursive https://this_repository
			git submodule update --init

clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C $(LIBDIR)

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) fclean -C $(LIBDIR)

re:			fclean $(NAME)

bonus:		$(NAME)

.PHONY:		all clean fclean re bonus
.PHONY:		init
