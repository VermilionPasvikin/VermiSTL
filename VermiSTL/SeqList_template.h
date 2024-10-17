#pragma once
#include <iostream>

namespace VermiSTL
{
	template <typename TYPE>
	class vector_p
	{
	public:
		vector_p() :size(0), capacity(1)
		{
			alloc(1);
		}

		vector_p(size_t Capacity)
		{
			alloc(Capacity);
		}

		vector_p(TYPE* Array, size_t Size, size_t Capacity)
		{
			alloc(Capacity);
			if (Size <= Capacity)
			{
				for (size_t i = 0; i < Size; i++)
				{
					vector[i] = Array[i];
				}
				size = Size;
			}
			else
			{
				for (size_t i = 0; i < Capacity; i++)
				{
					vector[i] = Array[i];
				}
				size = Capacity;
			}
		}

		vector_p(const vector_p<TYPE>& Vector)
		{
			alloc(Vector.capacity);
			for (size_t i = 0; i < Vector.size; i++)
			{
				vector[i] = Vector.vector[i];
			}
			size = Vector.size;
		}

		void push_back(TYPE& Element)
		{
			size++;
			if (size > capacity)
			{
				realloc(capacity + 10);
			}
			vector[size - 1] = Element;
		}

		void pop_back()
		{
			if (size > 0)
			{
				size--;
			}
			else
			{
				return;
			}
		}

		void insert(size_t Index, TYPE Element)
		{
			size++;
			if (size > capacity)
			{
				realloc(capacity + 10);
			}

			for (size_t i = Index; i < size - 1; i++)
			{
				vector[i + 1] = vector[i];
			}

			vector[Index] = Element;
		}
		void erase(size_t Index)
		{
			if (size > 0)
			{
				for (size_t i = Index; i < size - 1; i++)
				{
					vector[i] = vector[i + 1];
				}
				size--;
			}
			else
			{
				return;
			}
		}

		void erase(size_t BeginIndex, size_t EndIndex)
		{
			BeginIndex--;
			for (size_t i = 1; i < EndIndex-BeginIndex ; i++)
			{
				vector[BeginIndex + i] = vector[EndIndex + i];
			}
			size -= EndIndex - BeginIndex;
		}

		void swap(size_t Index1, size_t Index2)
		{
			TYPE temp_store;
			temp_store = Index1;
			Index1 = Index2;
			Index2 = temp_store;
		}

		void clear()
		{
			size = 0;
		}

		vector_p& operator=(const vector_p<TYPE>& Vector)
		{
			if (capacity != Vector.capacity)
			{
				realloc(Vector.capacity);
			}
			size = Vector.size;
			for (size_t i = 0; i < size; i++)
			{
				vector[i] = Vector.vector[i];
			}
			return *this;
		}

		TYPE& operator[](size_t index)
		{
			return vector[index];
		}

		~vector_p()
		{
			delete[] vector;
		}

		size_t getSize()
		{
			return size;
		}

		size_t getCapicity()
		{
			return capacity;
		}

	private:
		TYPE* vector;
		size_t size;
		size_t capacity;

		void alloc(size_t Capacity)
		{
			capacity = Capacity;
			vector = new TYPE[capacity];
		}

		void realloc(size_t Capacity)
		{
			TYPE* temp_store = this->vector;
			this->capacity = Capacity;
			this->vector = new TYPE[capacity];

			if (size > capacity)
			{
				for (size_t i = 0; i < capacity; i++)
				{
					vector[i] = temp_store[i];
				}
				size = capacity;
			}
			else
			{
				for (size_t i = 0; i < size; i++)
				{
					vector[i] = temp_store[i];
				}
			}
			delete[] temp_store;
		};
	};

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

	template<typename TYPE>
	void removeGivenValue(vector_p<TYPE>& Vec,TYPE Value)
	{
		for (size_t i = 0; i < Vec.getSize(); i++)
		{
			(Vec[i] == Value) ? Vec.erase(i),0 : 0;
		}
	}
}