#include "LinkedList.hpp"
#include <iostream> // std::cout, std::endl

LinkedList::LinkedList() :  m_head(nullptr) {
	std::cout << "==== Creating linked list ====" << std::endl;
}

LinkedList::~LinkedList() {
	std::cout << "==== Destroying linked list ====" << std::endl;
}

void LinkedList::addNewNode(int newValue) {
	Node * temp = m_head;
	Node * newNode = new Node();
	newNode->m_next = nullptr;
	newNode->m_value = newValue;
	if (m_head == nullptr) {
		m_head = newNode;
		return;
	}
	while (temp->m_next) {
		temp = temp->m_next;
	}
	temp->m_next = newNode;
}

void LinkedList::popBack() {
	if (m_head == nullptr) {
		return;
	}
	if (m_head->m_next == nullptr) {
		free(m_head);
		m_head = nullptr;
		return;
	}
	Node * temp = m_head;
	while (temp->m_next->m_next) {
		temp = temp->m_next;
	}
	free(temp->m_next);
	temp->m_next = nullptr;
}

void LinkedList::print() const {
	Node * temp = m_head;
	std::cout << "[ ";
	while (temp) {
		std::cout << temp->m_value << " ";
		temp = temp->m_next;
	}
	std::cout << "]" << std::endl;
}

void LinkedList::removeAll() {
	m_head = nullptr;
}
