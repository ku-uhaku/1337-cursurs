CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Iincludes

SRC_DIR	= src

SRC_FILES	= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/ft_atol.c \
			  $(SRC_DIR)/ft_abs.c \
			  $(SRC_DIR)/ft_isdigit.c \
			  $(SRC_DIR)/ft_split.c \
			  $(SRC_DIR)/handle_errors.c \
			  $(SRC_DIR)/stack.c \
			  $(SRC_DIR)/stack_utils.c \
			  $(SRC_DIR)/sort_three.c \
			  $(SRC_DIR)/sort.c \
			  $(SRC_DIR)/sort2.c \
			  $(SRC_DIR)/push.c \
			  $(SRC_DIR)/push_swap.c \
			  $(SRC_DIR)/rev_rotate.c \
			  $(SRC_DIR)/rotate.c \
			  $(SRC_DIR)/swap.c \
			  $(SRC_DIR)/do_move.c

BONUS_SRC_FILES	= $(SRC_DIR)/bonus.c \
				  $(SRC_DIR)/get_next_line.c \
				  $(SRC_DIR)/get_next_line_utils.c

OBJ_FILES		= $(SRC_FILES:%.c=%.o)
BONUS_OBJ_FILES	= $(BONUS_SRC_FILES:%.c=%.o)

EXECUTABLE		= push_swap
BONUS_EXECUTABLE	= checker

all: $(EXECUTABLE)

bonus: $(BONUS_EXECUTABLE)

BASE_OBJ = $(SRC_DIR)/ft_atol.o \
    $(SRC_DIR)/ft_abs.o \
    $(SRC_DIR)/ft_isdigit.o \
    $(SRC_DIR)/ft_split.o \
    $(SRC_DIR)/handle_errors.o \
    $(SRC_DIR)/stack.o \
    $(SRC_DIR)/stack_utils.o \
    $(SRC_DIR)/sort_three.o \
    $(SRC_DIR)/sort.o \
    $(SRC_DIR)/sort2.o \
    $(SRC_DIR)/push.o \
    $(SRC_DIR)/push_swap.o \
    $(SRC_DIR)/rev_rotate.o \
    $(SRC_DIR)/rotate.o \
    $(SRC_DIR)/swap.o \
    $(SRC_DIR)/do_move.o

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_EXECUTABLE): $(BONUS_OBJ_FILES) $(BASE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(EXECUTABLE) $(BONUS_EXECUTABLE)

re: fclean all

.PHONY: all bonus clean fclean re