CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -g3

HEADERS = so_long.h

SOURCES = main.c \
		check_img.c \
		init_all_line.c \
		parsing_map.c \
		parsing_map_2.c \
		border_map.c \
		check_if_possible_to_end.c \
		init_map.c \
		set_data.c \
		set_img.c \
		put_image_in_map.c \
		replace_spike.c \
		print_counter.c \
		input.c \
		move.c \
		animation.c \
		error.c \
		clear_all.c

HEADERS_BONUS = so_long_bonus.h

SOURCES_BONUS = main_bonus.c \
		check_img_bonus.c \
		init_all_line_bonus.c \
		parsing_map_bonus.c \
		parsing_map_2_bonus.c \
		border_map_bonus.c \
		check_if_possible_to_end_bonus.c \
		init_map_bonus.c \
		set_data_bonus.c \
		set_img_bonus.c \
		put_image_in_map_bonus.c \
		replace_spike_bonus.c \
		print_counter_bonus.c \
		input_bonus.c \
		move_bonus.c \
		animation_bonus.c \
		check_mob_bonus.c \
		error_bonus.c \
		clear_all_bonus.c

SRC = srcs/
DIR = objs_deps/
INC = includes/

SRC_BONUS = srcs_bonus/
DIR_BONUS = objs_deps_bonus/
INC_BONUS = includes_bonus/

INCLUDES = -I/$(INCS)

SRCS = $(addprefix $(SRC), $(SOURCES))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))
INCS = $(addprefix $(INC), $(HEADERS))

INCLUDES_BONUS = -I/$(INCS_BONUS)

SRCS_BONUS = $(addprefix $(SRC_BONUS), $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(DIR_BONUS), $(OBJ_BONUS))
DEPS_BONUS = $(addprefix $(DIR_BONUS), $(DEP_BONUS))
INCS_BONUS = $(addprefix $(INC_BONUS), $(HEADERS_BONUS))

OBJ = $(SOURCES:.c=.o)
DEP = $(SOURCES:.c=.d)

OBJ_BONUS = $(SOURCES_BONUS:.c=.o)
DEP_BONUS = $(SOURCES_BONUS:.c=.d)

NAME = so_long

NAME_BONUS = so_long_bonus

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make -sC libft
	@make -sC minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11
	@echo "Compilation completed"

$(NAME_BONUS) : $(OBJS_BONUS)
	@make -sC libft
	@make -sC minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -o $(NAME_BONUS) $(OBJS_BONUS) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11
	@echo "Compilation completed"

$(DIR)%.o : $(SRC)%.c | $(DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(DIR_BONUS)%.o : $(SRC_BONUS)%.c | $(DIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -o $@ -c $<

$(DIR) :
	@echo "Start Compilation for $(NAME)"
	@echo "Wait ..."
	@mkdir -p objs_deps

$(DIR_BONUS) :
	@echo "Start Compilation for $(NAME_BONUS)"
	@echo "Wait ..."
	@mkdir -p objs_deps_bonus

clean :
	@echo "Deleting Objects and Dependencies"
	@make fclean -sC libft
	@make clean -sC minilibx-linux
	@rm -rf $(DIR)
	@rm -rf $(DIR_BONUS)

fclean : clean
	@echo "Deleting the executable"
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re : fclean all

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY : all bonus clean fclean re