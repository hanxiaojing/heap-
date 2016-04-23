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


	//����ѣ��ȰѸ���Ԫ�ؽ��յ����ٸ��ݶѵ��ص㽫Ԫ�ص���
	Heap(const T* array, size_t size)
	{
		_a.reserve(size);
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(array[i]);
		}

		//����
		int Size = size;
		for (int j = (_a.size() - 2) / 2; j>=0; j --)
		{
			_AdjustDown(j, Size);
		}
	}


	//��������
	Heap(const vector<T>& vec)
		:_a(NULL)
	{
		_a.reserve(vec.size());
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(vec[i]);
		}
	}

	//����һ��Ԫ��x:�Ȳ��뵽˳����У��ٸ��ݾ���Ԫ�ش�С���ϵ���ȷ������Ԫ�ص�λ��
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}


	//ɾ�����ڵ�
	void Pop()
	{
		size_t size = _a.size();
		assert(size > 0);//����ʽ��̣�ȷ���Ƿ����ɾ��Ԫ��
		swap(_a[0], _a[size - 1]);//��ֱ��ɾ���ѵĸ��ڵ㣬���ʹ�ѽṹ����
		_a.pop_back();//�����ڵ���ѵ����һ���ڵ㽻��λ�ã���ʱ�ٶ�Ԫ��ɾ�����Լ���������ں���λ��
		size = _a.size();
		_AdjustDown(0,size);
	}


	//���ʶѵĸ��ڵ�
	T& GetTop()
	{
		size_t size = _a.size();
		assert(size > 0);
		return _a[0];
	}


	//�����ڵ����µ���
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


	//���ϵ���
	void _AdjustUp(int child)
	{
		//���۲�ڵ��Ϊ������������������������(child-2)/2�������ʱ���ڵ���±�
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