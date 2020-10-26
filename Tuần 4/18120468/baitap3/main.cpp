#include <iostream> 
using namespace std;

// node 
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkList {
	Node* head;
	LinkList()
	{
		head = NULL;
	}

	//hàm đảo ngược danh sách liên kết
	void reverse()
	{


		Node* current = head;
		Node* prev = NULL, * next = NULL;

		while (current != NULL) {

			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}


	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

int main()
{
	LinkList list ;

	//thêm vài node để test
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	list.push(5);
	

	cout << "Show link list: " << endl;
	list.print();
	
	//đảo ngược link list
	list.reverse();

	cout << "Reversed Linked list: " << endl;
	list.print();


	return 0;
}