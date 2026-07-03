#include <iostream>

template <typename T>
struct Triad
{
    T x {};
    T y {};
    T z {};
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void foo (const Triad<T>& t)
{
    std::cout << t.x << t.y << t.z;
}

int main(){

    Triad tri{" u3.4fu ", " u2.4fu ", " u44.4fu"};
    foo(tri);
    return 0;
}