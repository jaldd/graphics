一、程序的下载：
下载eclipse。http://www.eclipse.org/downloads/ 最好选择第一个（java EE吧，我选的这个）。
 
下载安装java JDK，这个在http://www.oracle.com/technetwork/java/javase/downloads/index.html。
 
下载CDT，这个是eclipse的插件，为C/C++准备的，下载地址：http://www.eclipse.org/cdt/
 在线安装地址
 http://download.eclipse.org/tools/cdt/releases/helios
下载MinGW，这个味C/C++编译，连接提供工具。gcc 、g++等等，下载地址：http://mingw.en.softonic.com/download（这个不是官方地址i，官方地址下载太慢，并且还出毛病）。
 
二：程序的安装
1. MinGW安装：(注意：要全选，全部安装。。gcc，mingw等）
下载下来后，运行，从MinGW下载过来的文件。按照提示操作，看清楚啊，中途有个提示，问你是否要自动安装，勾上，安装的好啊，我安装到了G盘，如：G:\MinGW
配置MinGW环境，找到环境变量，
 
变量名：CPLUS_INCLUDE_PATH
变量值：G:\MinGW\include;G:\MinGW\include\c++\3.4.2;G:\MinGW\include\c++\3.4.2\backward;G:\MinGW\include\c++\3.4.2\mingw32;G:\MinGW\lib
PATH变量名中加入：
G:\MinGW\bin
最后在G:\MinGW\bin文件夹中找到mingw32-make.exe，将其重命名为make.exe.
 安装完后，环境变量可能会在安装过程中自动设置好，在cmd中输入gcc测试一下，假如显示gcc: no input file ，则安装已成功。

2.  CDT安装
上面东西下载好后，先安装好JDK，然后解压eclipse，我将其解压到G:\eclipse中。
安装CDT插件:打开eclipse软件，Help->Install new software... 

  http://download.eclipse.org/tools/cdt/releases/helios

 
 3. eclipse配置情况
1)  File->new->C++ Project
配置完成后建立工程测试，发现建立Hello World c++ Project类型的项目后可以运行测试，直接建立空项目写个测试类无法运行，提示"launch failed.Binary not found ",产生原因：在CDT中每一次新项目建成后，系统一般默认会进行第一次的构建，也就是自动生成可执行文件。可是事实我们在刚新建的项目甚至还没有源码文 件，所以当然不 会生成可执行的文件了。当我们新建了一个源码文件时，点击执行按钮，就会弹出所说的"launch failed.Binary not found "提示说明（找不到可运行的二进制文件）。
解决办法：窗口左面的项目文件夹上右键鼠标，在弹出的菜单中选择Build Configurations --->Build-->select，选择其中的debug或者release进行构建。
三：配置开发opengl

http://blog.csdn.net/sdlgxxy/article/details/6225267