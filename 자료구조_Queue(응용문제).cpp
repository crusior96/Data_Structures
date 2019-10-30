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
	if (r == f - 1)
	{
		return 0;
	}
	else
	{
		return Q[f];
	}
}

int arrQueue::rear() {
	if (r == f - 1)
	{
		return 0;
	}
	else
	{
		return Q[r];
	}
}

void arrQueue::enqueue(int data) {
	r = (r + 1) % capacity;
	Q[r] = data;
}

void arrQueue::dequeue() {
	if (r == f - 1)
	{
		cout << "Empty" << endl;
	}
	else
	{
		Q[f] = 0;
		f = (f + 1) % capacity;
	}
}

int main()
{
	int TC;
	cin >> TC;
	arrQueue pt1 = arrQueue(10001);
	arrQueue pt2 = arrQueue(10001);

	for (int i = 0;i < TC;i++)
	{
		int num;
		int win1 = 0;
		int win2 = 0;
		int up1 = 0;
		int up2 = 0;
		cin >> num;

		for (int j = 0;j < num;j++)
		{
			int temp;
			cin >> temp;
			pt1.enqueue(temp);
		}

		for (int j = 0;j < num;j++)
		{
			int temp;
			cin >> temp;
			pt2.enqueue(temp);
		}

		for (int j = 0;j < num;j++)
		{
			int temp1 = pt1.front() + up1;
			int temp2 = pt2.front() + up2;
			pt1.dequeue();
			pt2.dequeue();
			if (temp1 > temp2)
			{
				win1++;
				up1 = temp1 - temp2 - 1;
				up2 = 0;
			}
			else if (temp1 < temp2)
			{
				win2++;
				up1 = 0;
				up2 = temp2 - temp1 - 1;
			}
			else if (temp1 == temp2)
			{
				up1 = 0;
				up2 = 0;
			}
		}

		if (win1 > win2)
		{
			cout << 1 << endl;
		}
		else if (win1 < win2)
		{
			cout << 2 << endl;
		}
		else if (win1 == win2)
		{
			cout << 0 << endl;
		}

	}

	return 0;
}