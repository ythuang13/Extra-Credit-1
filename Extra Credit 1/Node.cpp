/*
	Huang, Yitian
	Moore, Jaden

	December 1, 2020

	CS A250
	Extra Credit 1
*/

#include "Node.h"
#include <iostream>

template<typename G>
std::ostream& operator<<( std::ostream& out, const Node<G>& otherNode )
{
	out << otherNode.m_data;

	return out;
}
