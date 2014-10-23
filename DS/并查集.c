/**
 *		并查集(union_set) -- 将2个有序集合进行快速合并, 去掉重复元素
 */

 #include <stdio.h>
 #include <stdlib.h>

 //并查集结构
 #define MAXSIZE 100			// 集合最大元素个数
 int parant[MAXSIZE];			// parant[x] 表示 元素x 的根元素
 int rank[MAXSIZE];				// rank[x] 表示 以元素x 为根元素的集合 的深度


 /**
  *	 将每一个元素都放到一个单独的集合中
  */
 void makeset(int element) {
 	parant[element] = element;	//把自己作为集合的根元素
 	rank[element] = 0;			//集合只有自己，所以深度 = 0
 }

 /**
  *	 查找当前元素所在集合的根元素 (递归查找: 当前元素的根节点，可能是另外一个集合的子元素)
  * 	(求parant[x] == x的根元素)
  */
 int findParant(int element) {

 	//1)初始化单元素集合时, x的根元素就是parant[x]
 	//2)现在x的根元素已经不再是x (自己不再是单元素结合，已经是作为其他集合的子元素)
 	if (element != parant[element])	
 	{
 		//递归查找: 当前元素的根节点 = 当前元素的 根节点的 根节点
 		parant[element] = findParant(parant[element]);
 	}
 	return parant[element];
 }

 /**
  *	 按秩合并x，y所在的集合
  */
  void union_set(int x, int y) {

  		//1. 查找扫2个元素所在集合的根元素
  	    x = findParant(x);
  	    y = findParant(y);

  	    //2. 将深度低得集合 插入到 深度高的集合的子集合
  	    if (rank[x] < rank[y])
  	    {
  	    	parant[x] = y;		//把y作为x集合的根节点
  	    }else {
  	    	//有大于和等于的情况
  	    	parant[y] = x;		//x集合深度 >或= y集合深度, 都把x作为y的根元素

  	    	//x集合深度 == y集合深度 ( 1)把x作为y的根元素 2)x深要 + 1 )
  	    	if (rank[x] == rank[y])
  	    	{
  	    		rank[x]++;
  	    	}
  	    }
  }


