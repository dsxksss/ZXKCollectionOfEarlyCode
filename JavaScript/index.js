//javaScript代码区分大小写
//javaScript语法规范就是在代码末尾加上英文;号表示此行代码结束，但是也可以忽略不写
//因为解析器引擎会自动在每段代码末尾加上英文分号，尽管可以省略，但在一些特定语句会导致错误，
//所以还是不建议省略，javaScript不允许重复声明已有变量

      //单双引号都行
      console.log("你好！"); //向屏幕output些字符串
      console.info("info");//提示信息
      console.warn("warn");//警告信息
      console.error("error");//错误信息
      console.debug("debug\n");//调试信息
//占位符略解
      const obj={//一个对象的创建，在objects.js文件里有详细解释，这里跳过不赘述
            name:'Jack',
            age:30
      };
      
      //实测部分可以互用，javaScript语言不是强类型语言，可能是因为其动态性质导致
      console.log('%o',obj);//%o:javaScript对象、整数、字符串、以及json数据
      console.log('三个整数%d%d%i',2,5,231);//%d或%i:整数
      console.log('%s','我是字符串');//%s:字符串
      console.log('浮点%f数',2.123);//%f:浮点数

      //js也支持颜色输出
      console.log("\033[1;31mfuck you\033[32m");
      //console.clear();//清屏功能