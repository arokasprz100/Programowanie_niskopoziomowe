#include "Client.hpp"

int main() {

	Client client;
	client.sendMessage("Działa!!!");
	client.receiveResponse();

	return 0;	
}