#include <iostream>
#include "SeqList_template.h"
#include "Stack_template.h"
#include "LinkList_template.h"

int main()
{
	using namespace VermiSTL;
	int a[5] = { 0,1,3,3,1 };
	linkList<int> list_int(a, 5);

	int *b = list_int.getAllElements();
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << b[i];
	}
	std::cout << std::endl;

	list_int.remove(1);

	b = list_int.getAllElements();
	for (size_t i = 0; i < list_int.getLength(); i++)
	{
		std::cout << b[i];
	}

	std::cout << std::endl;

	list_int[0] = 8;

	b = list_int.getAllElements();
	for (size_t i = 0; i < list_int.getLength(); i++)
	{
		std::cout << b[i];
	}

	std::cout << std::endl;
}