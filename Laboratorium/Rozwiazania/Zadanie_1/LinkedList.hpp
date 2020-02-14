#pragma once

class LinkedList {

public:

	LinkedList();
	~LinkedList();

	void addNewNode(int newValue);
	void popBack();
	void print() const;
	void removeAll();

private:

	struct Node {
		Node * m_next;
		int m_value;
	};

	Node * m_head;

};