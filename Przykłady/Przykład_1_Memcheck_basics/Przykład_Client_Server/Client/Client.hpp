#ifndef Client_hpp
#define Client_hpp

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>


class Client
{
public:

	Client() {
		createSocket();
		prepareSockAddr();
		executeConnnect();
	}

	void sendMessage(const char * message) {
		int send_status = send(mainSocket, message, strlen(message), 0); 
		std::cout << "send status = " << send_status << std::endl;
		if (send_status == -1) {
			perror("Operacja send() nie powiodla sie.");
			exit(1);
		}
	}

	void receiveResponse() {
		char resp[257] = {'\0'};
		int recv_status = recv(mainSocket, &resp, 256, 0);
		std::cout << "recv_status = " << recv_status << std::endl;
		if (recv_status == -1) {
			perror("Operacja recv() nie powiodla sie.");
			exit(1);
		}
		std::cout << resp << std::endl;
	}

	~Client() {
		close(mainSocket);
	}

private:

	void createSocket() {
		int mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		std::cout << "socket status = " << mainSocket << std::endl;
		if (mainSocket == -1) {	
			std::cout << "Operacja socket() nie powiodla sie." << std::endl;
			exit(1);
		}
	}

	void prepareSockAddr() {
		memset(&sin, 0, sizeof(sin));
		sin.sin_family = AF_INET;
		sin.sin_addr.s_addr = inet_addr("127.0.0.1");
		sin.sin_port = htons(65280);
	}

	void executeConnnect() {
		int connect_status = connect(mainSocket, (struct sockaddr*) &sin, sizeof(sin));
		std::cout << "connect status = " << connect_status << std::endl;
		if (connect_status != 0) {
			perror("Operacja connect() nie powiodla sie.");
			exit(1);
	}

	}

	int mainSocket;
	sockaddr_in sin;
};

#endif // Client_hpp