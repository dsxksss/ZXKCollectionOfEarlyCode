#include <iostream>
using namespace std;

int num1(int a, int b) //面向过程
{
    return a + b;
}

class num //面向对象
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

template <typename T, typename U>//泛型编程
auto num3(T a, U b) -> decltype(a + b)
{
    return a + b;
}

//函数式编程
auto num4 = [](int a, int b) -> int
{
    return a + b;
};

int main()
{
    num num2;
    cout << num1(3, 5) << endl;
    cout << num2(3, 5) << endl;
    cout << num3(3, 5) << endl;
    cout << num4(3, 5) << endl;
    system("pause");
    return 0;
}