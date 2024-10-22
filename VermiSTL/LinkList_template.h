#pragma once

namespace VermiSTL
{
	template<typename TYPE>
	struct node
	{
	public:
		node(TYPE Element, node* NextNode = nullptr) : element(Element), next_ptr(NextNode) {};

		TYPE element;
		node* next_ptr;
	};

	template <typename TYPE>
	class linkList
	{
	public:
		linkList() : length(0), entrance(nullptr) {}

		linkList(const linkList& OtherLinklist) : length(OtherLinklist.length)
		{
			this->entrance = new node<TYPE>(OtherLinklist.entrance->element);
			node<TYPE>* self_current_node = this->entrance;
			node<TYPE>* tem_current_node = OtherLinklist.entrance;
			for (size_t i = 0; i < length - 1; ++i)
			{
				self_current_node->next_ptr = new node<TYPE>(tem_current_node->next_ptr->element);
				self_current_node = self_current_node->next_ptr;
				tem_current_node = tem_current_node->next_ptr;
			}
		}

		linkList(TYPE* ElementArray, size_t Length) : length(Length)
		{
			this->entrance = new node<TYPE>(ElementArray[0]);
			node<TYPE>* self_current_node = this->entrance;
			for (size_t i = 0; i < length - 1; ++i)
			{
				self_current_node->next_ptr = new node<TYPE>(ElementArray[i + 1]);
				self_current_node = self_current_node->next_ptr;
			}
		}

		linkList(TYPE FirstElement) : length(1)
		{
			entrance = new node<TYPE>(FirstElement);
		}

		void push_back(TYPE Element)
		{
			if (length == 0)
			{
				entrance = new node<TYPE>(Element);
			}
			else
			{
				node<TYPE>* current_node = entrance;
				for (size_t i = 0; i < length - 1; ++i)
				{
					current_node = current_node->next_ptr;
				}

				current_node->next_ptr = new node<TYPE>(Element);
			}
			++length;
		}

		void pop_back()
		{
			node<TYPE>* current_node = entrance;
			node<TYPE>* before_deleted_node = nullptr;
			for (size_t i = 0; i < length - 1; ++i)
			{
				if (i == length - 2)
				{
					before_deleted_node = current_node->next_ptr;
				}
				current_node = current_node->next_ptr;
			}
			delete current_node;
			before_deleted_node->next_ptr = nullptr;
			--length;
		}

		TYPE getElement(size_t index)
		{
			node<TYPE>* current_node = entrance;
			for (size_t i = 0; i < index; ++i)
			{
				current_node = current_node->next_ptr;
			}

			return current_node->element;
		}

		void insert(TYPE Element, size_t index)
		{
			if (index == 0)
			{
				node<TYPE>* current_node = entrance;
				entrance = new node<TYPE>(Element);
				entrance->next_ptr = current_node;
			}
			else
			{
				node<TYPE>* current_node = entrance;
				node<TYPE>* next_node = nullptr;
				for (size_t i = 0; i < index - 1; ++i)
				{
					current_node = current_node->next_ptr;
				}
				next_node = current_node->next_ptr;
				current_node->next_ptr = new node<TYPE>(Element);
				current_node->next_ptr->next_ptr = next_node;
			}
			++length;
		}

		void remove(size_t index)
		{
			if (index == 0)
			{
				node<TYPE>* current_node = entrance;
				node<TYPE>* next_node = current_node->next_ptr;
				delete current_node;
				entrance = next_node;
			}
			else
			{
				node<TYPE>* current_node = entrance;
				node<TYPE>* next_node = nullptr;
				for (size_t i = 0; i < index - 1; ++i)
				{
					current_node = current_node->next_ptr;
				}
				next_node = current_node->next_ptr->next_ptr;

				delete current_node->next_ptr;
				current_node->next_ptr = next_node;
			}
			length--;
		}

		linkList& operator=(const linkList& OtherLinklist)
		{
			this->length = OtherLinklist.length;
			this->entrance = new node<TYPE>(OtherLinklist.entrance->element);
			node<TYPE>* self_current_node = this->entrance;
			node<TYPE>* tem_current_node = OtherLinklist.entrance;
			for (size_t i = 0; i < length - 1; ++i)
			{
				self_current_node->next_ptr = new node<TYPE>(tem_current_node->next_ptr->element);
				self_current_node = self_current_node->next_ptr;
				tem_current_node = tem_current_node->next_ptr;
			}
			return*this;
		}

		TYPE* getAllElements()
		{
			TYPE* element_array = new TYPE[length];

			node<TYPE>* current_node = entrance;
			for (size_t i = 0; i < length - 1; ++i)
			{
				element_array[i] = current_node->element;
				current_node = current_node->next_ptr;
			}
			element_array[length - 1] = current_node->element;

			return element_array;
		}

		node<TYPE>** getAllNode()
		{
			node<TYPE>** node_ptr_array = new node<TYPE>*[length];

			node<TYPE>* current_node = entrance;
			for (size_t i = 0; i < length - 1; ++i)
			{
				node_ptr_array[i] = current_node;
				current_node = current_node->next_ptr;
			}
			node_ptr_array[length - 1] = current_node;

			return node_ptr_array;
		}

		TYPE operator[](size_t index)
		{
			return getElement(index);
		}

		size_t getLength()
		{
			return length;
		}

		~linkList()
		{
			node<TYPE>** self_all_nodes = this->getAllNode();
			for (size_t i = 0; i < length; i++)
			{
				delete self_all_nodes[i];
			}
		}
	private:
		node<TYPE>* entrance;
		size_t length;
	};
}