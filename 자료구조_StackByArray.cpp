#include<iostream>
#include<string>
using namespace std;

class arrayStack {
public:
	int* S;
	int capacity;
	int t;

	arrayStack(int capacity)
	{
		this->capacity = capacity;
		this->S = new int[capacity];
		this->t = -1;
	}

	int size()
	{
		return t + 1;
	}

	bool empty()
	{
		if (t == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int top()
	{
		if (t == -1)
		{
			return -1;
		}
		else
		{
			return S[t];
		}
	}

	void push(int e)
	{
		t++;
		S[t] = e;
	}

	int pop()
	{
		if (t == -1)
		{
			return -1;
		}
		else
		{
			int temp = S[t];
			t--;
			return temp;
		}
	}
};

int main()
{
	arrayStack arr = arrayStack(10001);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "pop")
		{
			cout << arr.pop() << endl;
		}
		else if (temp == "push")
		{
			int temp2;
			cin >> temp2;
			arr.push(temp2);
		}
		else if (temp == "top")
		{
			cout << arr.top() << endl;
		}
		else if (temp == "size")
		{
			cout << arr.size() << endl;
		}
		else if (temp == "empty")
		{
			cout << arr.empty() << endl;
		}
	}
	return 0;
}