# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 16:32:24 by fulloa-s          #+#    #+#              #
#    Updated: 2021/07/22 17:16:06 by fulloa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	philo.c \
				philo_create.c \
				philo_pars.c \
				philo_utils.c \
				philo_routine.c \
				philo_init.c

NAME		=	philo

CFLAGS		=	-Wall -Wextra -Werror -pthread

CC			=	gcc

OBJCS		=	$(SRCS:.c=.o)

.c.o		:
				@$(CC)  -c $<

all			:	$(NAME)
			
$(NAME)		:	$(OBJCS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJCS)

clean		:
				@rm -f $(OBJCS)

fclean		:	clean
				@rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re run