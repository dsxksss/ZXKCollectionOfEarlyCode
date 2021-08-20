#模块
#其实可以理解为文件分离运行
#在ModOne.py文件里使用了此模块


def kg_to_lbs(weight):
    return weight * 0.45


def lbs_to_kg(weight):
    return weight / 0.45


class ClassA:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def AorB(self, a, b):
        c = a
        a = b
        b = c


#包内容:
#导入格式:      import 包名.文件名
#调用函数:      包名.文件名.函数名
#from导入格式:  from 包名.文件名 import 函数名 (,or...)