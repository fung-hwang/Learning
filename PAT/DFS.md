## 深度优先搜索DFS

DFS理论暂且不表，只谈论实现  
一般使用递归方法实现，非递归方法不表  

题型
1. N个数中选k个数，要求满足x点条件。需保存最优解。

~~~
//递归函数中需要记录的变量应根据题目调整
void dfs(int index(N个数的下标，递归结点选择), int tempSum(记录1，判定是否达到边界), int tempK(已选数字个数 相关), int facSum（记录2，判定该结果是否需要记录) {

  //边界（路径终结）
  if(满足最终条件，即搜索成功){
    保存方案
    return;
  }

  //递归（路径拓展）
  {
  1.找可能的下一index(下一结点/状态)，因为通常有多个下一结点，会用到循环
  2.递归的准备工作，如判断下一结点是否合法，将合法的下一结点记录在tempAns中
  3.递归
  dfs(index, tempSum + v[index], tempK + 1, facSum + index);
  }
  4.如果没有下一递归结点，这个函数将自然消亡，此条路径终结，相当于return。回归到上一结点的递归环节
~~~
举例：
~~~
	if (tempK == k) {
		if (tempSum == n && facSum > maxFacSum) {
			ans = tempAns;
			maxFacSum = facSum;
		}
		return;
	}

	while (index >= 1) {
		if (tempSum + v[index] <= n) {
			tempAns[tempK] = index;
			dfs(index, tempSum + v[index], tempK + 1, facSum + index);
		}
		if (index == 1) return;
		index--;
	}
}~~~
