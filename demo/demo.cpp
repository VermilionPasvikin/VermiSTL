#include <iostream>
#include "SeqList_template.h"
#include "Stack_template.h"

int main()
{
	int a[5] = { 0,1,3,3,1 };
	VermiSTL::Stack<int> stack_int(5);
	
	for (size_t i = 0; i < 5; i++)
	{
		stack_int.push(a[i]);
	}

	for (size_t i = 0; i < 5; i++)
	{
		stack_int.push(a[i]);
	}

	std::cout << stack_int.getSize()<<std::endl;
	stack_int.pop();
	std::cout << stack_int.getSize()<<std::endl;

	std::cout << stack_int.getCapicity()<<std::endl;

	size_t all = stack_int.getSize();
	for (size_t i = 0; i <all; i++)
	{
		std::cout<< stack_int.pop();
	}
}