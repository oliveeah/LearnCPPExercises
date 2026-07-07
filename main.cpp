#include <iostream>

class Point3D
{
    private:
    int m_x {};
    int m_y {};
    int m_z {};

    public:
    auto print() const -> void
    {
        std::cout << "x: " << m_x
        << " y: " << m_y
        << " z: " << m_z << '\n';
    }

    auto setValues(int x, int y, int z) -> void
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    auto isEqual(const Point3D& pointPassed) const -> const bool 
    {
        return (pointPassed.m_x == m_x) && (pointPassed.m_y == m_y) && (pointPassed.m_z == m_z);
    }
};

int main(){
    Point3D point;
    point.setValues(1, 2, 3);

    Point3D point2;
    point2.setValues(4, 5, 6);

    point2.isEqual(point) ? std::cout << "Points are equal\n" : std::cout << "Points are not equal\n";

    return 0;
}