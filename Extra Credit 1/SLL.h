#ifndef SLL_H
#define SLL_H

#include "Node.h"
#include "Node.cpp"
#include <iostream>

template<typename T>
class SLL
{
template<typename T>
friend std::ostream& operator<<(std::ostream& out, const SLL<T>& rhs);
private:
	Node<T>* m_first;
	int m_count;

public:
	SLL() : m_first(nullptr), m_count(0) {}

	SLL<T>(const SLL<T>& other);
	SLL<T>& operator=(const SLL<T>& rhs);

	void push(const T& element);
	T pop();
	bool find(const T& element) const;
	void clear();
	 
	~SLL() { clear(); }
};

#endif
