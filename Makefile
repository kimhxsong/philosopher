# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:26:41 by hyeonsok          #+#    #+#              #
#    Updated: 2021/12/11 16:37:03 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./include/

SRCDIR := ./src
UTILDIR := ./util
OBJDIR := ./obj
OBJS	= $(addprefix $(OBJDIR)/, \
			init.o \
			main.o \
			simul_print.o \
			simul_routine_detect.o \
			simul_routine_dining.o \
			validate.o \
			simul.o)
OBJS	+= $(addprefix $(OBJDIR)/, \
			ft_atoi.o \
			ft_atoll.o \
			ft_isdigit.o \
			ft_isintf.o \
			ft_ispostive.o \
			ft_isspace.o \
			ft_strarriter.o \
			ft_strchr.o \
			ft_strlen.o \
			ft_strspn.o \
			ft_error.o)

NAME = philo

.PHONY:		all
all:		$(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@
$(OBJDIR)/%.o : $(UTILDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY:		NAME
$(NAME):	$(OBJDIR) $(OBJS)
			$(CC) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS): | $(OBJDIR)
$(OBJDIR):
			mkdir $(OBJDIR)

.PHONY:		clean
clean:
			$(RM) -r $(OBJDIR)

.PHONY:		fclean
fclean:		clean
			$(RM) -r $(NAME)

.PHONY:		re
re:
			$(MAKE) fclean
			$(MAKE)
