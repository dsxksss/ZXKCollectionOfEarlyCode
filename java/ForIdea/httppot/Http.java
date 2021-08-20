package httppot;

import java.net.*;
import java.io.*;

public class Http {
    //创建请求类，这个是请求类
    public static String sendurl(String geturl) throws IOException {
//设置Main的geturl的类型为string
        try {
//错误异常try
            URL url = new URL(geturl);
//new容器加一个新的URL
            URLConnection urlcon = url.openConnection();
            //创建URL连接，open打开连接
            urlcon.setAllowUserInteraction(false);
            InputStreamReader in = new InputStreamReader(url.openStream());
            //在URL打开input流
            BufferedReader buff = new BufferedReader(in);
            //读取缓冲
            while (buff.readLine() != null) {
                System.out.println(buff.readLine());
            }
            // TODO: Implement this method
        } catch (MalformedURLException ignored) {
        }
        return null;
    }
}