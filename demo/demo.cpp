#include <iostream>
#include "SeqList_template.h"
#include "Stack_template.h"
#include "LinkList_template.h"
#include "Queue_template.h"

#define LOG(X) std::cout << X << std::endl

int main()
{
	using namespace VermiSTL;
	static_queue<int, 6> qu1;
	qu1.Enqueue(1);
	qu1.Enqueue(2);

	static_queue<int, 6>* qu2 = new static_queue<int, 6>(qu1);
	LOG(qu2->Capacity());
	LOG(qu2->isEmpty());
	LOG(qu2->isFull());
	LOG(qu2->Length());
	LOG(qu2->Dequeue());
	LOG(qu2->Dequeue());
}