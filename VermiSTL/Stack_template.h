#pragma once
#include <cstddef>

namespace VermiSTL
{

    template<typename TYPE>
    class stack
    {
        private:
            TYPE* stk; // 表示栈的数组

            TYPE* top; // 栈顶位置
            size_t size; // 栈装入元素的个数
            size_t capacity; //栈的容量
        public:
            stack(size_t Capacity):size(0), capacity(Capacity)
            {
                stk = new TYPE[capacity];
                top = stk;
            }

            stack():size(0),capacity(0)
            {
                stk = new TYPE[capacity];
                top = stk;
            }

            stack(const stack& Right):size(Right.size), capacity(Right.capacity)
            {
                stk = new TYPE[capacity];
                top = stk;
                for (size_t i = 0; i < size; i++)
                {
                    stk[i] = Right.stk[i];
                    top++;
                }
            }

            ~stack()
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
    void stack<TYPE>::push(TYPE ELement) {
        if (size < capacity) {
            *top = ELement;
            ++top;
            ++size;
        }
    }

    template<typename TYPE>
    TYPE stack<TYPE>::pop() {
        if (size > 0) {
            --top;
            --size;
            return *top;
        }
    }

    template<typename TYPE>
    inline size_t stack<TYPE>::getSize()
    {
        return size;
    }

    template<typename TYPE>
    inline size_t stack<TYPE>::getCapicity()
    {
        return capacity;
    }
}