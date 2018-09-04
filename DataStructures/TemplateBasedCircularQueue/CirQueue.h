
#ifndef MSG_QUEUEIMPLEMENTATION_H
#define MSG_QUEUEIMPLEMENTATION_H

#include <stdint.h>

//================================================================
//					MsgQueueImplementation
//================================================================
template <typename dType, size_t qSize> 
class MsgQueueImplementation
{
private:
	int16_t m_front, m_rear;
	dType m_QueueItems[qSize];
	
	inline bool IsEmpty();
	inline bool IsFull();
	inline int GetSize();

	MsgQueueImplementation (const MsgQueueImplementation &obj) { }  //hiding copy CTOR
	MsgQueueImplementation & operator= (const MsgQueueImplementation & obj) { return *this; } //hiding assnmnt oprtr

public:
	MsgQueueImplementation();
	~MsgQueueImplementation();

	inline bool Enqueue(const dType& NewItem);
	inline size_t Dequeue(dType& Item);

	dType* GetQueue();
};


//================================================================
//					MsgQueueImplementation Definition
//================================================================
template <typename dType, size_t qSize> 
MsgQueueImplementation <dType, qSize> ::MsgQueueImplementation() : m_front(-1) , m_rear(-1)
{
	std::cout<<"Initializing Message Queue"<<std::endl;
}

template <typename dType, size_t qSize> 
MsgQueueImplementation <dType, qSize> ::~MsgQueueImplementation()
{
	//todo
}

template <typename dType, size_t qSize> 
bool MsgQueueImplementation <dType, qSize> ::IsEmpty()
{
	return (m_front == -1);
}

template <typename dType, size_t qSize> 
bool MsgQueueImplementation <dType, qSize> ::IsFull()
{
	 return (m_front == 0 && m_rear == qSize-1) ||
            (m_rear == m_front-1);
}

template <typename dType, size_t qSize> 
bool MsgQueueImplementation <dType, qSize> ::Enqueue(const dType& newItem)
{
	if(IsFull())
	{
		std::cout<<"ERROR: Queue full"<<std::endl;
		return false;
	}
	if (m_front == -1) /* Insert First Element */
        m_front = m_rear = 0;
    else
	{
		++m_rear;
		m_rear = m_rear %   qSize;
	}

	m_QueueItems[m_rear] = newItem;
	std::cout<<"inserted successfully"<<std::endl;

	return true;
}

template <typename dType, size_t qSize> 
size_t MsgQueueImplementation <dType, qSize> ::Dequeue(dType& item)
{
	if(IsEmpty())
	{
		std::cout<<"Queue Empty"<<std::endl;
	}
	else
	{
		//std::cout<<m_QueueItems[m_front]<<std::endl;
		item = m_QueueItems[m_front];
		
		if (m_front == m_rear) /* pop 1 Element */
			m_front = m_rear = -1;
		else 
		{
			++m_front;
			m_front = m_front % qSize;
		}
		return GetSize();
	}
	return 0;
}

template <typename dType, size_t qSize> 
int MsgQueueImplementation <dType, qSize> ::GetSize()
{
	int totalElement = 0;
	if((m_front != -1))
	{
		if((totalElement = m_front - m_rear) < 0 ) 
			totalElement *= (-1);
	}
	return totalElement;
}

template <typename dType, size_t qSize> 
dType* MsgQueueImplementation <dType, qSize> ::GetQueue()
{
	return m_QueueItems;
}


#endif //#ifndef MSG_QUEUEIMPLEMENTATION_H

