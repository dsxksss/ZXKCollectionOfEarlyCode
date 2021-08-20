#class类
class Class1:
    #构造函数:_ _init_ _(self),切记两边是两个_!!!
    #一个类里不可以存在多个构造函数
    def __init__(self, x, y):
        #初始化对象
        #self有一点类似this语法
        self.x = x
        self.y = y

    def move(self):
        print("mova")

    def draw(self):
        print("draw")


#创建类对象
#每个对象的空间都是不同的,他们都有独自的空间
class_1 = Class1(27, 71)
class_1.move()
class_1.x = 20  #在此对象内部添加了一个变量x,如果以存在则修改值
print(class_1.x)

#构造函数使用
class_2 = Class1(27, 71)
print(class_2.x)


#类的继承,在子类后面加上括号,里面填写父类名
class Class1z(Class1):  #如果有参数添加,会自动传入至父类构造
    pass  #python不喜欢空类,这里的pass表示此类没有内容


class_3 = Class1z(47, 79)
print(class_3.x)
