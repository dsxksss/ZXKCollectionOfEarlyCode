#py的文件操作
from pathlib import Path  #导入文件搜索功能类

path = Path("newfiles/name.txt")
#print(path.exists())  #判断文件或文件夹是否存在,return(True/flase)
#path.mkdir()  #创建一个上方path的文件,
#path.rmdir()#删除上方path的文件
# glob函数记得(不能设置当前Path)
for sum in path.glob('*.py'):  #C1:搜索当前目录下的.py文件
    print(sum)  #打印当前目录下.py后缀的文件名字,也可以'*'搜索当前目录下的全部文件名

#文件读写入

#文件写
file_name = 'tist.txt'  #文件相对路径
file_w = open(file_name, 'a')  #w表示:有内容则覆盖,a表示:不删除内容在末尾追加
file_w.write("hola this is test \n")

#文件读
file_r = open(file_name)
lien = file_r.readlines()  #多次读取一行数据
lien2 = file_r.read()
print(lien, '\n')
print(lien2)