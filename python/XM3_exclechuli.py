#-------------------------bat.1.0.00--------------------------
# 1、实现从外部的excel表格读取信息
# 2、将读取好的信息存入到一个二维列表里
# 3、将二维列表里的数据实现输入学生名字，即可查看此人全部信息
def main():
    import openpyxl as xl
    import numpy
    # TODO:名字查询功能
    # nameArraer = []  # 创建一个列表
    # for i in range(int(a)):
    #     name = input("输入查找的学生名字>")
    # print(nameArraer)
    name_list = []  # 存放学生信息
    biaoge = xl.load_workbook('database.xlsx')  # 要处理的表格路径名字
    sheet = biaoge['Sheet1']  # 表示要读取此文件的第一页表格
    cell = sheet['b2']  # 将单元格b2位置的内容存入到cell里面去
    man_size = 2
    for sum_one in range(sheet.max_row - 1):  #总共录入的学生人数
        for sum in range(2, sheet.max_column):  #一个学生的总信息个数
            my_cell = sheet.cell(man_size, sum)  # 2表示表格行,sum表示表格列
            name_list.append(my_cell.value)  #读到的数据存入到name_list里(还是一维列表DATA)
        man_size += 1  #读取完一个人信息然后自加1,继续读取下一个人信息
    name = []  #暂存一个人的全部信息
    name_list_big = []  #最后的结果,是一个二维列表
    for sum in name_list:  #读取五个数据存储一次
        name.append(sum)
        if len(name) >= 5:  #如果暂存数据达到五个之后算一个人的信息
            name_list_big.append(name)
            name = []  #达到要求之后,清空暂存数据,继续接受至无数据

    print("\n\n\n\n")
    # print(name_list_big)
    for sum in range(len(name_list_big)):
        print(name_list_big[sum])

    print(len(name_list_big))  #读取的人数
    print(len(name_list))  #读取的总数据(未进行个人归纳)


main()
