#def关键字是用来定义函数功能的,要定义一个函数
#就应该有def关键字在函数名前面
def hs():
    print("你好,这个是我的第一个py函数")


hs()


#带参数的函数
def hs1(name_1, name_2):
    print(f"Hi {name_1} {name_2}")
    print(name_2)


hs1("你好", "fuck you")


#带参数并且return返回值的函数
def hs2(num1, num2):
    return num1 + num2


print(hs2(25, 25))
#↓可以在参数中加上<虚参名>+<=>提高代码的阅读性
print(hs2(num1=30, num2=24))


#↓这里定义函数的时候参数栏里给num2给予了一个默认值,
#这样的作用是可以允许调用者使用此函数只代入一个参值
def hs3(num1, num2=5):
    return num1 + num2


print(hs3(21))
print(hs3(21, 22))


#参数值里带集合,*号表示:(数据类型：元组)
def hs4(*sum):
    print(sum)


hs4(2, 3, 5, 7)


#↑可以利用这点实现乘积的功能
def hs5(*sum):
    total = 1  #乘积数
    for numb in sum:
        total *= numb
    return total


print(hs5(3, 5, 7, 6))  #3*5*7*6


#双**号表示:(数据类型字典),这里仅做了解
def hs6(**user):
    print(user)
    print(user["name"], user["age"])  #获取这个字典对象里存放的某个具体数据


hs6(id=1, name="jeak", age=18)
