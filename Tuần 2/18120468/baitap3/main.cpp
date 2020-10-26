#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};


void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

Node* getNode(int k)
{
	Node* p = new Node; 

	if (p == NULL)
	{
		cout << "out of memory" << endl;
		return NULL; 
	}
	p->data = k; 
	p->pNext = NULL; 
	return p; 
}


void addHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; 
	}
	else
	{
		p->pNext = l.pHead; 
		l.pHead = p; 
	}
}





void output(List l)
{
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->data << " ";
	}
}

int checkList(List l)
{
	
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p == NULL)
			return -1;
		for (Node* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->data == q->data)
				return p->data;
		}
	}
	return -1;
}
int main()
{
	List l;
	Init(l);
	int n, k;
	//Nhập vào một link list 
	cout << "Number of link list: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter data: ";
		cin >> k;
		Node* p;
		p = getNode(k);
		addHead(l, p);
	}
	
	output(l);

	//check trùng lặp (ycbt)
	cout << endl;
	cout << "Result is: " << checkList(l) << endl;


	return 0;
}