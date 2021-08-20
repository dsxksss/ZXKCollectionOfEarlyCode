 #include <iostream>
using namespace std;

#include <fstream> //�ļ�������
int main1(void)    //��ϰ1:�ļ�����
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

#include <exception> //�쳣������
struct MyException : public exception
{
    const char *what()
        const throw()
    {
        return "c++ Exception";
    }
};
int main2(void) //��ϰ2:�쳣
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
        //�����Ĵ���
    }
    system("pause");
    return 0;
}

int main3(void) //��ϰ3:��̬�ڴ�������ͷ�
{
    int *p = NULL;
    p = new int[20];
    delete[] p;
    system("pause");
    return 0;
}

//��ϰ4:ģ��֪ʶ
template <class T> //template��������ʲô�����������ʲôģ��;
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

class Shape ////��ϰ5:�麯���봿�麯��
{
public:
    // �ṩ�ӿڿ�ܵĴ��麯��
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
// ������
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
    // �����������
    cout << "Total Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(7);
    // �����������
    cout << "Total Triangle area: " << Tri.getArea() << endl;

    return 0;
}

#include <string>
class Entity //��ϰ6:mutable�ؼ�����ϰ
{
private:
    string m_Name;
    mutable int m_debugCount = 0; //������mutable�ؼ��ֵĻ�
    //����ʹ����������ߺ�����const����±������ı�;
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
int main7(void) //��ϰ7:��Ԫ�����
{
    if (S_a > 5)
    {
        S_b = 10;
    }
    else
    {
        S_b = 5;
    }
    //������Ԫ�������������
    S_b = S_a > 5 ? 10 : 5;
    //��Ԫ�����Ƕ�ײ�������
    S_b = S_a > 5 ? S_a > 10 ? 15 : 10 : 5;
    return 0;
}
