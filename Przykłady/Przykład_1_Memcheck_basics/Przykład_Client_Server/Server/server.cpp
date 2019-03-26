/**
 * Arkadiusz Kasprzak
 * Programowanie sieciowe i cyberbezpieczeństwo
 * Zadanie 1 - Serwer
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <netdb.h>

constexpr int flags = 0;

int main() {

	int sock_1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	std::cout << "socket status = " << sock_1 << std::endl;
	if (sock_1 == -1) {	
		perror("Operacja socket() nie powiodla sie.");
		exit(1);
	}


	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_port = htons(65280);

	int jeden = 1;
	setsockopt(sock_1, SOL_SOCKET, SO_REUSEADDR, &jeden, sizeof(jeden));

	int bind_status = bind(sock_1, (struct sockaddr*) &sin, sizeof(sin));
	std::cout << "bind status = " << bind_status << std::endl;
	if (bind_status != 0) {
		perror("Operacja bind() nie powiodla sie.");
		exit(1);
	}

	int listen_status = listen(sock_1, SOMAXCONN);
	std::cout << "listen status = " << listen_status << std::endl;
	if (listen_status != 0) {
		perror("Operacja listen() nie powiodla sie.");
		exit(1);
	}

	socklen_t sock_length = sizeof(sin);

	int sock_2 = accept(sock_1, (struct sockaddr*) &sin, &sock_length);
	std::cout << "accept status = " << sock_2 << std::endl;
	if (sock_2 == -1) {
		perror("Operacja accept() nie powiodla sie.");
		exit(1);
	}
	close(sock_1);

	char host_name[128] = {'\0'};
	char serv_name[128] = {'\0'};
	getnameinfo((struct sockaddr*) &sin, sizeof(sin), host_name, 128, serv_name, 128, flags);
	
	std::cout << "address = " << inet_ntoa(sin.sin_addr) << " (" << host_name << ")"
		<< " port = " << ntohs(sin.sin_port) << " protocol = " << sin.sin_family << std::endl;
	
	char message_from_client[256] = {'\0'};

	int recv_status = recv(sock_2, &message_from_client, 256, flags);
	std::cout << "recv_status = " << recv_status << std::endl;
	if (recv_status == -1) {
		perror("Operacja recv() nie powiodla sie.");
		exit(1);
	}

	std::cout << message_from_client << std::endl;

	char response_to_client[256] = "Re: ";

	strcpy(response_to_client + 4, message_from_client);

	int send_status = send(sock_2, response_to_client, 256, flags);
	std::cout << "send_status = " << send_status << std::endl;
	if (send_status == -1) {
		perror("Operacja send() nie powiodla sie.");
		exit(1);
	}

	close(sock_2);


	return 0;
}