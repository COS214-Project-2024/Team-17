#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue {

private:
	int head;
	int tail;
	int size;
	int capacity;
	Vertex data[];

public:
	MyQueue(int capacity);

	void add(Vertex v);

	Vertex poll();

	boolean isEmpty();
};

#endif
