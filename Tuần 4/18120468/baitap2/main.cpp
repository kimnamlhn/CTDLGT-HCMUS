#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;


class ArrayQueue
{
private:
	int data[MAX_SIZE];
	int front;
	int rear;
public:
	ArrayQueue()
	{
		front = -1;
		rear = -1;
	}

	void Enqueue(int element)
	{
		if (Size() == MAX_SIZE - 1)
			cout << "ERORR !!" << endl;

		rear = ++rear % MAX_SIZE;
		data[rear] = element;


	}

	int Dequeue()
	{
		if (isEmpty() == true)
			cout << "Queue empty !!!" << endl;

		int ret = data[front];

		front = ++front % MAX_SIZE;

		return ret;
	}



	int Size()
	{
		return abs(rear - front);
	}

	bool isEmpty()
	{
		if (front == rear)
			return true;
		return false;
	}
};

int main()
{
	ArrayQueue q;

	//thêm vài điểm
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);

	//xóa vài điểm 
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();


	// hiển thị ra
	while (!q.isEmpty())
	{
		cout << q.Dequeue();
	}
}