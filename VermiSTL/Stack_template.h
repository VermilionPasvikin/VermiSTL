#pragma once
#include <cstddef>

namespace VermiSTL
{

    template<typename TYPE>
    class Stack
    {
        private:
            TYPE* stk; // ��ʾջ������

            TYPE* top; // ջ��λ��
            size_t size; // ջװ��Ԫ�صĸ���
            size_t capacity; //ջ������
        public:
            Stack(size_t Capacity):size(0), capacity(Capacity)
            {
                stk = new TYPE[capacity];
                top = stk;
            }

            Stack():size(0),capacity(0)
            {
                stk = new TYPE[capacity];
                top = stk;
            }

            Stack(const Stack& Right):size(Right.size), capacity(Right.capacity)
            {
                stk = new TYPE[capacity];
                top = stk;
                for (size_t i = 0; i < size; i++)
                {
                    stk[i] = Right.stk[i];
                    top++;
                }
            }

            ~Stack()
            {
                delete[] stk;
            }

        public:
            void push(TYPE ELement);
            TYPE pop();
            size_t getSize();
            size_t getCapicity();
    };

    template<typename TYPE>
    void Stack<TYPE>::push(TYPE ELement) {
        if (size < capacity) {
            *top = ELement;
            ++top;
            ++size;
        }
    }

    template<typename TYPE>
    TYPE Stack<TYPE>::pop() {
        if (size > 0) {
            --top;
            --size;
            return *top;
        }
    }

    template<typename TYPE>
    inline size_t Stack<TYPE>::getSize()
    {
        return size;
    }

    template<typename TYPE>
    inline size_t Stack<TYPE>::getCapicity()
    {
        return capacity;
    }
}