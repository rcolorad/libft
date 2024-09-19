# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcolorad <rcolorad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:23:53 by rcolorad          #+#    #+#              #
#    Updated: 2024/09/19 23:40:37 by rcolorad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RM = rm
RMFLAGS = -rf
CFLAGS = -Wall -Werror -Wextra -g3
AR = ar
R = r
INCLUDE = -I .

LIBFT_DIR = libft/
SRC_DIR = src/
BIN_DIR = obj/

CTYPE_DIR = ctype/
LIST_DIR = list/
STDIO_DIR = stdio/
STDLIB_DIR = stdlib/
STRING_DIR = string/

CTYPE_FILES =	ft_isalnum\
				ft_isalpha\
				ft_isascii\
				ft_isdigit\
				ft_isprint\
				ft_tolower\
				ft_toupper
								
LIST_FILES =	ft_lstadd_back\
				ft_lstadd_front\
				ft_lstclear\
				ft_lstdelone\
				ft_lstiter\
				ft_lstlast\
				ft_lstmap\
				ft_lstnew\
				ft_lstsize
			
STDIO_FILES = 	ft_putchar_fd\
				ft_putstr_fd\
				ft_putendl_fd\
				ft_putnbr_fd
				
STDLIB_FILES = 	ft_atoi\
				ft_calloc\
				ft_itoa
				
STRING_FILES = 	ft_strlen\
				ft_strncmp\
				ft_strlcpy\
				ft_strlcat\
				ft_memset\
				ft_bzero\
				ft_memcpy\
				ft_memmove\
				ft_strmapi\
				ft_striteri\
				ft_strchr\
				ft_strrchr\
				ft_memchr\
				ft_memcmp\
				ft_strnstr\
				ft_strdup\
				ft_substr\
				ft_strjoin\
				ft_split\
				ft_strtrim

FILES = $(addprefix $(CTYPE_DIR), $(CTYPE_FILES))\
		$(addprefix $(LIST_DIR), $(LIST_FILES))\
		$(addprefix $(STDIO_DIR), $(STDIO_FILES))\
		$(addprefix $(STDLIB_DIR), $(STDLIB_FILES))\
		$(addprefix $(STRING_DIR), $(STRING_FILES))
		
SRC	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ	= $(addprefix $(BIN_DIR), $(addsuffix .o, $(FILES)))

all: ${NAME}

${NAME}: ${OBJ}
	@echo "Creating library..."
	@$(AR) $(R) ${NAME} ${OBJ}
	@echo "Library created successfully!"

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "Cleaning up object files..."
	$(RM) $(RMFLAGS) $(OBJ)
	$(RM) $(RMFLAGS) $(BIN_DIR)
	@echo "Object files cleaned."

fclean: clean
	@echo "Removing library..."
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(BIN_DIR)
	@echo "Library removed."

re: fclean all

.PHONY: all clean fclean re
