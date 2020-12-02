#include "SLL.h"
#include <iostream>

template<typename T>
SLL<T>::SLL( const SLL<T>& copy )
{
	if ( copy.m_count == 0 )
	{
		this->m_count = 0;
		this->m_first = nullptr;
	}
	else
	{
		this->m_count = copy.m_count;
		this->m_first = new Node<T>( copy.m_first->getData(), nullptr );

		if ( copy.m_count > 1 )
		{
			Node<T>* temp = copy.m_first->getNext();
			Node<T>* curr = this->m_first;

			while ( temp != nullptr )
			{
				curr->setNext( new Node<T>( temp->getData(), nullptr ) );
				curr = curr->getNext();
				temp = temp->getNext();
			}
		}
	}
}

template<typename T>
SLL<T>& SLL<T>::operator=( const SLL<T>& rhs )
{
	if ( this != &rhs )
	{
		if ( rhs.m_count == 0 )
		{
			this->clear();
		}
		else if ( this->m_count == 0 )
		{
			Node<T>* rhsTemp = rhs.m_first;
			Node<T>* curr = this->m_first;
			Node<T>* lhsTemp = nullptr;

			while ( rhsTemp != nullptr )
			{
				if ( lhsTemp == nullptr )
				{
					curr = this->m_first = new Node<T>( rhsTemp->getData(), nullptr );
				}
				else
				{
					curr = new Node<T>( rhsTemp->getData(), nullptr );
					lhsTemp->setNext( curr );
				}
				lhsTemp = curr;
				rhsTemp = rhsTemp->getNext();
			}
		}
		else if ( this->m_count > rhs.m_count ) //left > right
		{
			//deep copy [0, rhs.m_count]
			Node<T>* temp = rhs.m_first;
			Node<T>* curr = this->m_first;
			Node<T>* end = curr;

			while ( temp != nullptr )
			{
				curr->setData( temp->getData() );
				end = curr;
				temp = temp->getNext();
				curr = curr->getNext();
			}

			//free rest of the nodes
			while ( curr != nullptr )
			{
				temp = curr;
				curr = curr->getNext();
				delete temp;
			}

			end->setNext( nullptr );
		}
		else if ( this->m_count == rhs.m_count ) //left == right
		{
			Node<T>* rhsTemp = rhs.m_first;
			Node<T>* curr = this->m_first;

			while ( rhsTemp != nullptr )
			{
				curr->setData( rhsTemp->getData() );
				rhsTemp = rhsTemp->getNext();
				curr = curr->getNext();
			}
		}
		else //left < right
		{
			//deep copy [0, this->m_count]
			Node<T>* rhsTemp = rhs.m_first;
			Node<T>* curr = this->m_first;

			for ( int i = 0; i < this->m_count - 1; ++i )
			{
				curr->setData( rhsTemp->getData() );
				rhsTemp = rhsTemp->getNext();
				curr = curr->getNext();
			}

			curr->setData( rhsTemp->getData() );
			rhsTemp = rhsTemp->getNext();
			Node<T>* lhsTemp = curr;

			//insert (this->m_count, rhs.m_count] into this
			while ( rhsTemp != nullptr )
			{
				curr = new Node<T>( rhsTemp->getData(), nullptr );
				lhsTemp->setNext( curr );
				lhsTemp = curr;
				rhsTemp = rhsTemp->getNext();
			}

			this->m_count = rhs.m_count;
		}
	}
	return *this;
}

template<typename T>
void SLL<T>::push( const T& element )
{
	this->m_first = new Node<T>( element, this->m_first );
	++this->m_count;
}

template<typename T>
T SLL<T>::pop()
{
	if ( this->m_count > 0 )
	{
		Node<T>* temp = m_first->getNext();
		T data = m_first->getData();
		delete m_first;
		this->m_first = temp;
		--this->m_count;
		return data;
	}
	return T();
}

template<typename T>
bool SLL<T>::find( const T& element ) const
{
	Node<T>* temp = this->m_first;
	while ( temp != nullptr )
	{
		if ( temp->getData() == element )
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

template<typename T>
std::ostream& operator<<( std::ostream& out, const SLL<T>& rhs )
{
	Node<T>* temp = rhs.m_first;
	while ( temp != nullptr )
	{
		out << temp->getData() << " ";
		temp = temp->getNext();
	}

	return out;
}

template<typename T>
void SLL<T>::clear()
{
	Node<T>* temp;
	while ( this->m_first != nullptr )
	{
		temp = this->m_first->getNext();
		delete this->m_first;
		this->m_first = temp;
	}
	this->m_first = nullptr;
	this->m_count = 0;
}


