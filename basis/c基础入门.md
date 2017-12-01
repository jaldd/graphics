# 变量
## 舍入误差

```
	float a,b;
	a=123456.789e5;
	b=a+20;
	printf("%f\n",a);
	printf("%f\n",b);
	return 0;
```
1. 每个字符变量分配一个字节内存空间，因此只能存放一个字符，字符值以ascii码（二进制代码）形式存放在变量的内存单元中。

# window.h
### undefined reference to ` _GetStockObject@4'

---
将glib32.lib给添加进来

---
Project->Properties->C/C++ Build->Settings->MinGW C++ Linker->Libraries
在Libraries(-l)中添加gdi32即可