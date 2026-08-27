#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

struct Student
{
  std::string name;
  int points;
};

int main()
{
std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, 
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};

auto i { std::max_element(
  arr.begin(),
   arr.end(),
   [](const Student& x, const Student& y)
   {
    return x.points < y.points;
   }
)};

std::cout << "The student with the most points is: " << i->name << " with " << i->points << " points." << std::endl;

return 0;
}

