#ifndef MYSET_H
#define MYSET_H

class MySet {

private:
	int size;
	Vertex data[];

public:
	MySet(int capacity);

	void add(Vertex v);

	boolean contains(Vertex v);

	int size();
};

#endif
