# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:26:41 by hyeonsok          #+#    #+#              #
#    Updated: 2021/11/23 03:38:34 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
ifdef DEBUG
	CFLAGS += -g3
endif

INCLUDES = -I ./include/

SRCDIR := ./src
UTILDIR := ./util
OBJDIR := ./obj
OBJS	= $(addprefix $(OBJDIR)/, \
			dining.o \
			main.o \
			parse.o \
			print.o \
			time.o \
			watch.o)
OBJS	+= $(addprefix $(OBJDIR)/, \
			ft_atoll.o \
			ft_isdigit.o \
			ft_isintf.o \
			ft_isspace.o \
			ft_strarriter.o \
			ft_strchr.o \
			ft_strlen.o \
			ft_strspn.o \
			ft_ternary.o \
			ft_perror.o)

NAME = philosopher

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
