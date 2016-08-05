// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SortAlgorithm.h"
#include <iostream>

int main()
{
	int num[20];
	ini(num,20);
	print(num, 20);
	//BubbleSort(num, 20);
	//InsertionSort(num, 20);
	//MergeSort(num, 0, 19);
	BucketSort(num, 20);
	print(num, 20);
	system("pause");
    return 0;
}

