#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};

Node* getNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->pLeft = p->pRight = NULL;
	return p;
}

void inOrder(Node* root) //left - root - right (LRR)
{
	if (root == NULL)
		return;
	inOrder(root->pLeft); //xuống dưới cuối left
	cout << root->data << " ";
	inOrder(root->pRight);
}

void insertNode()
{

}


void deletDeepest(struct Node* root,
	struct Node* d_node)
{
	queue<struct Node*> q;
	q.push(root);

	// Do level order traversal until last node 
	struct Node* temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == d_node) {
			temp = NULL;
			delete (d_node);
			return;
		}
		if (temp->pRight) {
			if (temp->pRight == d_node) {
				temp->pRight = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->pRight);
		}

		if (temp->pLeft) {
			if (temp->pLeft == d_node) {
				temp->pLeft = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->pLeft);
		}
	}
}


Node* deletion(struct Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->pLeft == NULL && root->pRight == NULL) {
		if (root->data == key)
			return NULL;
		else
			return root;
	}

	queue<struct Node*> q;
	q.push(root);

	struct Node* temp = NULL;
	struct Node* key_node = NULL;


	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->data == key)
			key_node = temp;

		if (temp->pLeft)
			q.push(temp->pLeft);

		if (temp->pRight)
			q.push(temp->pRight);
	}

	if (key_node != NULL) {
		int x = temp->data;
		deletDeepest(root, temp);
		key_node->data = x;
	}
	return root;
}

void insert(struct Node* temp, int key)
{
	queue<struct Node*> q;
	q.push(temp);


	while (!q.empty()) {
		struct Node* temp = q.front();
		q.pop();

		if (!temp->pLeft) {
			temp->pLeft = getNode(key);
			break;
		}
		else
			q.push(temp->pLeft);

		if (!temp->pRight) {
			temp->pRight = getNode(key);
			break;
		}
		else
			q.push(temp->pRight);
	}
}

int main()
{
	//tạo mẫu binary tree để test
	Node* root = getNode(1);
	root->pLeft = getNode(2);
	root->pRight = getNode(3);
	root->pLeft->pLeft = getNode(4);
	root->pLeft->pRight = getNode(5);
	root->pRight->pLeft = getNode(6);
	root->pRight->pRight = getNode(7);


	//binary tree

	 /*
			  1
		  /        \
	   2             3
	/     \          /    \
   4       5         6        7
  /  \    /    \     /  \    /    \
NULL NULL NULL NULL NULL NULL NULL NULL
*/


	//test thử xóa một node 
	cout << "Binary tree before delete: ";
	inOrder(root);
	
	int key = 5;
	deletion(root, key); //xóa số 5 trong cây
	cout << "\nBinary tree after delete: ";
	inOrder(root);


	//test thử chèn một node
	cout << "\nBinary tree before insert: ";
	inOrder(root);


	insert(root, key); //chèn số 5 vào lại
	cout << "\nBinary tree after insert: ";
	inOrder(root);


	return 0;
}