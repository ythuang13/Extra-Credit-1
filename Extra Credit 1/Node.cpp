#include "Node.h"
#include <iostream>

template<typename G>
std::ostream& operator<<( std::ostream& out, const Node<G>& otherNode )
{
	out << otherNode.m_data;

	return out;
}
