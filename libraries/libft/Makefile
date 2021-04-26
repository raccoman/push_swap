
NAME	= libft.a

SRCS	=	ft_atol.c \
			ft_is_int.c \
			ft_is_num.c \
			ft_gnl.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strcmp.c \
			ft_split.c \
			ft_strlcpy.c \
			ft_putnbr.c \
			ft_printf.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstclear.c \
			ft_lstsize.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM 		= rm -f

AR		= ar rc

FLAGS	= -Wall -Wextra -Werror

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

norme:
			norminette $(SRCS)

.PHONY:		clean fclean re norme









