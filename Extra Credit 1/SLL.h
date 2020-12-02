/*
	Huang, Yitian
	Moore, Jaden
	
	December 1, 2020

	CS A250
	Extra Credit 1
*/

#ifndef SLL_H
#define SLL_H

#include "Node.h"
#include <iostream>

template<typename T>
class SLL
{
	template<typename G>
	friend std::ostream& operator<<( std::ostream& out, const SLL<G>& otherList );

public:
	SLL() : m_first( nullptr ), m_count( 0 ) {}

	SLL<T>( const SLL<T>& copy );

	SLL<T>& operator=( const SLL<T>& otherList );

	void push( const T& element );

	T pop();

	bool find( const T& element ) const;

	void clear();

	~SLL() { clear(); }

private:
	Node<T>* m_first;
	int m_count;
};

#endif
