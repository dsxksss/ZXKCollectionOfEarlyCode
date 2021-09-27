//变量的创建
//ES6出来之前我们一般用var来创建变量,但是是有缺陷的,最好使用let来
//let表示这是一个变量,它的类型是auto的,按内容来标识其type
//建议使用驼峰命名法,变量名对大小写会敏感,支持一行多定义多赋值
let name1="Jack";
console.log(name1);


//常量的创建
//和C、C++语言一样,使用const表示此内容不可变
const name2="Bob";
console.log(name2);
var length = 16;                                  // Number 通过数字字面量赋值
var points = x * 10;                              // Number 通过表达式字面量赋值
var lastName = "Johnson";                         // String 通过字符串字面量赋值
var cars = ["Saab", "Volvo", "BMW"];              // Array  通过数组字面量赋值
var person = {firstName:"John", lastName:"Doe"};  // Object 通过对象字面量赋值