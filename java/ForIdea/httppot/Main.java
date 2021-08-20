package httppot;

import java.util.*;
import java.net.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        String geturl = "http://api.tianyi2006.xyz/api/weather.php?msg=长春&type=7";
        //这个是请求链接，我用到get方式
        String s = Http.sendurl(geturl);
    }
}