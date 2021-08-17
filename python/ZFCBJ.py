#字符串
course = "python programming"
print(type(course))  #打印变量类型
print(len(course))  #打印字符串长度
print(course[0])  #打印字符串的第一个字
print(course[-1])  #打印字符串最后一个字
print(course[0:3])  #打印字符串前三个字
print(course[0:])  #打印字符串从零到尾的所有字
print(course[:3])  #左手值会被默认为0所以和0:3等效
print(course[:])  #和0:值等效
buffr = "abcd"
buffr2 = "efg"
print(f"{buffr}   {buffr2}")  #里面是{表达式},也可以配合len函数执行
#其实是格式化字符串的一种方式，和下面功能等效,中间的空格也会被纳入输出范围
print(buffr + buffr2)  #这个是连接了两个字符串.
#可以理解字符串变量是一个对象,类似String类对象一样带内置函数方法
print(course.upper())  #upper()函数作用是”不改变原字符串内容前提“将字符串内容转换成大写
print(course.lower())  #不改变内容将字符串内容转换成小写
print(course.title())  #不改变内容将字符串首字母变成大写
print(course.strip())  #不改变内容将字符串开头多余的空格删除
print(course.find("pro"))  #查找字符串中符合内容的字符下标,如果没有则返回-1
print(course.replace("p", "j"))  #不改变内容将字符串内容改变,右项变左项
print("pro" in course)  #查找内容是否存在于字符串中,返回ture,flase
print("pro" not in course)  #和上面相反,查找内容是否不存在于字符串中
