// Programmers: Ziv Fuchs, Kamron Gonzales
// Programmers� IDs: 1796140, 1564995

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template<typename V>
class PriorityQueue
{
	V* values;
	int cap;
	int siz = 0;
	void capacity(int);

public:
	PriorityQueue(int = 2);
	PriorityQueue(const PriorityQueue<V>&);
	~PriorityQueue() { delete[] values; }
	PriorityQueue<V>& operator=(const PriorityQueue<V>&);

	void push(const V&);
	void pop();
	V top() const { return siz == 0 ? V() : values[0]; }
	int size() const { return siz; }
	bool empty() const { return siz == 0 ? true : false; }
	void clear() { siz = 0; }
	bool deleteValue(V value);
};

template<typename V>
void PriorityQueue<V>::capacity(int cap)
{
	V* temp = new V[cap];
	int limit = (cap < this->cap ? cap : this->cap);

	for (int i = 0; i < limit; i++) temp[i] = values[i];
	for (int i = limit; i < cap; i++) temp[i] = V();

	delete[] values;
	values = temp;
	this->cap = cap;
}

template<typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
	this->cap = cap;
	values = new V[cap];
}

template<typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
	cap = original.cap;
	siz = original.siz;

	values = new V[cap];
	for (int i = 0; i < siz; i++) values[i] = original.values[i];
}

template<typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
	if (this != &original)
	{
		delete[] values;

		cap = original.cap;
		siz = original.siz;

		values = new V[cap];
		for (int i = 0; i < siz; i++) values[i] = original.values[i];
	}

	return *this;
}

template<typename V>
void PriorityQueue<V>::push(const V& value)
{
	if (siz == cap) capacity(cap * 2);
	values[siz] = value;
	int index = siz;

	while (true)
	{
		if (index == 0) break;
		int parent = (index - 1) / 2;
		if (values[index] < values[parent]) break;
		V temp = value;
		values[index] = values[parent];
		values[parent] = temp;
		index = parent;
	}
	++siz;
}

template<typename V>
void PriorityQueue<V>::pop() // avoid the hole
{
	--siz;
	int index = 0;
	while (true)
	{
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		if (leftChild >= siz) break;
		if (rightChild >= siz)
		{
			if (values[leftChild] < values[siz]) break;
			else
			{
				values[index] = values[leftChild];
				index = leftChild;
			}
		}
		else if ((values[leftChild] < values[siz]) && (values[rightChild] < values[siz])) break;
		else if (values[leftChild] < values[rightChild])
		{
			values[index] = values[rightChild];
			index = rightChild;
		}
		else
		{
			values[index] = values[leftChild];
			index = leftChild;
		}
	}
	values[index] = values[siz];
}

template<typename V>
bool PriorityQueue<V>::deleteValue(V value)
{
	bool valueFound = false;

	vector<V> preservedValues;

	for (int i = 0; i < siz; i++)
	{
		if (!(values[i] == value))
			preservedValues.push_back(values[i]);
		else valueFound = true;
	}

	clear();

	for (int i = 0; i < preservedValues.size(); i++)
		push(preservedValues[i]);

	return valueFound;
}

#endif // PRIORITYQUEUE_H
