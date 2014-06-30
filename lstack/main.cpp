#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stack>
#include "lstack.h"

//Тесты LStack, используется сравнение с контрольным std::stack

int main()
{
    srand(time(0));
        
    LStack<int> stack;
    std::stack<int> std_stack;              //библиотечный стек для контроля
    
    std::cout << "Calling push() and pop() randomly." << std::endl;
    //50000 рандомных вызовов push() и pop()
    //push() имеет в два раза больший шанс
    for (int i=0; i<50000; i++)
    {
        if (rand()%3 > 0)
        {
            int num = rand();
            stack.push(num);
            std_stack.push(num);
        }
        else if (!stack.empty())
        {
            if (stack.pop() != std_stack.top())
            {
                std::cout << "Unexpected pop() result at " << i << " iteration";
                return 0;
            }
            std_stack.pop();
        }
    }
    
    //Проверка идентичности содержимого двух стеков
    std::cout << "checking sizes..";
    if (stack.size() != std_stack.size())       //Сверка количества элементов
    {
        std::cout   << "wrong stack size: " << std_stack.size() << " expected, "
                    << stack.size() << " returned by size()" << std::endl;
        return 0;
    }
    std::cout << "sizes equal" << std::endl;
    std::cout << "checking content of stack..";
    while(!stack.empty())                       //Вытаскиваем все оставшиеся элементы
    {                                           //и сравниваем с образцом
        if (stack.pop() != std_stack.top())
        {
            std::cout << "Unexpected pop() result";
            return 0;
        }
        std_stack.pop();
    }
    std::cout << "content equal." << std::endl;
    std::cout << "Tests done." << std::endl;
    return 0;
}