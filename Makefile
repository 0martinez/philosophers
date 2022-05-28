# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 19:56:54 by omartine          #+#    #+#              #
#    Updated: 2022/05/28 18:06:06 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
MAKE			= make


SRCS = main.c init_structs.c utils/utils.c \
		philo_dance/messages.c philo_dance/philo_handler.c \
		philo_dance/philo_moves.c philo_dance/socrates_platon.c \
		utils/born_to_be_free.c

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
