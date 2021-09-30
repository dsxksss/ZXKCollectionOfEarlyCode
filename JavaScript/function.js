//定义函数,语法:
//function关键字 + name(){}
function fcti(){
    //TODO THING
}
//这里可以使用模板来简化代码
function callName(name){
    console.log('Hello '+name);
}

function square(number){
    return number*number;
}

callName('Jack');
console.log(square(5));

//驾车检测扣分小函数
checkSpeed(20)

function checkSpeed(speed){
    const speedLimit=70;
    const kmPerPoint=5;
    if(speed < speedLimit+kmPerPoint){
        console.log("Is ok");
        return;
    }
    const points=Math.floor((speed-speedLimit)/kmPerPoint);
    if(points>=12)console.log("License suspended");//满12分吊销驾照
    else console.log("Points",points);//扣了多少分
}

//检测奇偶数小函数
showNumbers(10);
function showNumbers(limit){
    for(let i=0;i<=limit;i++){
        const message=(i%2===0)? '奇数':'偶数';
        console.log(i,message);
    }
}

//检测一个对象里面有多少个string并返回对象名称与内容
const movie={
    title:'阿凡达',
    releaseYear:2008,
    rating:9.2,
    director:'詹姆斯·卡梅隆'
};
showProperties(movie)
function showProperties(obj){
for(let key in obj){
    if(typeof obj[key]==='string')
       console.log(key,obj[key])
  }
}