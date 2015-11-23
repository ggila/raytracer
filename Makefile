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
C_FILE = main.c\
			read_map.c\
			matrix/add.c\
			matrix/dot.c\
			matrix/print.c\
			matrix/rot.c\
			matrix/trans.c\
			lib/ft_bzero.c
SRC = $(addprefix $(C_DIR)/, $(C_FILE))

H_DIR = -I./inc -I./minilib_macos
INC = inc/raytracer.h

MATRIX_FILE = matrix/add.c\
				matrix/dot.c\
				matrix/print.c\
				matrix/rot.c\
				matrix/test.c\
				matrix/trans.c\
				lib/ft_bzero.c

MATRIX = $(addprefix $(C_DIR)/, $(MATRIX_FILE))
# Obj directory
O_DIR = obj

O_FILE = $(C_FILE:.c=.o)
OBJ = $(addprefix $(O_DIR)/, $(O_FILE))

O_MAT_FILE = $(MATRIX_FILE:.c=.o)
OBJ_MAT = $(addprefix $(O_DIR)/, $(O_MAT_FILE))

# C compiler
CC = gcc

# C flags
FLAGS = -Wall -Wextra -Werror

# Lib
LIB = minilibx_macos/libmlx.a
LIB_LINK = -L./minilibx_macos/ -lmlx

FRAMEWORK = -framework OpenGL\
			-framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) -o $@ $(LIB_LINK) $(OBJ) $(FRAMEWORK)

mat: $(OBJ_MAT)
	$(CC) $(FLAGS) -o $@ $(OBJ_MAT)

$(O_DIR)/%.o: $(C_DIR)/%.c $(INC) | $(O_DIR)
	$(CC) $(FLAGS) $(H_DIR) -c $< -o  $@

$(O_DIR):
	mkdir -p obj/matrix obj/lib

$(LIB):
	make -C minilibx_macos

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C minilibx_macos

re: fclean all
