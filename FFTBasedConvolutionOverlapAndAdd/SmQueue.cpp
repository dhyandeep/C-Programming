#include"SmQueue.h"
#include<iostream>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<limits.h>
#include<semaphore.h>

using namespace std;
SmQueue* SmQueue::m_Instance;
SmQueue::SmQueue()
{
	cout<<__FUNCTION__<<" entered"<<endl;
	pthread_mutexattr_t mAttr;
	pthread_mutexattr_init(&mAttr);
	pthread_mutexattr_setpshared(&mAttr,  PTHREAD_PROCESS_SHARED);
	m_shmName = "OS";
	m_fullSemName = "full";
	m_emptySemName = "empty";

	/* create the shared memory object */

	m_shmFd = shm_open(m_shmName, O_CREAT | O_RDWR, 0666);
	if ((m_shmFd == -1))
                   exit(-1);

	/* configure the size of the shared memory object */
	ftruncate(m_shmFd, SHM_SIZE+2);//for storing current front value at the end

	/* memory map the shared memory object */
	m_smPtr = (int*)mmap(0, (SHM_SIZE+2)*sizeof(int), PROT_WRITE, MAP_SHARED, m_shmFd, 0);
	m_front = &m_smPtr[SHM_SIZE];
	m_rear = &m_smPtr[SHM_SIZE+1];
	*m_front = -1;
	*m_rear = -1;
	//front = (int*)calloc(1,sizeof(int)) ;
	m_empty = sem_open(m_emptySemName, O_CREAT, 0666, SHM_SIZE);
	m_full = sem_open(m_fullSemName, O_CREAT, 0666, 0);
	pthread_mutex_init(&m_lock, &mAttr);
	if(m_smPtr)
		cout<<__FUNCTION__<<" sharedmemory queue created"<<endl;
}
SmQueue::~SmQueue()
{
	cout<<__FUNCTION__<<" entered"<<endl;
	shm_unlink("OS");
	sem_unlink("empty");
	sem_unlink("full");
	cout<<"Delete Shared mem result:"<<system("rm /dev/shm/OS")<<endl;
	cout<<"Delete full semaphore  result:"<<system("rm /dev/shm/sem.full")<<endl;
	cout<<"Delete empty semaphore result:system("<<system("rm /dev/shm/sem.empty")<<endl;
	system("rm /dev/shm/front");
	sem_destroy(m_full);
	sem_destroy(m_empty);
}
bool SmQueue::IsEmpty() const
{
	if (*m_front == -1) 
	{ 
		printf("\nQueue is Empty"); 
		return true; 
	} 
}
bool SmQueue::IsFull() const
{
	 return (*m_front == 0 && *m_rear == SHM_SIZE-1) ||
            (*m_rear == *m_front-1);
}
SmQueue* SmQueue::GetInstance()
{
	cout<<__FUNCTION__<<" entered"<<endl;
	if(m_Instance)
		return m_Instance;
	m_Instance = new SmQueue();
	return m_Instance;
}
int SmQueue::GetSize()const
{
	int totalElement = 0;
	if((*m_front != -1))
	{
		if((totalElement = *m_front - *m_rear) < 0 )
			totalElement *= (-1);
	}
	return totalElement;
}
int SmQueue::Enqueue(int newItem) 
{ 
	cout<<__FUNCTION__<<" entered"<<endl;
	m_smPtr = (int*)mmap(0, SHM_SIZE+2, PROT_WRITE, MAP_SHARED, m_shmFd, 0);
	sem_wait(m_empty);
	pthread_mutex_lock(&m_lock);	

	if (*m_front == -1) /* Insert First Element */
        	*m_front = *m_rear = 0;
    	else
	{
		++(*m_rear);
		*m_rear = *m_rear % SHM_SIZE;
	}

	m_smPtr[*m_rear] = newItem;
	
	pthread_mutex_unlock(&m_lock);
	sem_post(m_full);
	std::cout<<"inserted successfully"<<std::endl;

	return 0;
} 
int SmQueue::Dequeue(int& item) 
{ 
	cout<<__FUNCTION__<<" entered"<<endl;
	m_smPtr = (int*)mmap(0, SHM_SIZE+1, PROT_WRITE, MAP_SHARED, m_shmFd, 0);
	
	sem_wait(m_full);
	pthread_mutex_lock(&m_lock);
	item = m_smPtr[*m_front];
	if (*m_front == *m_rear) /* pop 1 Element */
		*m_front = *m_rear = -1;
	else 
	{
		++(*m_front);
		*m_front = (*m_front) % SHM_SIZE;
	}
	
	pthread_mutex_unlock(&m_lock);
	sem_post(m_empty);

	
	return GetSize();
} 
