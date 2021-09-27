//字符串略解

//模版字符串(web开发中较常见):
//优化前：处理大量数据的时候容易出错，代码杂乱不易观看，别人接手项目困难
// let computer={
//     system:'linux',
//     ram:'8GB',
//     cpu:'i7-7700k'
// };
// let html=
// '<h2>系统: '+computer.system+'</h2>'+
// '<p>内存: '+computer.ram+'</p>'+
// '<p>cpu: '+computer.cpu+'</p>';
// console.log(html);// ><h2>系统: linux</h2><p>内存: 8GB</p></h2><p>cpu: i7-7700k</p>

//优化后，利用了模版字符串
let computer={
    system:'linux',
    ram:'8GB',
    cpu:'i7-7700k'
};
let html=
    `<h2>系统:${computer.system}</h2>
     <p>内存:${computer.ram}</p>
     <p>cpu:${computer.cpu}</p>`;
console.log(html);
console.log(html.length);//length:返回长度
/*<h2>系统:linux</h2>
     <p>内存:8GB</p>
     <p>cpu:i7-7700k</p> */

let buff="boutcc";
console.log(buff[2]);
