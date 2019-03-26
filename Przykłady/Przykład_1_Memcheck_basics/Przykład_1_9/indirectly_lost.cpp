#include <iostream>

struct Node
{
	Node(int value) : m_next(nullptr), m_value(value) {}

	~Node() { if (m_next) delete m_next; }

	Node * m_next;
	int m_value;
};

class List 
{
public:

	List() : m_head(nullptr) {}

	void addElement(int value) {
		Node * newNode = new Node(value);
		newNode->m_next = m_head;
		m_head = newNode;
	}

	void print() const {
		Node * printed = m_head;
		while (printed) {
			std::cout << printed->m_value << " ";
			printed = printed->m_next;
		}
		std::cout << std::endl;
	}

	void empty() {
		m_head = nullptr; // error
	}

	~List() { if (m_head) delete m_head; }

private:
	Node * m_head;
};

int main() {

	List list;

	list.addElement(5);
	list.addElement(10);
	list.addElement(20);
	list.print();

	list.empty();

	return 0;
}