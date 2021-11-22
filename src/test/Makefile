# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:26:41 by hyeonsok          #+#    #+#              #
#    Updated: 2021/11/23 04:32:56 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = arch -x86_64 gcc
CFLAGS = -Wall -Werror -Wextra -g3
ifdef DEBUG
	CFLAGS += -g3
endif

INCLUDES = -I ../../include

TESTDIR := .
UTILDIR := ../../util
OBJDIR := ./obj
OBJS	= $(addprefix $(OBJDIR)/, \
			test_error.o)
OBJS	+= $(addprefix $(OBJDIR)/, \
			ft_isdigit.o \
			ft_atoll.o \
			ft_isspace.o \
			ft_isintf.o \
			ft_strarriter.o \
			ft_strchr.o \
			ft_strlen.o \
			ft_strspn.o \
			ft_ternary.o \
			ft_perror.o)

.PHONY:		all
all:		test_error

$(OBJDIR)/%.o : $(TESTDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(UTILDIR)/%.c
			$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

test_error:	$(OBJDIR) $(OBJS)
			$(CC) $(INCLUDES) $(OBJS) -o test_error

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
