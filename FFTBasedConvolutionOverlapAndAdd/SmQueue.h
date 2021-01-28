#pragma once
#include<iostream>
#include <semaphore.h>
#define SHM_SIZE 16

using namespace std;

//Singleton class Smqueue

class SmQueue
{
	int m_shmFd;
	const char* m_shmName;
	const char* m_emptySemName; 
	const char* m_fullSemName; 
	sem_t* m_empty,* m_full;
	int* m_smPtr;
	int* m_front;
	int* m_rear;
	pthread_mutex_t m_lock;
	static SmQueue* m_Instance;

	SmQueue();				//hidden ctors
	SmQueue& operator = (const SmQueue& toCpy);
	SmQueue(const SmQueue& toCpy);
public:
	~SmQueue();
	static SmQueue* GetInstance();
	bool IsEmpty() const;
	bool IsFull() const;
	int GetSize() const;
	int Enqueue(int arg);
	int Dequeue(int& item);
};

