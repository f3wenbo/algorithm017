# Queue

## 关于Queue
---
queue是一种先进先出(FIFO)的数据结构，它有两个出口。queue允许新增元素、移除元素、从最底端加入元素、取得最顶端元素。但除了最底端可以加入、最顶端可以取出外，没有任何其他方法可以存取queue的其它元素。换言之，queue不允许有遍历行为.

queue是基于别的container进行修改, 使其符合FIFO特性, 这种称之为adapter. 因此queue又被归类为container adapter.

## Queue源码分析
---
从源码可以分析得出,queue的底层(underlying container)是基于deque的

```c++
template<typename _Tp, typename _Sequence = deque<_Tp> >
class queue {
    /* ... */
protected:
    _Sequence c;
}
```

### push()
---
从源码可以看出, 在deque的尾部添加元素

```c++
void push(value_type&& __x) { 
    c.push_back(std::move(__x)); // std::move将__x转换为右值引用
}
```

### pop()
---
在deque的头部将元素取出

```c++
void pop(){
__glibcxx_requires_nonempty();
   c.pop_front();
}
```

有一点值得注意就是因为FIFO不需要遍历, 因此queue不存在迭代器.

<br>

# priority_queue

priority_queue的源码也在std_queue.h中. 

## 基础知识学习
---
priority_queue是一个拥有权值概念的queue. 本质上是queue.

## 源码分析
---
从以下代码可以看到，priority_queue的底层由vector来实现，和queue有所不同的是提供了一个比较函数的template.

```c++
template<typename _Tp, typename _Sequence = vector<_Tp>,
typename _Compare  = less<typename _Sequence::value_type> >
class priority_queue {
/*...*/
protected:
    _Sequence  c;
    _Compare   comp; // 权值比较函数
}
```

在Constructor时, 对元素就进行了排序. 

```c++
 priority_queue(const _Compare& __x = _Compare(),const _Sequence& __s = _Sequence()): c(__s), comp(__x) {
    std::make_heap(c.begin(), c.end(), comp); // 堆排序, 从大到小
}
```

### push()
---
每次添加一个元素都会进行一个堆排序

```c++
void push(const value_type& __x){
    c.push_back(__x);
    std::push_heap(c.begin(), c.end(), comp);
}
```

### pop()
---
```c++
void pop() {
    __glibcxx_requires_nonempty();
    std::pop_heap(c.begin(), c.end(), comp);// 原来是 3 2 1, 调用后变成 2 1 3
    c.pop_back(); // 末尾元素移除
}
```

## 参考资料

www.cplusplus.com