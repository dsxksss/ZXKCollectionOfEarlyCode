//创建一个数组并且初始化为null
//数组(Array)在JavaScript中其实也是对象(Objects)类型
//我们这里给他加一些data(可以是任何变量类型)

let selectedColors=['red','blue'];
console.log(selectedColors);//print其Arrays内的全部内容
//可以通过它的下标索引来访问其内容
console.log(selectedColors[1]);//则显示blue

//因为JavaScript是动态语言,
//所以Arrray里的内容也可以在运行的时候发生改变
selectedColors[2]='green';
console.log(selectedColors);
//可以使用length函数来打印其对象的变量个数
console.log(selectedColors.length)//则print显示3个