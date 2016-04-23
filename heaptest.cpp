#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.hpp"

void Test()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int> h1(a, sizeof(a) / sizeof(a[0]));
	Heap<int> h2(h1);
	cout<<h1.GetTop()<<endl;
	cout << h1.Size() << endl;

	h1.Push(20);
	cout << h1.GetTop() << endl;

	h1.Pop();
	cout << h1.Size() << endl;

}

int main()
{
	Test();
	system("pause");
	return 0;
}