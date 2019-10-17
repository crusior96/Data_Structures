#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	
	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};

class SLinkedList {
public:
	Node* head;
	Node* tail;

	SLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void addFront(int X)
	{
		Node* temp = new Node(X);
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

	int removeFront() {
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

	int front() {
		if (head == NULL)
		{
			return 1;
		}
		else
		{
			return head->data;
		}
	}

	int empty() {
		if (head == NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void showList() {
		if (head == NULL)
		{
			cout << -1 << endl;
		}
		else
		{
			Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void addBack(int X) {
		Node* temp = new Node(X);
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
	}
};


int main()
{
	SLinkedList lis = SLinkedList();
	int N;
	cin >> N;
	for(int l = 0;l<N;l++)
	{
		for (int i = 0;i < 10;i++)
		{
			int temp;
			cin >> temp;
			lis.addBack(temp);
		}
		int size = 10;
		for (int i = 0;i < 3;i++)
		{
			int temp2;
			string S;
			cin >> S >> temp2;
			Node *tmp;
			temp2 = temp2 % size;
			if (temp2 == 0)
			{
				tmp = lis.head;
				lis.head = lis.head->next;
				size--;
			}
			else
			{
				Node *cur = lis.head;
				int k = temp2;
				while (--k)
				{
					cur = cur->next;
				}

				tmp = cur->next;
				cur->next = cur->next->next;
				size--;
			}
		}

		lis.showList();

		for (int i = 0;i < 7;i++)
		{
			lis.removeFront();
		}
	}
	return 0;
}