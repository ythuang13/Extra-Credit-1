#include "Node.h"
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& rhs)
{
	out << rhs.m_data;
	return out;
}
