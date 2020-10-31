LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
			convert.c \
			parse.c \
			print.c \
			print_address.c \
			print_cspercent.c \
			print_hex_lower.c \
			print_hex_upper.c \
			print_integer.c \
			print_string.c \
		
SURPL_O = 	ft_printf.o \
				convert.o \
				parse.o \
				print.o \
				print_address.o \
				print_cspercent.o \
				print_hex_lower.o \
				print_hex_upper.o \
				print_integer.o \
				print_string.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all