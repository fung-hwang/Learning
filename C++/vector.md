## vector

1. 常用函数
函数   |参数  |返回值 |用法
:---|:--:|:--:|---
vector\<type\>|   |     |定义
vector[int] |     |     |下标访问
iterator    |     |     |迭代器访问
push_back() |type |void |添加尾元素
pop_back()  |void |void |删除尾元素，不返回值
insert(it,x)|     |     |
erase(it)   |     |     |
clear()     |     |     |清空
size()      |     |int  |元素个数
resize(int) |     |     |设定vector长度，并初始化为默认值
reserve(int)|     |     |设定vector容量，不影响size，不初始化

2. 运算符
运算符  |   |用法
:--:    |:--:   |---
=       |vec1=vec2 |拷贝，完全复制

3. 注意点
  + 若定义了vector初始大小,如vector<int> vec(10)，元素会初始化为默认值
  +  reserve增加了vector的capacity，但是它的size没有改变！而resize改变了vector的capacity同时也增加了它的size！

    reserve()是容器预留空间，但在空间内不真正创建元素对象，所以在没有添加新的对象之前，不能引用容器内的元素。加入新的元素时，要调用push_back()/insert()函数。

    resize()用于预留+初始化空间。
