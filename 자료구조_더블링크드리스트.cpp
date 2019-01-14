#include<iostream>
using namespace std;

//���߿��Ḯ��Ʈ�� ���� ���.
//���Ͽ��Ḯ��Ʈ�� ���������ִٸ� 1. �ѹ����� �ƴ� ������̸� 2. �׷����� �ڷῡ�� ���� �� �Ļ��� �ٸ� �ڷᱸ���� ������ ����������.
class Node {
	friend class List;
private:
	Node* next;
	Node* prev;
	int value;
	Node(Node* n, Node* p, int v)
	{
		next = n;
		prev = p;
		value = v;
	}
	Node(int v)
	{
		next = nullptr;
		prev = nullptr;
		value = v;
	}
};

class List {
private:
	Node* head;
	Node* tail;
	int size;
public:
	List(int);
	void insertHead(int);
	void insertTail(int);
	void insert(int, int);
	void deletehead();
	void print();
	~List();
};

//�ʱ⿡ ����Ʈ ������ �����صδ� �ʱⰪ.
List::List(int value)
{
	tail = head = new Node(value);
	size = 1;
}

//����Ʈ�� Head�� Node�� �߰��ϴ� �Լ�.
void List::insertHead(int value)
{
	Node* newNode = new Node(value);
	if (head == nullptr)
	{
		tail = head;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
	}
	head = newNode;
	size++;
}

//����Ʈ�� Tail�� Node�� �߰��ϴ� �Լ�
void List::insertTail(int value)
{
	Node* newNode = new Node(value);
	if (tail == nullptr)
	{
		head = tail;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
	}
	tail = newNode;
	size++;
}

//Head�� Tail�� �ƴ�, Ư�� ��ġ�� Node�� �߰��ϴ� �Լ�.
void List::insert(int idx, int value)
{
	if (idx<0 || idx>=size)
	{
		cout << "�ε��� ���� �ʰ�" << endl;
		return;
	}
	else if (idx == 0)
	{
		insertHead(value);
	}
	else if (idx == size - 1)
	{
		insertTail(value);
	}
	else
	{
		Node* newNode = new Node(value);
		Node* cur = head;
		int i = 0;
		while (i < idx)
		{
			cur = cur -> next;
			i++;
		}
		newNode->next = cur;
		newNode->prev = cur->prev;
		cur->prev->next = newNode;
		cur->prev = newNode;
	}
	size++;
}

//����Ʈ�� Head�� �ִ� Node�� �����ϴ� �Լ�
void List::deletehead()
{
	if (head != nullptr)
	{
		Node* remove = head;
		head = head->next;
		head->prev = nullptr;
		delete remove;
		size--;
	}
}

//���� ��ġ�� Node Value�� ����ϴ� �Լ�
void List::print()
{
	Node* cur = head;
	while (cur != nullptr)
	{
		if (cur->next == nullptr)
		{
			cout << cur->value << endl;
		}
		else
		{
			cout << cur->value << " <-> ";
		}
		cur = cur->next;
	}
}

//���߿��Ḯ��Ʈ�� �Ҹ��Ű�� �Լ�
List::~List()
{
	Node* cur = head;
	while (cur != nullptr)
	{
		deletehead();
	}
}

int main()
{
	List* list = new List(1);
	for (int i = 3;i <= 6;i++)
	{
		list->insertHead(i);
	}
	list->print(); //��½� �������� ���߿��Ḯ��Ʈ�� ��� : 6 - 5 - 4 - 3 - 1
	list->deletehead(); //���� Head �κ��� '6'�� ���ŵȴ�.
	for (int i = 10;i <= 13;i++)
	{
		list->insertTail(i);
	}
	list->print(); //��½� �������� ���߿��Ḯ��Ʈ�� ��� : 5 - 4 - 3 - 1 - 10 - 11 - 12 - 13
	list->insert(6, 77);
	list->insert(1, 88); //���� 6��°, 1��° Node�� �޺κп� ���ο� Node�� �߰��Ǿ�����.
	list->print(); //��½� �������� ���߿��Ḯ��Ʈ�� ��� : 5 - 88 - 4 - 3 - 1 - 10 - 11 - 77 - 12 - 13
	return 0;
}