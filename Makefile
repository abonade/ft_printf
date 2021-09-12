SRCS		=	srcs/printf_put.c\
				srcs/printf_utils.c\
				srcs/printf.c

OBJS		=	$(SRCS:.c=.o)

CC			=	@clang
RM			=	@rm -f
NAME		=	libftprintf.a

FLAGS		=	-Wall -Werror -Wextra -Iincludes

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):		start_message $(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@echo "\033[1A\033[25C\033[1;32m✓\033[0m"

all:			$(NAME)

clean:
				@echo "\033[0;33mCleaning \033[1;31m$(NAME)\033[0;33m's objects\033[0m"
				$(RM) $(OBJS)

start_message:
				@echo "\033[0;33mMaking \033[1;31m$(NAME)\033[0;33m\t\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"

fclean:			
				$(RM) $(NAME)
				$(RM) $(OBJS)
				@echo "\033[0;33mRemoving \033[1;31m$(NAME)\033[0;33m.\033[0m"

re:				fclean all

.PHONY:			all clean fclean re