 #include <iostream>
using namespace std;

#include <fstream> //文件操作库
int main1(void)    //练习1:文件操作
{
    char data[100];
    ofstream dx;
    dx.open("C:\\dsxk\\dsxktxt.txt", ios::out | ios::ate);
    cin.getline(data, 100);
    dx << data << endl;
    dx.close();
    ifstream dx2;
    dx2.open("C:\\dsxk\\dsxktxt.txt", ios::in);
    dx2 >> data;
    cout << data << endl;
    system("pause");
    return 0;
}

#include <exception> //异常操作库
struct MyException : public exception
{
    const char *what()
        const throw()
    {
        return "c++ Exception";
    }
};
int main2(void) //练习2:异常
{
    try
    {
        throw MyException();
    }
    catch (MyException &e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        //其他的错误
    }
    system("pause");
    return 0;
}

int main3(void) //练习3:动态内存分配与释放
{
    int *p = NULL;
    p = new int[20];
    delete[] p;
    system("pause");
    return 0;
}

//练习4:模板知识
template <class T> //template的下面是什么决定了这个是什么模板;
void swapa(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}
template <class T>
class L1
{
public:
    L1(int);
    ~L1();
    L1(const L1 &);
    L1 &operator=(const L1 &);
    T &operator[](int);

private:
    T *m_elements;
    int m_size;
};
template <class T>
L1<T>::L1(int size) : m_size(size)
{
    m_elements = new T[m_size];
}
int main4(void)
{
    int a = 2, b = 3;
    swapa<int>(a, b);
    float c = 0.5, d = 10.5;
    swapa<float>(c, d);
    cout << "a=" << a << "b=" << b << endl;
    cout << "c=" << c << "d=" << d << endl;
    system("pause");
    return 0;
}

class Shape ////练习5:虚函数与纯虚函数
{
public:
    // 提供接口框架的纯虚函数
    virtual int getArea() = 0;
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};
// 派生类
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};
class Triangle : public Shape
{
public:
    int getArea()
    {
        return (width * height) / 2;
    }
};
int main5(void)
{
    Rectangle Rect;
    Triangle Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);
    // 输出对象的面积
    cout << "Total Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(7);
    // 输出对象的面积
    cout << "Total Triangle area: " << Tri.getArea() << endl;

    return 0;
}

#include <string>
class Entity //练习6:mutable关键字练习
{
private:
    string m_Name;
    mutable int m_debugCount = 0; //加上了mutable关键字的话
    //可以使这个变量或者函数在const情况下被发生改变;
public:
    const string &GetName() const
    {
        m_debugCount++;
        return m_Name;
    }
};
int main6(void)
{
    const Entity e;
    e.GetName();
    return 0;
}

static int S_a = 1;
static int S_b = 2;
int main7(void) //练习7:三元运算符
{
    if (S_a > 5)
    {
        S_b = 10;
    }
    else
    {
        S_b = 5;
    }
    //运用三元运算符操作如下
    S_b = S_a > 5 ? 10 : 5;
    //三元运算符嵌套操作如下
    S_b = S_a > 5 ? S_a > 10 ? 15 : 10 : 5;
    return 0;
}
