//binary search tree

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};

Node* getNode(int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->pLeft = tmp->pRight = NULL;
	return tmp;
}

void inOrder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	inOrder(root->pLeft);
	inOrder(root->pRight);
}

Node* insert(Node* root, int key)
{
	if (root == NULL)
		return getNode(key);
	else
	{
		if (root->data > key)
			root->pLeft = insert(root->pLeft, key);
		else
			root->pRight = insert(root->pRight, key);
	}
	return root;
}

Node* Search(Node* root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->data = key)
		return root;
	if (key > root->data)
		return Search(root->pRight, key);
	else
		return Search(root->pLeft, key);
	
}
// đếm số lá có giá trị nguyên 
int getNumberOfLeaf(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->pLeft == NULL && root->pRight == NULL)
		return 1;
	else
		return getNumberOfLeaf(root->pLeft) + getNumberOfLeaf(root->pRight);
}

Node* minValueNode(Node* root)
{
	Node* current = root;
	while (current->pLeft != NULL)
	{
		current = current->pLeft;
	}
	return current;
}

void deleteNode(Node* root, int key)
{
	if (root == NULL)
		return;
	if (key > root->data)
		deleteNode(root->pRight, key);
	else if (key < root->data)
		deleteNode(root->pLeft, key);
	else
	{
		//tim ra roi
		//no child
		if (root->pLeft == NULL && root->pRight == NULL)
		{
			delete root;
			root = NULL;
		}
		//1 child
		else if (root->pLeft == NULL || root->pRight == NULL)//sai rồi, cái này bao gồm luôn TH 2 child rồi
		{
			if (root->pLeft == NULL)
			{
				root->data = root->pLeft->data;//sai ngu đây nữa nè :v
				deleteNode(root->pLeft, root->pLeft->data);
			}
			else
			{
				root->data = root->pRight->data;
				deleteNode(root->pRight, root->pRight->data);
			}
		}
		//2 child	
		else
		{
			Node* temp = minValueNode(root->pRight);
			root->data = temp->data;
			deleteNode(root->pRight, temp->data);
		}
	}

}
// cấu trúc cây nhị phân tìm kiếm 
// đếm số  lá có giá trị số nguyên
//xóa tất cả các node có data là số nguyên tố !!!

// :v 

int main()
{

	//tạo vài node test thử C1
	Node* root;
	root = getNode(1);
	insert(root, 3);
	insert(root, 4);
	insert(root, 5);
	insert(root, 6);
	insert(root, 7);
	insert(root, 8);

	//SAI vì không phải BST
	////C2
	//Node* root;
	//root = getNode(8);
	//root->pLeft = getNode(7);
	//root->pRight = getNode(9);
	//root->pLeft->pLeft = getNode(1);
	//root->pLeft->pRight = getNode(2);
	//root->pRight->pLeft = getNode(5);
	//root->pRight->pRight = getNode(4);

	cout << "Inorder: ";
	inOrder(root);

	// đếm số lá có giá trị nguyên
	int numberOfLeaf = getNumberOfLeaf(root);
	cout << "\nNumber of leaf: " << numberOfLeaf << endl;


	//delete số nguyên tố 
	deleteNode(root, 3);
	cout << "BST after deletion" << endl;
	inOrder(root);

	return 0;
}