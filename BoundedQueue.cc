#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;

template<class TYPE>
class BoundedQueue
{
    public:
        BoundedQueue(int capacity);
        void enqueue(TYPE* t);
        TYPE* dequeue();
        ~BoundedQueue();
    private:
    	int capacity;//capacity
    	int tail;//point to the tail of queue
    	int head;
    	TYPE *queue;//the queue
};

void BoundedQueue::BoundedQueue(int capacity){
	queue = new (TYPE*)[capacity];
	capacity = capacity;
	tail = 0;
	head = 1;
	return;
}
void BoundedQueue::~BoundedQueue(){
	delete []queue;
}

void BoundedQueue::enqueue(TYPE* t){
	if((tail == head){//queue is full
		return;
	}
	//insert value to queue tail
	queue[tail] = t;
	tail = (tail + 1) % capacity;
	return;

}
TYPE* BoundedQueue::dequeue(){
	TYPE* t;
	if(tail==head){//empty queue
		return NULL;
	}else{
		t = queue[tail];
		tail = (tail-1) % capacity;//decrement pointer
	}
}

