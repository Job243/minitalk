NAME = minitalk
CLIENT = client
SERVER = server

SRC_DIR = src
FT_PRINTF_DIR = ft_printf
INCLUDE_DIR = include

# Add utils.c to common sources
COMMON_SRC = $(SRC_DIR)/utils.c $(SRC_DIR)/utils_2.c

CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c

OBJ_DIR = obj
COMMON_OBJS = $(COMMON_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIENT_OBJS = $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(COMMON_OBJS)
SERVER_OBJS = $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(COMMON_OBJS)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

RM = rm -f
MKDIR = mkdir -p

# Build target for both client and server
all: $(OBJ_DIR) $(CLIENT) $(SERVER)

# Create object directory if it does not exist
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Build client
$(CLIENT): $(CLIENT_OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(FT_PRINTF)

# Build server
$(SERVER): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(FT_PRINTF)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build ft_printf
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Clean object files and libraries
clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(COMMON_OBJS)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Full clean (objects and binaries)
fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
