import Mods  #导入模块包
import random  #随机数生成包
#用模块名+.方式调用,或者利用下面👇这句话(转换器),不带模块名直接调用此函数
#from Mods import kg_to_lbs#这句话类似于c++里的using namespa XXX;
Class_A = Mods.ClassA(21, 33)
Class_A.AorB(43, 55)
print(Class_A.x, "  ", Class_A.y, "\n")

print(Mods.kg_to_lbs(21), "\n")
print(Mods.lbs_to_kg(21), "\n\n")

#随机生成三个0-1之间的数
for sum in range(3):
    print(random.random())

#随机生成指定范围的整数
for sum in range(3):
    print(random.randint(1, 20))  #C1:最小值,C2:最大值

#随机选择列表中的某个内容
list_1 = ['Jack', 'Bob', 'Sarue', 20, 750]
print(random.choice(list_1))  #随机返回一个内容


class Lx1:
    def roll(self, mnx, max):
        first = random.randint(mnx, max)
        second = random.randint(mnx, max)
        return (first, second)
        #返回一个元组,可以不带括号,默认多个内容则return元组


sz = Lx1()
print(sz.roll(1, 6))
