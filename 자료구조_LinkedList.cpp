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
	for (int i = 0;i < N;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "front")
		{
			cout<< lis.front() << endl;
		}
		else if (temp == "empty")
		{
			cout << lis.empty() << endl;
		}
		else if (temp == "removeFront")
		{
			cout << lis.removeFront() << endl;
		}
		else if (temp == "addFront")
		{
			int temp2;
			cin >> temp2;
			lis.addFront(temp2);
		}
		else if (temp == "showList")
		{
			lis.showList();
		}
		else if (temp == "addBack")
		{
			int temp2;
			cin >> temp2;
			lis.addBack(temp2);
		}
	}
	return 0;
}