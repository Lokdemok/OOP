#pragma once

template <class T>
class CList 
{
	struct Node
	{
		T data;
		Node *prev;
		Node *next;

		Node(const T& data)
			: data(data)
			, prev(nullptr)
			, next(nullptr)
		{
		}
	};

public:
	class CIterator 
	{
	public:
		friend CList<T>;
		CIterator(Node* node = nullptr, bool isReverse = false)
			: m_node(node)
			, m_isReverse(isReverse)
		{
		}

		const T& operator *() const
		{
			return m_node->data;
		}

		T& operator *()
		{
			return m_node->data;
		}

		CIterator operator ++()
		{
			m_node = (m_isReverse) ? m_node->prev : m_node->next;
			return *this;
		}

		CIterator operator ++(int)
		{
			CIterator it(*this);
			m_node = (m_isReverse) ? m_node->prev : m_node->next;
			return it;
		}

		CIterator operator --()
		{
			m_node = (m_isReverse) ? m_node->next : m_node->prev;
			return *this;
		}

		CIterator operator --(int)
		{
			CIterator it(*this);
			m_node = (m_isReverse) ? m_node->next : m_node->prev;
			return it;
		}

		bool operator ==(CIterator const& iter) const
		{
			return m_node == iter.m_node;
		}

		bool operator !=(CIterator const& iter) const
		{
			return m_node != iter.m_node;
		}

	private:
		Node* operator->() const
		{
			return m_node;
		}

		Node* m_node;
		bool m_isReverse;
	};

	CList()
		: m_firstNode(nullptr)
		, m_lastNode(nullptr)
		, m_size(0)
	{
	}

	~CList()
	{
		if (!IsEmpty())
		{
			Node *node;
			for (auto it = begin(); it != end();)
			{
				node = it.m_node;
				it++;
				delete node;
			}
			m_firstNode = m_lastNode = nullptr;
		}
	}

	CList(CList const& list)
	{
		CList tmp;
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			tmp.PushBack(*it);
		}
		swap(m_firstNode, tmp.m_firstNode);
		swap(m_lastNode, tmp.m_lastNode);
		m_size = tmp.m_size;
	}

	CList& operator =(CList const& other)
	{
		if (addressof(other) != this)
		{
			CList tmp(other);
			swap(m_firstNode, tmp.m_firstNode);
			swap(m_lastNode, tmp.m_lastNode);
		}
		return *this;
	}

	bool IsEmpty() const
	{
		return !m_firstNode;
	}

	size_t GetSize() const
	{
		return m_size;
	}

	CIterator begin()
	{
		return CIterator(m_firstNode, false);
	}

	const CIterator begin() const
	{
		return CIterator(m_firstNode, false);
	}

	CIterator end()
	{
		return CIterator(nullptr, false);
	}

	const CIterator end() const
	{
		return CIterator(nullptr, false);
	}

	CIterator rbegin()
	{
		return CIterator(m_lastNode, true);
	}

	const CIterator rbegin() const
	{
		return CIterator(m_lastNode, true);
	}

	CIterator rend()
	{
		return CIterator(nullptr, true);
	}

	const CIterator rend() const
	{
		return CIterator(nullptr, true);
	}

	CIterator last()
	{
		return CIterator(m_lastNode);
	}

	const CIterator last() const
	{
		return CIterator(m_lastNode);
	}

	void PushFront(const T& data)
	{
		Insert(begin(), data);
	}

	void PushBack(const T& data)
	{
		Insert(end(), data);
	}

	bool Contains(const CIterator& iter);
	void Insert(const CIterator& iter, const T& data);
	void Delete(const CIterator& iter);
		
private:
	Node *m_firstNode;
	Node *m_lastNode;
	size_t m_size;
};

template <class T>
bool CList<T>::Contains(const CIterator& iter)
{
	CIterator it;
	for (it = begin(); it != end(); ++it)
	{
		if (it == iter)
		{
			return true;
		}
	}
	return false;
}

template <class T>
void CList<T>::Insert(const CIterator& iter, const T& data)
{
	Node *newNode = new Node(data);
	if (iter == end())
	{		
		if (m_firstNode)
		{
			m_lastNode->next = newNode;
		}			
		else
		{
			m_firstNode = newNode; 
		}		
		newNode->prev = m_lastNode;	
		m_lastNode = newNode;
	}
	else if (iter == begin())
	{			
		if (m_firstNode)
		{
			m_firstNode->prev = newNode;
		}				
		else
		{
			m_lastNode = newNode;
		}
		newNode->next = m_firstNode;
		m_firstNode = newNode;
	}		
	else
	{	
		if (!Contains(iter))
		{
			return;
		}
		iter.m_node->prev->next = newNode;
		newNode->prev = iter.m_node->prev;
		newNode->next = iter.m_node;
		iter.m_node->prev = newNode;
	}
	++m_size;
}

template <class T>
void CList<T>::Delete(const CIterator& iter)
{
	if (!Contains(iter))
	{
		return;
	}
	Node *node = iter.m_node;
	if (iter == begin())
	{		
		m_firstNode = node->next;
		if (!m_firstNode)
		{
			m_lastNode = nullptr;
		}
		else
		{
			iter->next->prev = nullptr;
		}
	}
	else if (iter == last())
	{
		iter->prev->next = nullptr;
		m_lastNode = node->prev;
	}
	else
	{			
		node->prev->next = node->next;
		node->next->prev = node->prev;
	} 
	delete node;
	--m_size;
}