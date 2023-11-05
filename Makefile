SERVER = server
CLIENT = client
LIBFTDIR = ./libft
LIBFTNAME = libft.a

CFLAGS = -Wall -Werror -Wextra
CC = cc

SFILE = server.c
CFILE = client.c

all: $(LIBFTDIR)/$(LIBFTNAME) $(SERVER) $(CLIENT)

$(LIBFTDIR)/$(LIBFTNAME):
	make -C $(LIBFTDIR)

$(SERVER): $(LIBFTDIR)/$(LIBFTNAME)
	$(CC) $(CFLAGS) $(SFILE) $(LIBFTDIR)/$(LIBFTNAME) -o $(SERVER)

$(CLIENT): $(LIBFTDIR)/$(LIBFTNAME)
	$(CC) $(CFLAGS) $(CFILE) $(LIBFTDIR)/$(LIBFTNAME) -o $(CLIENT)

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(SOBJS) $(COBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(SERVER) $(CLIENT)

re: fclean all