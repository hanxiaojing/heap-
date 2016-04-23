#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<assert.h>
#include<vector>

template <class T>
class Heap
{
public:
	Heap()
		:_a(NULL)
	{}


	//构造堆：先把各个元素接收到，再根据堆的特点将元素调整
	Heap(const T* array, size_t size)
	{
		_a.reserve(size);
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(array[i]);
		}

		//建堆
		int Size = size;
		for (int j = (_a.size() - 2) / 2; j>=0; j --)
		{
			_AdjustDown(j, Size);
		}
	}


	//拷贝构造
	Heap(const vector<T>& vec)
		:_a(NULL)
	{
		_a.reserve(vec.size());
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(vec[i]);
		}
	}

	//插入一个元素x:先插入到顺序表中，再根据具体元素大小向上调整确定插入元素的位置
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}


	//删除根节点
	void Pop()
	{
		size_t size = _a.size();
		assert(size > 0);//防御式编程，确定是否可以删除元素
		swap(_a[0], _a[size - 1]);//若直接删除堆的根节点，则会使堆结构紊乱
		_a.pop_back();//将根节点与堆的最后一个节点交换位置，此时再对元素删除，以及将其调整于合适位置
		size = _a.size();
		_AdjustDown(0,size);
	}


	//访问堆的根节点
	T& GetTop()
	{
		size_t size = _a.size();
		assert(size > 0);
		return _a[0];
	}


	//将根节点向下调整
	void _AdjustDown(size_t parent,size_t size)
	{
		size_t child = 2 * parent + 1;
		while (child<size)
		{
			if (child+1 < size && _a[child] < _a[child + 1])
			{
				child++;
			}
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}		
	}


	//向上调整
	void _AdjustUp(int child)
	{
		//无论插节点后为左子树还是右子树，都可用(child-2)/2计算出此时父节点的下标
		size_t parent = (child - 1) / 2;
		int index = child;
		size_t size = _a.size();
		while (child<size)
		{
			if (index % 2 == 0 && _a[index - 1] > _a[index])
			{
				--child;								
			}
			if (index % 2 != 0 && index + 1 < child && _a[index] < _a[index + 1])
			{
				++child;
			}
			if (_a[child]>_a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;

				parent = (child-1)/2;
			}
			else
			{
				break;
			}
		}
	}


	bool Empty()
	{
		size_t size = _a.size();
		assert(size >= 0);
		return size == 0;
	}


	size_t Size()
	{
		size_t size = _a.size();
		assert(size >= 0);
		return size;
	}

private:
	vector<T> _a;
};