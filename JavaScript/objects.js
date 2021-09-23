/*引用类型:
objects
Array
Function*/

//创建一个对象,一个对象里面可以存在多种变量,对象也可以是const的
//javaScript里赋值{}表示此类型是一个引用对象类型
//创建了名字为dx的对象,后面调用的时候可以使用此对象调用
//赋值方法类似于python中的字典
//标识符被作为属性名是，可以是关键字或保留字
const dx={
    a:10,
    b:"Jack"
}//对应一个key一个value
console.log(dx)

//也可以通过.运算符来修改value或调用 
dx.a="Bob"
console.log(dx.a)

//也可以通过[]来修改value或调用,要加上引号表示内变量
dx["b"]=2//单双引号都可以
console.log(dx["b"])