# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 11:51:44 by valgrant          #+#    #+#              #
#    Updated: 2024/05/22 21:41:56 by valgrant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libn.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_is.c \
	ft_itoa.c ft_mem.c ft_len.c ft_is.c ft_tofd.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_toupper.c ft_tolower.c \
	ft_toput.c main.c ft_printfmem_fd.c ft_tohexa.c \
	get_next_line.c get_next_line_utils.c ft_puttab.c

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
