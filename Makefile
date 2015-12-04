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
		   lib/ft_strncmp.c\
		   lib/ft_memcpy.c\
		   lib/ft_float_equal.c\
		   lib/ft_errno.c\
		   lib/ft_putnbr.c

MATRIX_FILE = matrix/add.c\
				matrix/dot_mat.c\
				matrix/print.c\
				matrix/rot.c\
				matrix/trans.c

VECTOR_FILE = vector/mat_vect.c\
			  vector/new_vect.c\
			  vector/print_vect.c\
			  vector/scalar_prod.c\
			  vector/cross_prod.c

READ_FILE = read/read_scene.c\
			read/read_object.c\
			read/read_shape.c\
			read/read_number.c

OTHER_FILE = main.c\
			raytracer.c\
			check_scene.c

C_FILE = $(LIB_FILE) $(MATRIX_FILE) $(VECTOR_FILE) \
		 $(READ_FILE) $(OTHER_FILE)

SRC = $(addprefix $(C_DIR)/, $(C_FILE))

H_DIR = -I./inc -I./minilib_macos
INC = inc/raytracer.h

# Obj directory
O_DIR = obj

# Test
O_TDIR = obj/test
C_MATRIX_TEST = $(MATRIX_FILE) $(LIB_FILE)
C_VECTOR_TEST = $(VECTOR_FILE) $(LIB_FILE) matrix/print.c
C_READ_TEST = $(READ_FILE) $(LIB_FILE) vector/print_vect.c\
			  init_errno.c scene_error.c
C_LIB_TEST = $(LIB_FILE) vector/new_vect.c vector/scalar_prod.c

MATRIX = $(addprefix $(C_DIR)/, $(C_MATRIX_TEST))
VECTOR = $(addprefix $(C_DIR)/, $(C_VECTOR_TEST))
READ =  $(addprefix $(C_DIR)/, $(C_READ_TEST))
LIB =  $(addprefix $(C_DIR)/, $(C_LIB_TEST))

O_FILE = $(C_FILE:.c=.o)
OBJ = $(addprefix $(O_DIR)/, $(O_FILE))

O_MAT_FILE = $(C_MATRIX_TEST:.c=.o)
OBJ_MAT = $(addprefix $(O_DIR)/, $(O_MAT_FILE))

O_VECT_FILE = $(C_VECTOR_TEST:.c=.o)
OBJ_VECT = $(addprefix $(O_DIR)/, $(O_VECT_FILE))

O_READ_FILE = $(C_READ_TEST:.c=.o)
OBJ_READ = $(addprefix $(O_DIR)/, $(O_READ_FILE))

O_LIB_FILE = $(C_LIB_TEST:.c=.o)
OBJ_LIB = $(addprefix $(O_DIR)/, $(O_LIB_FILE))

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

mat: $(OBJ_MAT) test/test_mat.c| $(O_DIR) $(O_TDIR)
	$(CC) $(H_DIR) -c test/test_mat.c -o obj/test/test_mat.o
	$(CC) $(FLAGS) -o $@ $(OBJ_MAT) obj/test/test_mat.o

vect: $(OBJ_VECT) test/test_vect.c| $(O_DIR) $(O_TDIR)
	$(CC) $(H_DIR) -c test/test_vect.c -o obj/test/test_vect.o
	$(CC) $(FLAGS) -o $@ $(OBJ_VECT) obj/test/test_vect.o

read: $(OBJ_READ) test/test_read.c| $(O_DIR) $(O_TDIR)
	$(CC) $(H_DIR) -c test/test_read.c -o obj/test/test_read.o
	$(CC) $(FLAGS) -o $@ $(OBJ_READ) obj/test/test_read.o

lib: $(OBJ_LIB) test/test_lib.c| $(O_DIR) $(O_TDIR)
	$(CC) $(H_DIR) -c test/test_lib.c -o obj/test/test_lib.o
	$(CC) $(FLAGS) -o $@ $(OBJ_LIB) obj/test/test_lib.o

$(O_DIR)/%.o: $(C_DIR)/%.c $(INC) | $(O_DIR)
	$(CC) $(FLAGS) $(H_DIR) -c $< -o $@

$(O_DIR):
	mkdir -p obj/matrix obj/lib obj/vector obj/read

$(O_TDIR):
	mkdir -p obj/test

$(LIB):
	make -C minilibx_macos

clean:
	rm -rf $(O_DIR)
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	rm -f mat vect read lib
	make clean -C minilibx_macos

re: fclean all
