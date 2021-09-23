//js判断

let dx=new Date();//Date类功能实例化
let hour=dx.getHours();//获取当前小时(0-23制)

if(hour<12&&hour>=6){
    console.log("上午好");
}
else if(hour>=12&&hour<19){
    console.log("下午好")
}
else{
    console.log("晚上好")
}
//如果要使用switch功能的话和c、c++语言使用方法一样，这里就不赘述了