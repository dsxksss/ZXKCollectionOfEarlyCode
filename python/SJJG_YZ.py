#元组
#和列表相似但是其内容不可改变
tuples_1 = (1, 3, 4, 75, 'good', 'fuck', 75)
#其方法少的可怜,只有
print(tuples_1.index('good'))  #return内容的index
print(tuples_1.count(75))  #return内容出现的次数
#如果你想获取元组里的数据做运算,最简单的方式是利用py的unpacking(解包)
x, y, z, h, c, b, i = tuples_1  #从index0至末尾的顺序来
#这种方法必须赋值全
#这个特性不仅限于元组
print(x, y, z, h, c, b, i)
