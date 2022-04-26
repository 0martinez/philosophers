# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 12:52:22 by omartine          #+#    #+#              #
#    Updated: 2022/04/26 13:24:35 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= philo
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make


SRCS = main.c utils/ft_atoi.c philo_dance/philo_dance.c philo_dance/philo_moves.c

OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME) -lpthread

clean:
				$(RM) $(OBJS) $(BONUS_O)
fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean $(NAME)

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(BONUS_O)
				$(CC) $(CFLAGS) $(BONUS_O) -o $(NAME_BONUS)

rebonus:		fclean $(NAME) $(NAME_BONUS)

.PHONY:			all clean fclean re bonus
