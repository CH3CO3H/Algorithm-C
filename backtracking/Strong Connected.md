# Strong Connected

问题：强连通图的判定。

原始问题：给定一个无向图，问能否通过给边定向的方式使其变为强连通图。

强连通图，即任意两结点间都存在双向的路径。

上面两个问题其实是等价的，因为若一个有向图是强连通图，将构成某一环路的所有边的方向取反，它仍然是强连通图。给一个强连通图再增加边，它仍然是强连通图。在给无向边定向时，若有多个选择，可以任意选取。

我们假设给定的图是简单图，即无自身环和重边。

考虑强连通图的生成过程，给一个强连通图增加一个结点，并增加此结点到原图某点、以及原图某点到该点的路径，它仍然是强连通图。那么强连通图的定义是否可以写成这样：

- 平凡图是强连通图；
- 给强连通图增加一结点，并增加该结点与原图间的双向路径，生成的新图也是强连通图。

然而这只是强连通图的充分条件，并不是所有强连通图都可以通过这样逐个增加结点的方式生成出来。比如强连通图可能只是一个环，去掉任何一个结点后都不是强连通图。

![](https://wx4.sinaimg.cn/large/b66c1c09ly1gjw6etb3lrj20m80go3yl.jpg)

这样看来，强连通图的关键在于有环。那么是否可以从某一点开始 DFS，检测叶子结点是否与根结点间直接相连呢？

然而这也是错的，叶子结点不一定与根结点直接相连，比如下图这样：

![](https://wx1.sinaimg.cn/large/b66c1c09ly1gjw5z0bfhjj20jg08c3yh.jpg)

所以强连通图的一个可行定义是这样：

- 平凡图是强连通图；
- 给定一个强连通图和一个结点集，结点集内的所有点与强连通图间都有双向的路径，则它们的合并是强连通图。

据此我们写出下面的伪代码：

```
StrongConnected(g)
	unmark all vertices
	mark s as solved
	return findCycle(s)
findCycle(s)
	for each edge sw
		if w is unmarked
			mark w as pending
			return  findCycle(w)
		else if w is marked solved
			change all pending to solved
	if all w are marked pending
		return false
```

C 语言函数代码可向后台发消息索取。