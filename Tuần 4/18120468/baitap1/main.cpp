#include <vector>
#include <iostream>
using namespace std;

typedef struct {
	vector<int> data;
} IntStack;


// Đưa phần tử -x- vào stack
void push(IntStack& q, int x) 
{
	q.data.push_back(x);

}

// Xoá phần tử - - ra khỏi stack
int pop(IntStack& q)
{
	int temp = q.data[q.data.size()];
	q.data.pop_back();
	return temp;
}

// kiểm tra stack có rỗng
bool isempty(IntStack& q)
{
	if (q.data.empty()==true)
		return true;
	return false;
}

int main()
{

	return 0;
}

