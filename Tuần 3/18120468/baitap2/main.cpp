#include <iostream>
using namespace std;


struct node
{
	int data;
	node* next;
};


// gan head va tail la global varriable
	node* head = NULL;
	node* tail = NULL;


void createNode(int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void insert_start(int value)
{
	node* temp = new node;
	if (head == NULL)
	{
		head = tail = NULL;
	}
	temp->data = value;
	temp->next = head;
	head = temp;

}

void insert_position(int pos, int value)
{
	node* pre = new node;
	node* cur = new node;
	node* temp = new node;
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}

void display()
{
	node* temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}

int checkPosition(int index)
{
	node* p = head;
	int count = 1;
	for (; p != NULL; p = p->next)
	{
		if (p->data >= index)
			return count;
		count++;
	}
}


int main()
{
	int n;

	//tao 1 link list de test
	createNode(9);
	insert_start(7);
	insert_start(6);
	insert_start(5);
	insert_start(3);
	insert_start(2);
	insert_start(1);
	
	//show link list ra 
	display();

	//Nhap vao 1 node
	cout << endl;
	cout << "Enter your value: ";
	cin >> n;

	//chen 1 node vao link list 
	//van giu tinh sap xep cua no

	int test = checkPosition(n);
	if (n < head->data)	//n nam o dau
		insert_start(n);
	else if (n > tail->data) //n nam o cuoi
	{
		node* temp = new node;
		temp->data = n;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
	else
		insert_position(checkPosition(n), n);// n o giua
	display();


	return 0;
}