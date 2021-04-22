#Names
NAME_1 =		checker
NAME_2 =		push_swap

#Compiler
CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror
LIBRARIES =		$(LIBFT_DIR)/$(LIBFT)
CFLAG = 		-c
OFLAG =			-o
IFLAG =			-I

#Make
MAKE = 			make -s -C
MAKE_CLEAN = 	make clean -s -C
MAKE_FCLEAN = 	make fclean -s -C

#Unzip
UNZIP =			unzip -X -o -q

#Norm
NORM =			norminette

#Shell
MKDIR =			mkdir -p
CP =			cp
RM =			rm -rf

#Directories
SOURCES_DIR =	./sources
OBJECTS_DIR =	./objcets
HEADERS_DIR =	./headers
LIBRARIES_DIR =	./libraries

LIBFT_DIR =		libraries/libft

#Libs
LIBFT =			libft.a

#Files
FILES =			operations.c \
				sorting.c \
				sorting_utils.c \
				sort_n_utils.c \
				utils.c \
				utils_2.c \

#Srcs
SRCS =			$(foreach FILE, $(FILES), $(shell find $(SOURCES_DIR) -name $(FILE)))

#Objs
OBJS =			$(patsubst $(SOURCES_DIR)/%, $(OBJECTS_DIR)/%, $(SRCS:.c=.o))

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(HEADERS_DIR) $(IFLAG) $(LIBRARIES_DIR) $(CFLAG) $(OFLAG) $@ $<

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES) checker.c $(OFLAG) $(NAME_1)
	@echo "Checker done!"

$(NAME_2): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES) push_swap.c $(OFLAG) $(NAME_2)
	@echo "Push_swap done!"

$(LIBFT):
	@$(MAKE) $(LIBFT_DIR)

norminette:
	@$(NORM) $(shell find $(SOURCES_DIR) -name *.c)
	@$(NORM) $(shell find $(HEADERS_DIR) -name *.h)
	@$(NORM) $(shell find . -name *.c)

clean:
	@$(MAKE_CLEAN) $(LIBFT_DIR)
	@$(RM) $(OBJECTS_DIR)

fclean: clean
	@$(MAKE_FCLEAN) $(LIBFT_DIR)
	@$(RM) $(NAME_1) $(NAME_2)

re: fclean all

.PHONY: all screeshot norminette clean fclean re run