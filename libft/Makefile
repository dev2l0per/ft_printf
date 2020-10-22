# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 21:04:58 by juyang            #+#    #+#              #
#    Updated: 2020/10/11 00:22:15 by juyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

RM = rm
RMFLAGS = -rf

NAME = libft.a

FILES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd

FILES_Bonus = ft_lstnew \
	  	ft_lstadd_front \
	  	ft_lstsize \
		ft_lstlast \
	  	ft_lstadd_back \
	  	ft_lstdelone \
	  	ft_lstclear \
	  	ft_lstiter \
	  	ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_Bonus = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_Bonus)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_Bonus = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_Bonus)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^ 

bonus: $(NAME) $(OBJS_Bonus)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_Bonus)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_Bonus)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
