all: server client

server: tcp_server.c
	gcc -Wall -Wextra -Werror -o tcp_server tcp_server.c

client: tcp_client.c
	gcc -Wall -Wextra -Werror -o tcp_client tcp_client.c

clean:
	rm -f tcp_server tcp_client
