#include<iostream>
using namespace std;

//이중연결리스트에 쓰일 노드.
//단일연결리스트와 차이점이있다면 1. 한방향이 아닌 양방향이며 2. 그로인한 자료에의 접근 및 파생된 다른 자료구조의 제작이 용이해진다.
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

//초기에 리스트 생성시 지정해두는 초기값.
List::List(int value)
{
	tail = head = new Node(value);
	size = 1;
}

//리스트의 Head에 Node를 추가하는 함수.
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

//리스트의 Tail에 Node를 추가하는 함수
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

//Head나 Tail이 아닌, 특정 위치에 Node를 추가하는 함수.
void List::insert(int idx, int value)
{
	if (idx<0 || idx>=size)
	{
		cout << "인덱스 범위 초과" << endl;
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

//리스트의 Head에 있는 Node를 제거하는 함수
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

//현재 위치의 Node Value를 출력하는 함수
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

//이중연결리스트를 소멸시키는 함수
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
	list->print(); //출력시 보여지는 이중연결리스트의 모습 : 6 - 5 - 4 - 3 - 1
	list->deletehead(); //앞의 Head 부분인 '6'이 제거된다.
	for (int i = 10;i <= 13;i++)
	{
		list->insertTail(i);
	}
	list->print(); //출력시 보여지는 이중연결리스트의 모습 : 5 - 4 - 3 - 1 - 10 - 11 - 12 - 13
	list->insert(6, 77);
	list->insert(1, 88); //각각 6번째, 1번째 Node의 뒷부분에 새로운 Node가 추가되어진다.
	list->print(); //출력시 보여지는 이중연결리스트의 모습 : 5 - 88 - 4 - 3 - 1 - 10 - 11 - 77 - 12 - 13
	return 0;
}