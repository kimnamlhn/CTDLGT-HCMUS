#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};

Node* newNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->pLeft = NULL;
	p->pRight = NULL;
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

void preOrder(Node* root) //root - left - right (RLR)
{
	if (root == NULL)
		return;
	cout << root->data << " "; //in root ra dau tien
	preOrder(root->pLeft);
	preOrder(root->pRight);
}


void posOrder(Node* root) // left - right - root (LRR)
{
	if (root == NULL)
		return;
	posOrder(root->pLeft);
	posOrder(root->pRight);
	cout << root->data << " ";
}

void BFS_traversal(Node *root)  
{  
    // Base Case  
    if (root == NULL) return;  
  
    // Create an empty queue for level order tarversal  
    queue<Node *> q;  
  
    // Enqueue Root and initialize height  
    q.push(root);  
  
    while (q.empty() == false)  
    {  
        // nodeCount (queue size) indicates number 
        // of nodes at current lelvel.  
        int nodeCount = q.size();  
  
        // Dequeue all nodes of current level and  
        // Enqueue all nodes of next level  
        while (nodeCount > 0) 
        {  
            Node *node = q.front();  
            cout << node->data << " ";  
            q.pop();  
            if (node->pLeft != NULL)  
                q.push(node->pLeft);
            if (node->pRight != NULL)  
                q.push(node->pRight);  
            nodeCount--;  
        }  
        cout << endl;  
    }  
}  

int main()
{
	//tạo mẫu binary tree để test
	struct Node* root = newNode(1);
	root->pLeft = newNode(2);
	root->pRight = newNode(3);
	root->pLeft->pLeft = newNode(4);
	root->pLeft->pRight = newNode(5);
	root->pRight->pLeft = newNode(6);
	root->pRight->pRight = newNode(7);

	
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


	//duyệt binary tree theo 3 thứ tự inorder, posorder và preorder
	cout << "InOrder: " << endl;
	inOrder(root);
	cout << "\nPreOrder: " << endl;
	preOrder(root);
	cout << "\nPosOrder: " << endl;
	posOrder(root);


	//duyệt cây nhị phân theo chiều rộng
	cout << "\nBFS traversal: " << endl;
	BFS_traversal(root);
	return 0;
}



