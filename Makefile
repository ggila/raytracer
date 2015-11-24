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

LIB_FILE = lib/ft_bzero.c\
		   lib/ft_isdigit.c\
		   lib/ft_strcmp.c

MATRIX_FILE = matrix/add.c\
				matrix/dot_mat.c\
				matrix/print.c\
				matrix/rot.c\
				matrix/trans.c

VECTOR_FILE = vector/dot_vect.c\
			  vector/new_vect.c\
			  vector/vect_cpy.c\
			  vector/print_vect.c

READ_FILE = read/read_scene.c\
			read/read_object.c\
			read/read_number.c

OTHER_FILE = main.c

C_FILE = $(LIB_FILE) $(MATRIX_FILE) $(VECTOR_FILE) \
		 $(READ_FILE) $(OTHER_FILE)

C_MATRIX_TEST = $(MATRIX_FILE) $(LIB_FILE) matrix/test.c
C_VECTOR_TEST = $(VECTOR_FILE) $(LIB_FILE) matrix/print.c vector/test.c
C_READ_TEST = $(READ_FILE) $(LIB_FILE) read/test.c vector/print_vect.c

SRC = $(addprefix $(C_DIR)/, $(C_FILE))

H_DIR = -I./inc -I./minilib_macos
INC = inc/raytracer.h

MATRIX = $(addprefix $(C_DIR)/, $(C_MATRIX_TEST))
VECTOR = $(addprefix $(C_DIR)/, $(C_VECTOR_TEST))
READ =  $(addprefix $(C_DIR)/, $(C_READ_TEST))

# Obj directory
O_DIR = obj

O_FILE = $(C_FILE:.c=.o)
OBJ = $(addprefix $(O_DIR)/, $(O_FILE))

O_MAT_FILE = $(C_MATRIX_TEST:.c=.o)
OBJ_MAT = $(addprefix $(O_DIR)/, $(O_MAT_FILE))

O_VECT_FILE = $(C_VECTOR_TEST:.c=.o)
OBJ_VECT = $(addprefix $(O_DIR)/, $(O_VECT_FILE))

O_READ_FILE = $(C_READ_TEST:.c=.o)
OBJ_READ = $(addprefix $(O_DIR)/, $(O_READ_FILE))
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

vect: $(OBJ_VECT)
	$(CC) $(FLAGS) -o $@ $(OBJ_VECT)

read: $(OBJ_READ)
	$(CC) $(FLAGS) -o $@ $(OBJ_READ)

$(O_DIR)/%.o: $(C_DIR)/%.c $(INC) | $(O_DIR)
	$(CC) $(FLAGS) $(H_DIR) -c $< -o  $@

$(O_DIR):
	mkdir -p obj/matrix obj/lib obj/vector obj/read

$(LIB):
	make -C minilibx_macos

clean:
	rm -rf $(O_DIR)
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	rm -f mat vect read
	make clean -C minilibx_macos

re: fclean all
