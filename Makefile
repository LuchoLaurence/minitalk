GCC = gcc -Wall -Wextra -Werror
HEAD = -I ./minitalk.h

NAME = server 
NAMEC = client

NAMEB = serverbonus 
NAMECB = clientbonus

SRCS_C = ./client.c ./utils.c\

SRCS_S = ./server.c ./utils.c\

SRCS_CB = ./client_bonus.c ./utils.c\

SRCS_SB = ./server_bonus.c ./utils.c\

OBJS_C = ${SRCS_C:%.c=objets/%.o}
OBJS_S = ${SRCS_S:%.c=objets/%.o}

OBJS_CB = ${SRCS_CB:%.c=objets/%.o}
OBJS_SB = ${SRCS_SB:%.c=objets/%.o}

all : ${NAME}

${NAME} : ${OBJS_S} ${OBJS_C}
	make -C libft
	$(GCC) $(HEAD)  ${OBJS_S} -o ${NAME}
	$(GCC) $(HEAD)  ${OBJS_C} -o ${NAMEC}
	@echo "Server and Client are ready! 👌"

objets/%.o : %.c
	mkdir -p objets
	$(GCC) $(HEAD) -c $< -o $@

clean :
	rm -rf objets
	@echo "clean objects 🗑️"

fclean : clean
	rm -f ${NAMEC} ${NAME}
	@echo "clean all names and objects 🗑️"

re : fclean all

bonus : ${NAMEB}

${NAMEB} : ${OBJS_SB} ${OBJS_CB}
	make -C libft
	$(GCC) $(HEAD) ${OBJS_SB} -o ${NAMEB}
	$(GCC) $(HEAD) ${OBJS_CB} -o ${NAMECB}
	@echo "Server and Client are ready! 👌"

objets/%.o : %.c
	mkdir -p objets
	$(GCC) $(HEAD) -c $< -o $@

cleanbonus :
	rm -rf objets
	@echo "clean objects BONUS 🗑️"

fcleanbonus : cleanbonus
	rm -f ${NAMECB} ${NAMEB}
	@echo "clean all names and objects BONUS 🗑️"

rebonus : fcleanbonus bonus

.PHONY: all clean fclean re
