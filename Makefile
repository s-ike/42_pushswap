NAME		:= push_swap

SRCSDIR		:= ./srcs/
SRCS		:= push_swap.c \
				ans_list.c \
				exit.c \
				init.c \
				op_push.c \
				op_rotate.c \
				op_rrotate.c \
				op_swap.c \
				order.c \
				presort_list.c \
				sort_2.c \
				sort_3.c \
				sort_3_b_and_pa.c \
				sort_4.c \
				sort_6.c \
				sort_6_utils.c \
				sort_6_b.c \
				sort_7.c \
				sort_7_pa.c \
				sort_7_pa2.c \
				sort_7_pb.c \
				sort.c \
				stack.c \
				validator.c \
				circular_dlist/add.c \
				circular_dlist/comp.c \
				circular_dlist/info.c \
				circular_dlist/init.c \
				circular_dlist/print.c \
				circular_dlist/remove.c \
				circular_dlist/search.c \
				circular_dlist/search_idx.c \
				utils/tlist_sort.c \
				utils/utils.c
SRCS		:= $(addprefix $(SRCSDIR), $(SRCS))
OBJS		:= $(SRCS:.c=.o)

INCLUDE		:= -I./includes/ -I./libft/

LIBDIR		:= ./libft
LIBPATH		:= $(LIBDIR)/libft.a
LFLAGS		:= -L${LIBDIR} -lft

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

DEBUG		:= -g
ifdef LEAKS
DEBUG2		:=
else
DEBUG2		:= -fsanitize=address
endif

RM			:= rm -f
C_GREEN		:= "\x1b[32m"
C_DEFAULT	:= "\x1b[39m"
C_RESET		:= "\x1b[0m"


.c.o:
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBPATH)
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(OBJS) $(LFLAGS) -o $@
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

$(LIBPATH):	init
			$(MAKE) bonus -C $(LIBDIR)

init:		## git clone --recursive https://this_repository
			git submodule update --init

leaks:		$(LIBPATH)	## For leak check
			$(MAKE) CFLAGS="$(CFLAGS) -D LEAKS=1" LEAKS=TRUE

clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C $(LIBDIR)

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) fclean -C $(LIBDIR)

re:			fclean $(NAME)

bonus:		$(NAME)

.PHONY:		all clean fclean re bonus
.PHONY:		init leaks
