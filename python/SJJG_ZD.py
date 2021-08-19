#字典
#字典是利用一个key存一个value的一种数据结构
#不能存在相同名字的key,key会区分大小写
#value可以是任何数据类型的变量或常量
dictionary_1 = {"name": "John Smith", "age": 30, "are True": True}

print(dictionary_1["name"])  #return这个key的value
print(dictionary_1.get("NaME"))  #可以利用get方法减低代码错误率
dictionary_1["name"] = "jack"  #增加或修改字典
print(dictionary_1.get("name"))

#小练习:接收1234数字,屏幕输出对应单词
dictionary_2 = {"1": "One", "2": "Two", "3": "Three", "4": "Four"}
phone = input("Phone:")
output = ""
#这个for分割开了接收的in,从而做到连续输入也可以无误区分
for sum in phone:
    #将每个获取到的value按顺序放入output中,最后连接了一个空字符串方便区分value
    output += dictionary_2.get(sum, "默认值null") + " "
print(output)

#可以封装成函数复用:已实现在functions.py文件中
#小练习二:接收一句话,可以转换成好看的表情,也可以区分输入的多段文字词语
message = input(">:")
message2 = message.split(' ')  #利用空格区分开了一句话的多个词语
#print(message2)  #试试效果#message2是一个列表
dictionary_3 = {"Hi!": "苏小姐要天天开心喔!!!", ":)": "😄", ":(": "😞"}
output2 = ""
for sum in message2:
    #这里的get方法,其默认值设置成了自身,如果没有对应的key,默认值则返回自身
    output2 += dictionary_3.get(sum, sum) + " "
print(output2)