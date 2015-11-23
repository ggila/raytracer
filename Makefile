# **************************************************************************** #
#                __  __   _   _  _____ ___ ___ _    ___                        # 
#               |  \/  | /_\ | |/ / __| __|_ _| |  | __|                       #
#               | |\/| |/ _ \| ' <| _|| _| | || |__| _|                        # 
#               |_|  |_/_/ \_\_|\_\___|_| |___|____|___|                       #
#                                                                    ggilaber  #
# **************************************************************************** #

####
# Variables internes:
#    $@ -> nom cible
#    $< -> nom premiere dependance
#    $^ -> liste dependance
#    $? -> liste depandances plus recentes que cible
#    $* -> nom fichier sans suffixe
###

.PHONY: all clean fclean re

# Project name
NAME = raytracer

# Source
C_DIR = src
C_FILE = main.c
SRC = $(addprefix $(C_DIR)/, $(C_FILE))

H_DIR = -I./inc -I./minilib_macos
INC = inc/raytracer.h

# Obj directory
O_DIR = obj

O_FILE = $(C_FILE:.c=.o)
OBJ = $(addprefix $(O_DIR)/, $(O_FILE))

# C compiler
CC = gcc

# C flags
FLAGS = -Wall -Wextra -Werror

# Lib
LIB = minilibx_macos/libmlx.a
LIB_LINK = -L./minilibx_macos/ -lmlx

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ) $(FLAGS)

$(O_DIR)/%.o : $(C_DIR)/%.c $(INC) | $(O_DIR)
	$(CC) $(FLAGS) $(H_DIR) -c $< -o $@

$(O_DIR):
	mkdir -p $(O_DIR)

$(LIB):
	make -C minilibx_macos

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C minilibx_macos

re: fclean all
