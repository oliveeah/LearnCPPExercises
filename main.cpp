#include <iostream>
#include <vector>

namespace {
    enum class StackOp
    {
        Push,
        Pop,
        Peek
    };
}

template <typename T>
auto printStack(StackOp op, const std::vector<T>& stack) -> void
{   
    switch(op)
    {
        case StackOp::Push:
            std::cout << "Push: ";
            break;
        case StackOp::Pop:
            std::cout << "Pop: ";
            break;
        case StackOp::Peek:
            std::cout << "Peek: ";
            break;
    }

    std::cout << "(Stack:";

    if(stack.empty())
    {
        std::cout << " empty";
    }
    else
    {
        for(const auto& i : stack)
        {
            std::cout << ' ' << i;
        }
    }
    std::cout << ")\n";
}

template <typename T>
auto popStack(std::vector<T>& stack) -> void
{
    if(!stack.empty())
    {
        stack.pop_back();
        printStack(StackOp::Pop, stack);
    }
}

template <typename T>
auto pushStack(std::vector<T>& stack, T val) -> void
{
    stack.push_back(val);
    printStack(StackOp::Push, stack);
}

int main() {
    std::vector<int> stack {};

    pushStack(stack, 1);
    pushStack(stack, 2);
    pushStack(stack, 3);
    popStack(stack);
    pushStack(stack, 4);
    popStack(stack);
    popStack(stack);
    popStack(stack);

    return 0;
}