#py的文件操作
from pathlib import Path  #导入处理文件的类

path = Path("newfiles/name.txt")
#print(path.exists())  #判断文件或文件夹是否存在,return(True/flase)
#path.mkdir()  #创建一个上方path的文件,
#path.rmdir()#删除上方path的文件
# glob函数记得(不能设置当前Path)
for sum in path.glob('*.py'):  #C1:搜索当前目录下的.py文件
    print(sum)  #打印当前目录下.py后缀的文件名字,也可以'*'搜索当前目录下的全部文件名
