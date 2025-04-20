# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 01:26:37 by mbarrah           #+#    #+#              #
#    Updated: 2025/02/22 01:26:38 by mbarrah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

# Colors and formatting
PURPLE = \033[35m
BRIGHT_PURPLE = \033[95m
GREEN = \033[32m
RESET = \033[0m

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRCS = $(SRC_DIR)/ft_str/ft_split.c \
       $(SRC_DIR)/ft_str/ft_strchr.c \
       $(SRC_DIR)/ft_str/ft_strdup.c \
       $(SRC_DIR)/ft_str/ft_striteri.c \
       $(SRC_DIR)/ft_str/ft_strjoin.c \
       $(SRC_DIR)/ft_str/ft_strlcat.c \
       $(SRC_DIR)/ft_str/ft_strlcpy.c \
       $(SRC_DIR)/ft_str/ft_strlen.c \
       $(SRC_DIR)/ft_str/ft_strmapi.c \
       $(SRC_DIR)/ft_str/ft_strncmp.c \
       $(SRC_DIR)/ft_str/ft_strnstr.c \
       $(SRC_DIR)/ft_str/ft_strrchr.c \
       $(SRC_DIR)/ft_str/ft_strtrim.c \
       $(SRC_DIR)/ft_str/ft_substr.c \
       $(SRC_DIR)/ft_nbr/ft_atoi.c \
       $(SRC_DIR)/ft_nbr/ft_itoa.c \
       $(SRC_DIR)/ft_mem/ft_bzero.c \
       $(SRC_DIR)/ft_mem/ft_calloc.c \
       $(SRC_DIR)/ft_mem/ft_memchr.c \
       $(SRC_DIR)/ft_mem/ft_memcmp.c \
       $(SRC_DIR)/ft_mem/ft_memcpy.c \
       $(SRC_DIR)/ft_mem/ft_memmove.c \
       $(SRC_DIR)/ft_mem/ft_memset.c \
       $(SRC_DIR)/ft_lst/ft_lstadd_back.c \
       $(SRC_DIR)/ft_lst/ft_lstadd_front.c \
       $(SRC_DIR)/ft_lst/ft_lstclear.c \
       $(SRC_DIR)/ft_lst/ft_lstdelone.c \
       $(SRC_DIR)/ft_lst/ft_lstiter.c \
       $(SRC_DIR)/ft_lst/ft_lstlast.c \
       $(SRC_DIR)/ft_lst/ft_lstmap.c \
       $(SRC_DIR)/ft_lst/ft_lstnew.c \
       $(SRC_DIR)/ft_lst/ft_lstsize.c \
       $(SRC_DIR)/ft_file/ft_putchar_fd.c \
       $(SRC_DIR)/ft_file/ft_putendl_fd.c \
       $(SRC_DIR)/ft_file/ft_putnbr_fd.c \
       $(SRC_DIR)/ft_file/ft_putstr_fd.c \
       $(SRC_DIR)/ft_char/ft_isalnum.c \
       $(SRC_DIR)/ft_char/ft_isalpha.c \
       $(SRC_DIR)/ft_char/ft_isascii.c \
       $(SRC_DIR)/ft_char/ft_isdigit.c \
       $(SRC_DIR)/ft_char/ft_isprint.c \
       $(SRC_DIR)/ft_char/ft_tolower.c \
       $(SRC_DIR)/ft_char/ft_toupper.c \
       $(SRC_DIR)/get_next_line/get_next_line.c \
       $(SRC_DIR)/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I$(INC_DIR)

define BANNER
	@echo 
	@echo 
	@echo "$(PURPLE)██╗  ██╗██╗   ██╗██╗   ██╗$(BRIGHT_PURPLE)██╗  ██╗ █████╗ ██╗  ██╗██╗   ██╗$(RESET)"
	@echo "$(PURPLE)██║ ██╔╝██║   ██║██║   ██║$(BRIGHT_PURPLE)██║  ██║██╔══██╗██║ ██╔╝██║   ██║$(RESET)"
	@echo "$(PURPLE)█████╔╝ ██║   ██║██║   ██║$(BRIGHT_PURPLE)███████║███████║█████╔╝ ██║   ██║$(RESET)"
	@echo "$(PURPLE)██╔═██╗ ██║   ██║██║   ██║$(BRIGHT_PURPLE)██╔══██║██╔══██║██╔═██╗ ██║   ██║$(RESET)"
	@echo "$(PURPLE)██║  ██╗╚██████╔╝╚██████╔╝$(BRIGHT_PURPLE)██║  ██║██║  ██║██║  ██╗╚██████╔╝$(RESET)"
	@echo "$(PURPLE)╚═╝  ╚═╝ ╚═════╝  ╚═════╝ $(BRIGHT_PURPLE)╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ $(RESET)"
	@echo 

endef

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/ft_str
	@mkdir -p $(OBJ_DIR)/ft_nbr
	@mkdir -p $(OBJ_DIR)/ft_mem
	@mkdir -p $(OBJ_DIR)/ft_lst
	@mkdir -p $(OBJ_DIR)/ft_file
	@mkdir -p $(OBJ_DIR)/ft_char
	@mkdir -p $(OBJ_DIR)/get_next_line

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(BANNER)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✨ KuuHaKu's libft is ready! ✨$(RESET)"

clean:
	@$(BANNER)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)🧹 Cleaned up object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🗑️  Removed library$(RESET)"

re: fclean all

.PHONY: all clean fclean re