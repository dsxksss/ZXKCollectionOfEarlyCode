//JavaScript循环笔记
/*
for
while
do while
for in
for of
*/
//for
for(let i=0;i<=5;i++){
    if(i%2 !== 0)console.log("Hello",i);//只输出i奇数
}

//while
let i=0;
while(i<=5){
    console.log(i)
    i++
}

//do-while
let x=0;
do{
    if(x%2 !== 0)console.log("Hello",x);
    x++;
}while(x<=5);


//for-in 用来遍历一个对象的所有属性或者数组的所有元素
//更适合对象(也就是python中的字典)
const person={
    name:'Mosh',
    age:30
};
//类似于python中的遍历列表和其他数据结构
for(let sum in person){
    console.log(person);//打印的是此对象的key所以出现的是name，age
    console.log(person[sum]);//这里打印的是此对象key的value
}
const colors=['red','green','blue'];
for(let sum in colors){
    console.log(sum,colors[sum]);
}

//for-of 更适合用来遍历一个数组(python列表)
//直接把此数组的value赋值给sum里了
for(let sum of colors){
    console.log(sum);
}