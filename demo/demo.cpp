#include <iostream>
#include "SeqList_template.h"

template<typename TYPE> 
void printVector(VermiSTL::vector_p<TYPE>& Vec) //嵌套使用数据类型时不要用这个！
{
	size_t count = Vec.getSize();
	for (size_t i = 0; i < count; i++)
	{
		std::cout << Vec[i] << std::endl;
	}
	putchar('\n');
}

int main()
{
	int a[5] = {0,1,0,0,1};
	VermiSTL::vector_p<int> vecI(a, 5, 5);
	VermiSTL::printVector<int>(vecI);

	VermiSTL::removeGivenValue<int>(vecI, 1);
	VermiSTL::printVector<int>(vecI);
}