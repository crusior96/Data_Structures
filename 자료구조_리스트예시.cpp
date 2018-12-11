#include<iostream>
#include<string>
using namespace std;

//SingleLinkedList�� ���� ���������� �����غ� ��.
//�ڷ����� String���� ���ߴ�.

class StringNode //LinkedList�� �����ϴµ� ���� ���. 
{
private:
	string elem;	//��� ���� �ִ� data
	StringNode* next;	//List�� ����Ű�� �ִ� ���� Node�� ��ġ.

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

//LinkedList ������
StringLinkedList::StringLinkedList() : head(NULL)
{

}

//LinkedList �Ҹ���
StringLinkedList::~StringLinkedList()
{
	//LinkedList�� ������� �ʴٸ� �տ������� �����س�����.
	while (!empty())
		removeFront();
}

bool StringLinkedList::empty() const
{
	//LinkedList�� ����ִٸ� head�κ��� NULL���� �������̴�.
	//head�� NULL���̶�� true, �ƴϸ� false�� �ݳ��� ���̴�.
	return head == NULL;
}

const string& StringLinkedList::front() const
{
	//LinkedList�� �պκ�(head)�� �ݳ��ϴ� �Լ�.
	return head->elem;
}

void StringLinkedList::addFront(const string& e)
{
	//���ο� ��� v�� ���� v�� string e�� �����Ѵ�.
	StringNode* v = new StringNode;
	v->elem = e;
	v->next = head; //head�� v �ڿ� ���� �ǰ� v�� head�� ������ ��ü�ȴ�.
	head = v;
}

void StringLinkedList::removeFront()
{
	//List���� �� �ڿ� �ִ� ��带 �����Ѵ�.
	StringNode* old = head;
	head = old->next; //head�� old����� next���� �����ϰ�
	delete old; //old��带 �����Ѵ�.
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