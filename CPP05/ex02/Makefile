# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 10:45:07 by javiersa          #+#    #+#              #
#    Updated: 2023/11/29 20:05:14 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General variables
PERSONALNAME = AForm
NAME = $(PERSONALNAME).a
PROGRAM = $(PERSONALNAME)
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
CLEAN = rm -Rf
SRC = $(wildcard *.cpp)
OBJS := $(SRC:.cpp=.o)

# Personal use variables
PARAMS = nothing
DATETIME := $(shell date +%Y-%m-%d' '%H:%M:%S)
GIT_BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
USER := $(shell whoami)
GITIGNORE = .gitignore

# General rules

all: $(PROGRAM)


$(PROGRAM): $(LIBFTPLUS_LIB) $(NAME)
	@$(CC) $(CFLAGS) $(NAME) -o $(PROGRAM)
	@echo "$(MAGENTA)Program $(PERSONALNAME) created successfully.$(DEFAULT)"

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"
	
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(MAGENTA)Library $(NAME) created successfully.$(DEFAULT)"
clean:
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) All objects from $(PERSONALNAME)."
fclean: clean
	@$(CLEAN) ./$(NAME) ./$(PROGRAM)
	@echo "$(RED)Removing:$(DEFAULT) Library $(NAME)."
	@echo "$(RED)Removing:$(DEFAULT) Program $(PROGRAM)."
re: fclean all

#Personal use
git: fclean $(GITIGNORE)
	@git add *
	@echo "$(BOLD)$(YELLOW)Git ($(GIT_BRANCH)):$(WHITE) Adding all archives.$(DEFAULT)"
	@git commit -m "[$(DATETIME)] - Little changes by $(USER)"
	@echo "$(BOLD)$(CYAN)Git ($(GIT_BRANCH)):$(WHITE) Commit this changes in brunch\
	 $(GIT_BRANCH) with "[$(DATETIME)] - Little changes by $(USER)".$(DEFAULT)"
	@git push --set-upstream origin $(GIT_BRANCH)
	@echo "$(BOLD)$(GREEN)Git ($(GIT_BRANCH)):$(WHITE) Pushing all changes.$(DEFAULT)"
submodules:
	@git submodule update --init --recursive
	@echo "$(GREEN)The submodules have been created and updated successfully.$(DEFAULT)"
$(GITIGNORE):
	@echo ".*\n*.out\n*.o\n*.a\n*.dSYM">.gitignore
	@echo "$(GREEN)Creating:$(DEFAULT) Gitignore."
42prepare: submodules
	@rm -rf .git*
	@echo "$(GREEN)All .git removed.$(DEFAULT)"
valgrind_datarace: $(PROGRAM)
	valgrind --tool="helgrind" ./$(PROGRAM) $(PARAMS)
valgrind_leaks: $(PROGRAM)
	valgrind --leak-check=full -s ./$(PROGRAM) $(PARAMS)

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
DEFAULT	:= \033[0m

.PHONY : all clean fclean re \
git submodules gitignore 42prepare valgrind_datarace valgrind_leaks