#try except
#如果用户输入无效值,该怎么样避免发生这种错误
try:
    a = int(input('age: '))
    income = 20000
    #假如a是0的话也会出现ZeroDivisionError错误
    risk = income / a
    print(a)
    #如果except后面没有error种类说明的话,则捕捉全部error
except ValueError or ZeroDivisionError:
    print("输入值无效!!!或不能与0整除")