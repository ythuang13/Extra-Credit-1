/*
	Huang, Yitian
	Moore, Jaden

	December 1, 2020

	CS A250
	Extra Credit 1
*/

#include "SLL.h"
#include <iostream>

using namespace std;

template<typename T>
SLL<T>::SLL( const SLL<T>& other )
{
	if ( other.m_count == 0 )
	{
		this->m_count = 0;
		this->m_first = nullptr;
	}
	else
	{
		this->m_count = other.m_count;
		this->m_first = new Node<T>( other.m_first->getData(), nullptr );

		if ( other.m_count > 1 )
		{
			Node<T>* tempNode = other.m_first->getNext();
			Node<T>* currentNode = this->m_first;

			while ( tempNode != nullptr )
			{
				currentNode->setNext( new Node<T>( tempNode->getData(), nullptr ) );
				currentNode = currentNode->getNext();
				tempNode = tempNode->getNext();
			}
		}
	}
}

template<typename T>
SLL<T>& SLL<T>::operator=( const SLL<T>& otherList )
{
	if ( this != &otherList )
	{
		if ( otherList.m_count == 0 )
		{
			this->clear();
		}
		else if ( this->m_count == 0 )
		{
			this->m_first = new Node<T>( otherList.m_first->getData(), nullptr );

			Node<T>* node = this->m_first;
			Node<T>* currentNode = otherList.m_first->getNext();

			while ( currentNode != nullptr )
			{
				node->setNext( new Node<T>( currentNode->getData(), nullptr ) );

				node = node->getNext();
				currentNode = currentNode->getNext();
			}
		}
		else if ( this->m_count > otherList.m_count ) // left > right
		{
			Node<T>* temp = otherList.m_first;
			Node<T>* curr = this->m_first;
			Node<T>* end = curr;

			while ( temp != nullptr )
			{
				curr->setData( temp->getData() );
				end = curr;
				temp = temp->getNext();
				curr = curr->getNext();
			}

			// Free left over Nodes.
			while ( curr != nullptr )
			{
				temp = curr;
				curr = curr->getNext();
				delete temp;
			}

			end->setNext( nullptr );
		}
		else if ( this->m_count == otherList.m_count ) // left == right
		{
			Node<T>* currentNode = otherList.m_first;
			Node<T>* tempNode = this->m_first;

			while ( currentNode != nullptr )
			{
				tempNode->setData( currentNode->getData() );

				currentNode = currentNode->getNext();
				tempNode = tempNode->getNext();
			}
		}
		else // left < right
		{
			Node<T>* rhsTemp = otherList.m_first;
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

			// Create new Nodes from remaining list.
			while ( rhsTemp != nullptr )
			{
				curr = new Node<T>( rhsTemp->getData(), nullptr );
				lhsTemp->setNext( curr );
				lhsTemp = curr;
				rhsTemp = rhsTemp->getNext();
			}
		}
	}

	this->m_count = otherList.m_count;

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
	T result = T();

	if ( this->m_count > 0 )
	{
		Node<T>* node = m_first;
		m_first = node->getNext();
		result = node->getData();
		delete node;

		--this->m_count;
	}

	return result;
}

template<typename T>
bool SLL<T>::find( const T& element ) const
{
	bool found = false;

	Node<T>* currentNode = this->m_first;

	while ( !found && currentNode != nullptr )
	{
		if ( currentNode->getData() == element )
		{
			found = true;
		}

		currentNode = currentNode->getNext();
	}

	return found;
}

template<typename G>
ostream& operator<<( ostream& out, const SLL<G>& otherList )
{
	Node<G>* currentNode = otherList.m_first;

	while ( currentNode != nullptr )
	{
		out << currentNode->getData() << " ";

		currentNode = currentNode->getNext();
	}

	return out;
}

template<typename T>
void SLL<T>::clear()
{
	if ( this->m_count > 0 )
	{
		Node<T>* currentNode = this->m_first;

		while ( currentNode != nullptr )
		{
			this->m_first = currentNode->getNext();
			delete currentNode;
			currentNode = this->m_first;
		}

		this->m_count = 0;
		this->m_first = nullptr;
	}
}
