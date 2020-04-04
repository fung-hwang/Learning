## 广度优先搜索BFS

BFS通常是用来求最短路径的

基本模板
~~~C++
void bfs(int s){
  queue<int> q;
  q.push(s);
  while(!q.empty()){
      取队首元素top；
      访问队首元素top(检测是否到达边界，可选);
      将队首元素top出队；
      就top的下一层结点中未曾入队的结点全部入队，并标记为已入队;
  }
}
