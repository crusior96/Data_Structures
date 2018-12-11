#include<iostream>
#include<string>
using namespace std;

//SingleLinkedList에 대해 기초적으로 구현해본 것.
//자료형은 String으로 정했다.

class StringNode //LinkedList를 구현하는데 쓰일 노드. 
{
private:
	string elem;	//노드 내에 있는 data
	StringNode* next;	//List가 가리키고 있는 다음 Node의 위치.

	friend class StringLinkedList;
};

class StringLinkedList
{
public :
	StringLinkedList();
	~StringLinkedList();
	bool empty() const;
	const string& front() const;
	void addFront(const string& e);
	void removeFront();
private:
	StringNode * head;
};

//LinkedList 생성자
StringLinkedList::StringLinkedList() : head(NULL)
{

}

//LinkedList 소멸자
StringLinkedList::~StringLinkedList()
{
	//LinkedList가 비어있지 않다면 앞에서부터 제거해나간다.
	while (!empty())
		removeFront();
}

bool StringLinkedList::empty() const
{
	//LinkedList가 비어있다면 head부분이 NULL값이 있을것이다.
	//head가 NULL값이라면 true, 아니면 false를 반납할 것이다.
	return head == NULL;
}

const string& StringLinkedList::front() const
{
	//LinkedList의 앞부분(head)를 반납하는 함수.
	return head->elem;
}

void StringLinkedList::addFront(const string& e)
{
	//새로운 노드 v를 만들어서 v에 string e를 저장한다.
	StringNode* v = new StringNode;
	v->elem = e;
	v->next = head; //head는 v 뒤에 오게 되고 v는 head의 값으로 대체된다.
	head = v;
}

void StringLinkedList::removeFront()
{
	//List내의 맨 뒤에 있는 노드를 제거한다.
	StringNode* old = head;
	head = old->next; //head에 old노드의 next값을 저장하고
	delete old; //old노드를 제거한다.
}

int main()
{
	StringLinkedList list1 = StringLinkedList();
	list1.addFront("hi");
	list1.addFront("hello");
	string a = list1.front();
	cout << a << endl;
	return 0;
}