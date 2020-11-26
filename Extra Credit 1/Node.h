#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T>
class Node
{
	template <typename T>
	friend std::ostream& operator<<(std::ostream& out, const Node<T>& rhs);
private:
	T m_data;
	Node<T>* m_next;

public:
	Node() : m_data(T()), m_next(nullptr) {}
	Node(const T& d, Node<T>* n) : m_data(d), m_next(n) {}

	void setData(const T& newData) { m_data = newData; }
	void setNext(Node<T>* newNode) { m_next = newNode; }
	T getData() const { return m_data; }
	Node<T>* getNext() const { return m_next; }

	~Node() {}
};

#endif