#循环
for num in range(3):  #这里也可以是1,4参数,这样就不用加1运行了
    #表示从1开始到4结束,也可有第三个参数表示步长range(1,4,2)
    #num是计数器
    print("www", (num + 1) * ".")
# while True:
# print("bug")
successful = True
for number in range(3):
    print("successful")
    if successful:
        print("if successful")
        break  #跳出循环

sum = False
for num in range(3):
    print("halo", num + 1)
    if sum:
        print("sum")
        break
else:
    print("Im else")

# in 后面的东西可以是列表,字符串,range等等等、也可以是个对象
# 双循环loop
for x in range(3):
    for y in range(3):
        print(f"{x}:{y}")

# 利用循环表示字符串各项
for v in "python":
    print(v)
# 利用循环打印出列表里的各项值
for loop in [1, 54, 34, 22]:
    print(loop)
for loop1 in ["adwad", "s瓦达"]:
    print(loop1)

ifddd = 100
while ifddd > 0:
    print(ifddd)
    ifddd //= 2

# 循环接收,直至收到quit字符则结束循环(不管大小写,只要是相同字符则可以解决)
# command = ""
# while command != "quit" and command != "QUIT":
#     command = input(">:")
#     if command != "quit" and command != "QUIT":
#         print("ECHO:", command)
#     else:
#         print("Done")
# lower方法作用是不管字符里的大小写,只要是这个字符的样子则会被识别,不管是"Quit"、"QUiT"等等等
command = ""
while command.lower() != "quit":
    command = input(">:")
    if command.lower() != "quit":
        print("ECHO:", command)
    else:
        print("Done")

# 表示偶数的小程序
count = 0
for number in range(3, 100):  # 从三开始到一百之前的间值
    if number % 2 == 0:
        count += 1
        print(number)
print(f"我 们 有 {count} 个 偶 数")