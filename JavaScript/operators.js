//javaScript操作符:
/*
Arithmetic:算数操作符
Assignment:赋值操作符
Comparison:比较操作符
Logical:   逻辑操作符
Bitwise:   位元操作符
*/
//以下的操作都会影响原内容
//1、Arithmetic:算数操作符(代数操作符)
let x=10;
let y=3;
console.log(x+y);//这里填写的是x+y,在JavaScript中是表达式
console.log(x-y);
console.log(x*y);
console.log(x/y);
console.log(x%y);
console.log(x**y);//**表示幂运算符

console.log(++x);//自加1
console.log(x++);//先显示后自加1

console.log(--x);//自减1
console.log(x--);//先显示后自减1


//2、Assignment:赋值操作符
let x1=10;
console.log(x1+=5);//效果等同于x=x+5;
console.log(x1-=5);//效果等同于x=x-5;
console.log(x1*=5);//效果等同于x=x*5;
console.log(x1/=5);//同上
console.log(x1**=5);//同上
console.log(x1%=5);//同上

//3、Comparison:比较操作符
//Relational
let x2=1;
console.log(x2>0);
console.log(x2>=1);
console.log(x2<1);
console.log(x<=1);
//Equality
//JavaScript中相等比较符3个等于代表严格相等比较(全等于)
//实践中一般全等于使用次数较多
console.log(x===1);//必须确保符号两边的值类型及值都完全一样
console.log(x!==1);
//这种在JavaScript中表示,抽象相等比较(等价于)
console.log(x==1);//符号两边的值类型可以不相等(会auto),但是值得一样
console.log(x!=1);
//TernaryOperator(三元运算符)
let points=110;
//询问points的value是否大于10,如果大于则存放gold,如果不大于则存放silver;
let type=points>10 ? 'gold' : 'silver';

//4、Logical:   逻辑操作符
// &&逻辑与
console.log(true && true);
// ||逻辑或
console.log(true || false);
// !逻辑非
console.log(!true);

//在JavaScript中,逻辑操作符可以适用于非布尔类型
/*
如果在逻辑运算中使用了非布尔类型值,他们就会被视作为类假类型(Falsy)
undefined
null
0
''
false
NaN
以上都是类假类型
*/
console.log(false || true);
console.log(false || 'dsxk');
console.log(false || 1);
console.log(false || 1 || 2);//会采用就近原则,所以结果是1

//5、Bitwise:  位元操作符
//平常比较少见,但是用处还是有的
//权限小程序
//Read , Write ,Execute
//00000100 Read
//00000010 Write
//00000001 Execute
const readPermission=4;//00000100 Read
const writePermission=2;//00000010 Write
const executePermission=1;//00000001 Execute

let myPermission=0;
//可以使用位元运算添加权限
//去掉readPermission配合下面会显示no
myPermission= myPermission | readPermission | writePermission;
//检测是否有某个权限
let message = (myPermission & readPermission) ? 'yes':'no';
console.log(message);