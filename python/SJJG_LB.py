#列表
list_1 = ['John', 'Bob', 'Mosh', 'Sarah', 'Mary']
print(list_1)
print(list_1[0])  #可以直接访问列表下标,输出第一个目标

#利用列表算出列表中最大的数
list_2 = [24, 15, 347, 2, 7]
maxnum = list_2[0]
for num in list_2:
    if num > maxnum:
        maxnum = num
print(maxnum)

#创建一个二维的列表
# [
#    1,2,3
#    4,5,6
#    7,8,9
# ]
list_3x3 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(list_3x3[0][0])  #结果1
print(list_3x3[1][2])  #结果6
#第一个index表示第几组1维列表
#第二个index表示第几组1维列表中的第几个元素
#二维列表的for遍历
#注意这里的暂存sum不是存放的index而是内容
for sum_1 in list_3x3:
    for sum_2 in sum_1:
        print(sum_2)
#list函数使用说明
print(list_1)  #对比用的
list_1.append(10)  #在此列表的末尾处增加一个内容
list_1.insert(2, 547)  #插入新内容到此下标前面,C1:index,C2:内容
list_1.remove('Bob')  #删除选择内容
#list_1.clear()#删除所有内容
#list_1.pop()#删除末尾第一个内容
#list_1.sort()#按升序重新排列列表内容
#list_1.reverse()#按降序重新排列列表内容
#↑这些操作会影响原有的data(数据内容)
#list_10=list_1.copy()#拷贝数据至左项
print(list_1.index('Sarah'))  #查找选择内容的下标|
print(list_1.count(547))  #查找此列表中出现了几次此内容
#也可以使用in运算符:如print('Sarah' in list_1)
print(list_1)  #最后结果
#使用列表避免重复数值给一个新列表
list_4 = [2, 2, 4, 7, 6, 1, 6]
list_4new = []
for sum in list_4:
    if sum not in list_4new:
        list_4new.append(sum)
print(list_4new)