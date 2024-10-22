#ifndef MYMAP_H
#define MYMAP_H

class MyMap {

private:
	int size;
	DynamicArray<Vertex> keys;
	DynamicArray<Object> values;

public:
	MyMap(int capacity);

	void put(Vertex key, double value);

	void put(Vertex key, Object value);

	boolean containsKey(Vertex key);

	double get(Vertex key);

	Object getObject(Vertex key);

	double getDouble(Vertex key);

	Vertex getVertex(Vertex key);
};

#endif
