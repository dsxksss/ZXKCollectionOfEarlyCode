#include<windows.h>
/*
_declspec(dllexport)void he()

{
	MessageBoxA(0, "QT提醒你你的电脑被劫持了！", "QT", 0);
}
*/
//第一步：把项目默认值中的配置类型改成dll动态库
//第二步：引入<windows.h>头文件
//第三步：加入关键字_declspec、(dllexport)
//第四步：更改常规中的目标文件名
//第五步：生成dll文件


//*详细请看2020.9.6日笔记内容