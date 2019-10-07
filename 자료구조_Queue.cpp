#include<iostream>
#include<string>
using namespace std;

class arrQueue {
public:
	arrQueue(int size);
	int size();
	bool isEmpty();
	int front();
	int rear();
	void enqueue(int data);
	void dequeue();
	int* Q;
	int capacity;
	int f;	//front의 위치
	int r;	//rear의 위치
};

arrQueue::arrQueue(int size) {
	this->Q = new int[size];
	this->capacity = size;
	this->f = 0;
	this->r = -1;
}

int arrQueue::size() {
	return (r - f + 1 + capacity) % capacity;
}

bool arrQueue::isEmpty() {
	if (r == f - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int arrQueue::front() {
	if (r == f-1)
	{
		return 0;
	}
	else
	{
		return Q[f];
	}
}

int arrQueue::rear() {
	if (r==f-1)
	{
		return 0;
	}
	else
	{
		return Q[r];
	}
}

void arrQueue::enqueue(int data) {
	r = (r + 1)%capacity;
	Q[r] = data;
}

void arrQueue::dequeue() {
	if (r == f - 1)
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << Q[f] << endl;
		Q[f] = 0;
		f = (f + 1) % capacity;
	}
}

int main()
{
	arrQueue Q = arrQueue(10001);
	int cmdNum;
	cin >> cmdNum;
	while (cmdNum--) {
		string cmd;
		cin >> cmd;

		if (cmd == "enqueue")
		{
			int input;
			cin >> input;
			Q.enqueue(input);
		}
		else if (cmd == "dequeue")
		{
			Q.dequeue();
		}
		else if (cmd == "size")
		{
			cout << Q.size() << endl;
		}
		else if (cmd == "isEmpty")
		{
			cout << Q.isEmpty() << endl;
		}
		else if (cmd == "front")
		{
			if (Q.front() == 0)
			{
				cout << "Empty" << endl;
			}
			else if(Q.front()!=0)
			{
				cout << Q.front() << endl;
			}
		}
		else if (cmd == "rear")
		{
			if (Q.rear() == 0)
			{
				cout << "Empty" << endl;
			}
			else if(Q.rear()!=0)
			{
				cout << Q.rear() << endl;
			}
		}
	}

	return 0;
}