
NAME	:= megaphone

SRC_DIR	:= src
SRCS	:= megaphone.cpp
SRCS	:= $(SRCS:%=$(SRC_DIR)/%)

OBJ_DIR	:= .build
OBJS	:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra -Wpedantic -std=c++11
RM		:= rm -rf

DEBUG	?= 1
ifeq ($(DEBUG),1)
DFLAGS	:= -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@
	@printf "$(CREATED)" $@ $(CUR_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@printf "$(REMOVED)" $(OBJ_DIR) $(CUR_DIR)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	@printf "$(REMOVED)" $(NAME) $(CUR_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# ----------------------------------- colors --------------------------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

# ----------------------------------- messages ------------------------------- #

CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED	:= $(MAGENTA) $(BOLD) REMOVED %s (%s) $(RESET)\n\n
CREATED	:= $(GREEN) $(BOLD) CREATED %s (%s) $(RESET)\n\n
UPDATED	:= $(GREEN) $(BOLD) CREATED OR UPDATED %s (%s) $(RESET)\n\n

