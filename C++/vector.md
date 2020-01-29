## vector

1. 常用函数
函数   |参数  |返回值 |用法
:---|:--:|:--:|---
vector\<type\>|   |     |定义
vector[int] |     |     |下标访问
iterator    |     |     |迭代器访问
push_back() |type |void |添加尾元素
pop_back()  |void |void |删除尾元素
insert(it,x)|     |     |
erase(it)   |     |     |
clear()     |     |     |清空
size()      |     |int  |元素个数
resize(int) |     |     |设定vector长度，并初始化为默认值
reserve(int)|     |     |预留vector长度，不初始化

2. 运算符
运算符  |   |用法
:--:    |:--:   |---
=       |vec1=vec2 |拷贝，完全复制

3. 注意点
  + 若定义了vector初始大小,如vector<int> vec(10)，元素会初始化为默认值
  + pop_back不返回元素
  + resize()用于预留空间。
    在vector定义后才得到vector大小时，就可以用resize()初始化并赋值，否则不能用下标访问。(注意和reverse的区别)
    比如：vector定义在全局，但在main中才接收vector大小，这时用resize()就很好。
