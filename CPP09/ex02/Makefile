# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 10:45:07 by javiersa          #+#    #+#              #
#    Updated: 2024/01/17 19:16:13 by javiersa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General variables
PERSONALNAME = PmergeMe
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

LIBDIR = ./lib
OBJDIR = ./obj
LIB = $(LIBDIR)/$(PERSONALNAME).a
PROGRAM = $(PERSONALNAME)
CLEAN = rm -Rf
SRC = $(wildcard *.cpp)
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

# Personal use variables
PARAMS = nothing
DATETIME := $(shell date +%Y-%m-%d' '%H:%M:%S)
GIT_BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
USER := $(shell whoami)
GITIGNORE = .gitignore

# General rules
all: $(PROGRAM)

$(PROGRAM): $(LIB)
	@$(CC) $(CFLAGS) $(LIB) -o $(PROGRAM)
	@echo "$(MAGENTA)Program $(PERSONALNAME) created successfully.$(DEFAULT)"
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(GREEN)Creating:$(DEFAULT) $(OBJDIR) directory."
$(LIBDIR):
	@mkdir -p $(LIBDIR)
	@echo "$(GREEN)Creating:$(DEFAULT) $(LIBDIR) directory."
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"
$(LIB): $(OBJS) $(LIBDIR)
	@ar rcs $(LIB) $(OBJS)
	@echo "$(MAGENTA)Library $(LIB) created successfully.$(DEFAULT)"
clean:
	@$(CLEAN) -f ./$(OBJS)
	@$(CLEAN) -rf $(OBJDIR)
	@echo "$(RED)Removing:$(DEFAULT) All objects from $(PERSONALNAME)."
fclean: clean
	@$(CLEAN) ./$(LIB) ./$(PROGRAM)
	@$(CLEAN) -rf $(LIBDIR)
	@echo "$(RED)Removing:$(DEFAULT) Library $(LIB)."
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
git submodules 42prepare valgrind_datarace valgrind_leaks