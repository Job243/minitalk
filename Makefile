NAME = minitalk
CLIENT = client
SERVER = server

SRC_DIR = src
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
INCLUDE_DIR = include

CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c

OBJ_DIR = obj
CLIENT_OBJS = $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJS = $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

RM = rm -f
MKDIR = mkdir -p

all:$(OBJ_DIR) $(CLIENT) $(SERVER)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)

$(SERVER): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	rmdir $(OBJ_DIR) 2>/dev/null || true
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C  $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
