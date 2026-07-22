#include <iostream>
#include <vector>
#include <string_view>

class FizzBuzz {
    private:
    inline static const std::vector<int> m_fizzbuzz_divisors { 3, 5, 7, 11, 13, 17, 19 };
    inline static const std::vector<std::string_view> fizzbuzz_words { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

    public:
    FizzBuzz() = default;
    ~FizzBuzz() = default;

};

int main() {
    return 0;
}