#pragma once
#include <string.h>

namespace VermiSTL
{
	template<typename TYPE,int CAPACITY>
	class  static_queue
	{
	public:
		static_queue() :length(0), capacity(CAPACITY), front_index(0), rear_index(0) {};
		
		static_queue(TYPE* _array, size_t _length) :capacity(CAPACITY), front_index(0), rear_index(0)
		{
			if (_length >= capacity)
			{
				memcpy(queue_array, _array, capacity * sizeof(TYPE)); 
				rear_index = capacity - 1;
				length = capacity;
			}
			else
			{
				memcpy(queue_array, _array, _length * sizeof(TYPE));
				rear_index = _length - 1;
				length = _length;
			}
		}

		static_queue(const static_queue& _right):capacity(CAPACITY),front_index(_right.front_index),rear_index(_right.rear_index),length(_right.length)
		{
			memcpy(queue_array, _right.queue_array, length * sizeof(TYPE));
		}

		~static_queue() {};

		void Enqueue(TYPE _element)
		{
			if (length < capacity)
			{
				queue_array[rear_index++] = _element;
				length++;
				if (rear_index == capacity)
				{
					rear_index = 0;
				}
			}
			else
			{
				throw "Exceed maximum queue length.";
			}
		}

		void Enqueue(TYPE& _element)
		{
			if (length < capacity)
			{
				queue_array[rear_index++] = _element;
				length++;
				if (rear_index == capacity)
				{
					rear_index = 0;
				}
			}
			else
			{
				throw "Exceed maximum queue length.";
			}
		}


		TYPE Dequeue()
		{
			if (length > 0)
			{
				TYPE temp = queue_array[front_index++];
				length--;
				if (front_index == capacity)
				{
					front_index = 0;
				}
				return temp;
			}
			else
			{
				throw "Dequeue from empty queue.";
			}
		}

		void clear()
		{
			if (length > 0)
			{
				length = 0;
				front_index = 0;
				rear_index = 0;
			}
		}

		bool isEmpty()
		{
			if (length == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool isFull()
		{
			if (length == capacity)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		size_t Length()
		{
			return length;
		}

		size_t Capacity()
		{
			return capacity;
		}

	private:
		TYPE queue_array[CAPACITY];
		size_t length;
		const size_t capacity;
		size_t front_index;
		size_t rear_index;
	};
}