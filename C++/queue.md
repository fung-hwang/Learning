## queue

1. 常用函数
函数   |参数  | 返回值 |用法
:---|:--:|:--:|---
queue\<type\>|||定义
push() |type |void  |入队
front()|void |type  |取队首
back() |void |type  |
pop()  |void |**void** |弹出队首（不作为返值）
empty()|     |bool  |判空
size() |     |int   |元素个数

2. 常见用法
    + BFS
    + 模拟“轮次”
    +

3. 注意点
    1. pop()不返回值，如果需要弹出队首并获取返回值，
      需要 front() , pop() 连用
    2.
