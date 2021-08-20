import Mods  #导入模块包
#用模块名+.方式调用,或者利用下面👇这句话(转换器),不带模块名直接调用此函数
#from Mods import kg_to_lbs#这句话类似于c++里的using namespa XXX;
Class_A = Mods.ClassA(21, 33)
Class_A.AorB(43, 55)
print(Class_A.x, "  ", Class_A.y)

print(Mods.kg_to_lbs(21))
print(Mods.lbs_to_kg(21))
