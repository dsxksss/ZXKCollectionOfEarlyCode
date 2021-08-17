#if条件判断
temperature = 35
data = 21
if temperature > 30:  #要空格表示作用域
    print("Is's warm")
    print("Drink water")
elif temperature < 30:  #else if
    print("flase")
else:  #else
    print("flase")
if data > 20 and temperature < 50:  #&&
    print("true")
if data < 20 or temperature < 50:  #||
    print("true")
if not data > 2:  #!=
    print("true")

if1 = True
if2 = False
if3 = True
if if1 and if2 or not if3:
    print("true")

#布尔运算符
age = 22
#if age>=18 and age<65:等同下行的作用
if 18 >= age < 65:  #作用相同,只是代码干净了
    print("true")
