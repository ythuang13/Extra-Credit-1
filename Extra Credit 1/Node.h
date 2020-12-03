/*
	Huang, Yitian
	Moore, Jaden

	December 1, 2020

	CS A250
	Extra Credit 1
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T>
class Node
{
	template <typename G>
	friend std::ostream& operator<<( std::ostream& out, const Node<G>& otherList );

public:
	Node() : m_data{ T{} }, m_next{ nullptr } {}

	Node( const T& newData, Node<T>* newNode ) : m_data{ newData }, m_next{ newNode } {}

	void setData( const T& newData ) { m_data = newData; }

	void setNext( Node<T>* newNode ) { m_next = newNode; }

	T getData() const { return m_data; }

	Node<T>* getNext() const { return m_next; }

	~Node() {}

private:
	T m_data;
	Node<T>* m_next;
};

#endif