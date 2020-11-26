#include "SLL.h"
#include <iostream>

template<typename T>
SLL<T>::SLL(const SLL<T>& other)
{
	if (other.m_count == 0)
	{
		this.m_count = 0;
		this.m_first = nullptr;
	}
	else
	{
		this.m_count = other.m_count;
		this.m_first = new Node<T>(other.m_first->getData(), nullptr);

		if (other.m_count > 1)
		{
			Node<T>* temp = other.m_first->getNext();
			Node<T>* curr = this.m_first;

			while (temp != nullptr)
			{
				curr->setNext(new Node<T>(temp->getData(), nullptr));
				curr = curr->getNext();
				temp = temp->getNext();
			}
		}
	}
}

template<typename T>
SLL<T>& SLL<T>::operator=(const SLL<T>& rhs)
{
	if (this != &rhs)
	{
		if (rhs.m_count == 0)
		{
			this->clear();
		}
		else if (this->m_count > rhs.m_count) //left > right
		{
			//deep copy [0, rhs.m_count]
			Node<T>* temp = rhs.m_first;
			Node<T>* curr = this->m_first;

			while (temp != nullptr)
			{
				curr->setData(temp->getData());
				temp = temp->getNext();
				curr = curr->getNext();
			}

			//free rest of the nodes
			Node<T>* end = curr;

			while (curr != nullptr)
			{
				temp = curr;
				curr = curr->setNext();
				delete temp;
			}

			end->setNext(nullptr);
		}
		else if (this->m_count == rhs.m_count) //left == right
		{
			Node<T>* temp = rhs.m_first;
			Node<T>* curr = this->m_first;

			while (temp != nullptr)
			{
				curr->setData(temp->getData());
				temp = temp->getNext();
				curr = curr->getNext();
			}
		}
		else //left < right
		{
			this.m_count = rhs.m_count;

			//deep copy [0, this->m_count]
			Node<T>* temp = rhs.m_first;
			Node<T>* curr = this->m_first;

			this->m_first = 

			while (curr != nullptr && curr->getNext() != nullptr)
			{
				curr->setData(temp->getData());
				temp = temp->getNext();
				curr = curr->getNext();
			}

			//insert (this->m_count, rhs.m_count] into this
			while ()
		}
	}
	return *this;
}

template<typename T>
void SLL<T>::push(const T& element)
{
	this.m_first = new Node<T>(element, this.m_first);
	++this.m_count;
}

template<typename T>
T SLL<T>::pop()
{
	if (this.m_count > 0)
	{
		Node<T>* temp = m_first->getNext();
		T data = m_first->getData();
		delete m_first;
		this.m_first = temp;
		--this.m_count;
		return data;
	}
	return T();
}

template<typename T>
bool SLL<T>::find(const T& element) const
{
	Node<T>* temp = this.m_first;
	while (temp != nullptr)
	{
		if (temp->getData() == element)
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const SLL<T>& rhs)
{
	Node<T>* temp = rhs.m_first;
	while (temp != nullptr)
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
	while (this.m_first != nullptr)
	{
		temp = this.m_first->getNext();
		delete this.m_first;
		this.m_first = temp;
	}
	this.m_first = nullptr;
	this.m_count = 0;
}


