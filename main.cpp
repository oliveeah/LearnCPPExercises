#include <iostream>

struct IntPair
{
    int first {};
    int second {};

    void print()
    {
        std::cout << "Pair(" << first << "," << second << ")\n";
    }

    bool isEqual(const IntPair& intpair)
    {
        return (first == intpair.first) && (second == intpair.second);
    }
};

int main(){

    IntPair ip1 {1, 2};
    IntPair ip2 {1, 2};

    ip1.print();
    ip2.print();

    std::cout << (ip1.isEqual(ip2) ? "equal" : "not equal");

    std::cin.get();
    return 0;
}