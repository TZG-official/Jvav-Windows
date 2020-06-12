# Jvav Compile Platform 源代码

这只是一个梗, 并且当事人并不介意大家玩这个梗

如果您想获得更好的开发体验(关键字高亮,快捷键自动编译等,自动补全正在开发)
可以在VSCode中搜索插件`Jvavscode`,安装此插件后安装主程序即可ctrl+f5编译运行 (**请注意重启VSCode**)

如果您需要手动下载资源文件(一般情况下程序会自动下载,如果出现bug请联系我们)
请前往[http://airk.gitee.io/jvavresourcecdn/]( http://airk.gitee.io/jvavresourcecdn/ )

如果您并不关心源代码,只想使用Jvav编译程序, 
请前往Jvav安装程序:[https://gitee.com/Doxfer/jvav_auxiliary/tree/master/]( https://gitee.com/Doxfer/jvav_auxiliary/tree/master/ )



## 源代码编译和运行

```shell
$ g++ Jvav.cpp JVMplus.cpp -o JCP
```

## 可执行文件使用方法

将本目录加入环境变量,在cmd中输入`jcp init`
点击编译后的可执行文件即可,或在cmd中输入`jcp`
同时,您也可以在cmd中直接使用`jcp -c {源文件名}.jvav`

## 初始化
在cmd中输入
```shell
jcp init
```

## 设置
### 设置Jvav标准版本
```shell
Jvav>settings -std 11 quit
```
### 开启/关闭严格模式
严格模式默认开启,会报变量未使用等错误
所有warning将在严格模式下变为error.
关闭严格模式如下.如需开启则将false改为true
```shell
Jvav>settings -strict=false quit
```

### 编译: compile命令
不会生成可执行文件,但会有正常的程序运行(输入 输出等)
```shell
$ Jvav> compile demo-cn.jvav
```

### 打包: jvins命令
将会生成{executeFileName}.exe可执行文件
```shell
$ Jvav> jvins demo-cn.jvav {executeFileName}
```

## 常见问题
P1. Failed to create folder .....
表示创建文件夹失败,很可能是您的C盘下面有重复目录,
解决方案是:
在C盘下面新建`Jvav`文件夹,并在Jvav文件夹下新建`resource`和`lib`文件夹,在`resource`文件夹下放入您在http://airk.gitee.io/jvavresourcecdn/identifier.res下载的identifier.res文件

P2. The identifier file is missing, please check if the identity.res file is in good condition.installing identifier library for your device.Your device has already had identifier library.Please re-execute the compile command.
表示您在编译前没有执行jcp init命令,在这个情况下,JCP将为您自动初始化,再次编译即可
解决方案是:
再次编译

P3. Compiler error or there is no g++ compiler environment!
可能是您的文件有语法错误,或您的设备中没有g++环境,在cmd中输入g++ -v,如果显示的是
> 'g++' is not recognized as an internal or external command, operable program or batch file.

那么请安装g++环境(事实上,如果您在 https://gitee.com/Doxfer/jvav_auxiliary/tree/master/ 中安装这个程序,将会为您自动添加g++环境)

P4. your os is linux.
你的操作系统为linux发行版(包括Deepin也是Linux发行版),目前暂不支持


---

以下内容不保证最新,请酌情阅读.

---
目录下的`demo-cn.jvav`是一个关于Jvav语法的演示文档

```Jvav
JvavBegin

iNt mAiN(){  //iNt 为 整型变量
    cHaR ch = 'r';  //cHaR 为 字面量(字符)
    iNt n;         
    input n;         //使用input 变量/字符串/字符/重载了">>"运算符的类对象 进行程序输入
    output n magic 10;   //output 变量/字符串/字符/重载了"<<"运算符的类对象 进行程序输出,
    //并使用magic代替*(包括指针/解引用运算符和乘法的*都可以使用magic运算符)
    goBack ZERO;    //使用goBack 代替 return
    //并使用0-10的任意数字的英文单词大写代表0-10,如 ZERO ONE TWO等

    //除此之外,您可以使用if/else的大写字母IF/ELSE来进行条件控制
    //像使用while那样使用Loop,像使用for那样使用ConLoop
}

JvavEnd
```
这是一个简单的JCP with jvins的demo
乱码问题正在修复
```shell
---------------------------------------------
| Jvav Program                Ver.2 Pre0    |
| By Dr.ZhangHaoYang      Programmer 30266  |
| The author of the JCP & Jvins: Amiriox    |
| Enter'help'to get help!
          |
| Online push updates are now supported!    |
| Compile vav source ile are now supported! |
--------------------------------------------
Jvav>compile demo-cn.jvav
demo-cn.cpp: In function \'int main()\':
demo-cn.cpp:55:10: error: unused variable \'ch\' [-Werror=unused-variable]
     cHaR ch = \'r\';  //cHaR 涓?瀛?1;31mm^~
cc1plus.exe: all warnings being treated as errors
deleting *.cpp

Compiler error or there is no g++ 
compiler environment!
Jvav>settings
tips: Warning: You are changing your settings
Please enter the Settings you want to change,
enter quit to quit:
-std
Input 11 or 14 or 17 for jvav standard version: 11
The standard has been set to 11   
-strict=false
Strict Mode already been closed.  
quit
Jvav>compile demo-cn.jvav
450
4500
3请按任意键继续. . .


Compile successfully.
Jvav>jvins demo-cn.jvav testins   

Your execute file has been generated.

Compile successfully.
Jvav>exit

D:\CppProjects\DevelopingProjects\Public.MyJCP\JvavCompilePlatform>testins.exe
4502
45020
3请按任意键继续. . .
D:\CppProjects\DevelopingProjects\Public.MyJCP\JvavCompilePlatform>
```
