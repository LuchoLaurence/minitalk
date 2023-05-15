CLIENT = client.c
SERVER = server.c
CLIENT_NAME = client
SERVER_NAME = server

CLIENT_B = client_bonus.c
SERVER_B = server_bonus.c
CLIENT_NAME_B = client_bonus
SERVER_NAME_B = server_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

# ******************************** MAIN PART ******************************** #

all:  ${SERVER_NAME} ${CLIENT_NAME} ${SERVER} ${CLIENT}

$(SERVER_NAME) : $(SERVER)
	$(CC) $(CFLAGS) utils.c $(SERVER) -o $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_B)
	$(CC) $(CFLAGS) utils.c $(CLIENT) -o $(CLIENT_NAME)

# ******************************** BONUS PART ******************************** #

all bonus: ${SERVER_NAME_B} ${CLIENT_NAME_B} ${SERVER_B} ${CLIENT_B}

$(SERVER_NAME_B) : $(SERVER_B)
	$(CC) $(CFLAGS) utils.c $(SERVER_B) -o $(SERVER_NAME_B)

$(CLIENT_NAME_B) : $(CLIENT_B)
	$(CC) $(CFLAGS) utils.c $(CLIENT_B) -o $(CLIENT_NAME_B)

# ********************************** RULES ********************************** #

clean:
	rm -rf

fclean: clean
	rm -rf server client
	rm -rf server_bonus client_bonus

re: fclean all

.PHONY:	all clean fclean re bonus
