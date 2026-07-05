#include <iostream>
#include <type_traits>

template<typename T, typename U>
void foo(T, U)
{
    std::cout << std::is_same_v<T, U> << '\n';
}


int main(){

    double i {1.0};
    int h{1};
    foo<int>(i,h);
    std::cin.get();
    return 0;
}