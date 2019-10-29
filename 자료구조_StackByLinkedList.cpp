#include<iostream>
#include<string>
using namespace std;


class Node{
public:
	int data;
	Node* next;
	Node(int e)
	{
		this->data = e;
		this->next = NULL;
	}
};

class SLinkedList {
public:
	Node*head;
	Node* tail;
	SLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	int front()
	{
		return head->data;
	}
	void addFront(int e)
	{
		Node* temp = new Node(e);
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
	int removeFront()
	{
		if (head == NULL)
		{
			return -1;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			return temp->data;
		}
	}
};

class LinkedStack {
public:
	int n;
	SLinkedList* S;

	LinkedStack()
	{
		this->S = new SLinkedList();
		this->n = 0;
	}

	int size()
	{
		return n;
	}

	bool empty()
	{
		return n == 0;
	}

	int top()
	{
		if (n == 0)
		{
			return -1;
		}
		else
		{
			return S->front();
		}
	}

	void push(int e)
	{
		++n;
		S->addFront(e);
	}

	int pop()
	{
		--n;
		return S->removeFront();
	}
};

int main()
{
	LinkedStack A = LinkedStack();
	
	for (int i = 0;i < 5;i++)
	{
		string S;
		cin >> S;
		if (S == "top")
		{
			cout << A.top() << endl;
		}
		else if (S == "empty")
		{
			cout << A.empty() << endl;
		}
		else if (S == "pop")
		{
			cout << A.pop() << endl;
		}
		else if (S == "size")
		{
			cout << A.size() << endl;
		}
		else if (S == "push")
		{
			int N;
			cin >> N;
			A.push(N);
		}
	}
	return 0;
}