NAME = libftprintf.a

SRC = prinft.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)NAME = libftprintf.a
