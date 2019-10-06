#include<iostream>
#include<string>
using namespace std;

//자료구조 Array 실습코딩.
//STL을 사용 못해서 이렇게 해야한다.
//몇몇 오류들이 발생할 수도 있다.


class Array {
public:
	int n;
	int* arr;

	Array(int size)
	{
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0;i < size;i++)
		{
			arr[i] = 0;
		}
	}

	int at(int idx)
	{
		if (arr[idx] == 0)
		{
			return 0;
		}
		else
		{
			return arr[idx];
		}
	}

	void set(int idx, int X)
	{
		if (arr[idx]!=0)
		{
			arr[idx] = X;
		}
		else
		{
			cout << 0 << endl;
		}
	}

	void add(int idx, int num)
	{
		if (arr[idx] == 0)
		{
			arr[idx] = num;
		}
		else
		{
			int temp = arr[idx];
			int temp2;
			arr[idx] = num;
			for (int i = idx;arr[i]!=0;i++)
			{
				temp2 = arr[i + 1];
				arr[i + 1] = temp;
				temp = temp2;
			}
		}
	}

	int remove(int idx)
	{
		if (arr[idx] == 0)
		{
			return 0;
		}
		else
		{
			int temp = arr[idx];
			for (int i = idx;arr[i] != 0;i++)
			{
				arr[i] = arr[i + 1];
			}
			return temp;
		}
	}

	void printArray()
	{
		if (arr[0] == 0)
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			for (int i = 0;arr[i] != 0;i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Array nums = Array(10001);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "at")
		{
			int temp2;
			cin >> temp2;
			cout<< nums.at(temp2) << endl;
		}
		else if (temp == "add")
		{
			int temp2, temp3;
			cin >> temp2 >> temp3;
			nums.add(temp2, temp3);
		}
		else if (temp == "set")
		{
			int temp2, temp3;
			cin >> temp2 >> temp3;
			nums.set(temp2, temp3);
		}
		else if (temp == "remove")
		{
			int temp2;
			cin >> temp2;
			cout<< nums.remove(temp2) << endl;
		}
		else if (temp == "printArray")
		{
			nums.printArray();
		}
	}
}