#pragma once
#include <stdio.h>
#include <time.h>
#include <algorithm>
using namespace std;
//¸¨Öúº¯Êý
void ini(int num[], int len)
{
	srand((unsigned)time(NULL));
	for (int i = 0;i < len;i++)
		num[i] = rand() % 100;
}
void Swap(int *a, int *p)
{
	int temp = *a;
	*a = *p;
	*p = temp;
}
void print(int num[], int len)
{
	for (int i = 0;i < len;i++)
	{
		printf("%5d", num[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}
bool cmp(int a, int b)
{
	return a < b;
}
//ÎÈ¶¨ÅÅÐò---
//Ã°ÅÝÅÅÐò
void BubbleSort(int num[], int len)
{
	for (int i = 0;i < len - 1;i++)
		for (int j = 0;j < len - i - 1;j++)
			if (!cmp(num[j], num[j + 1]))
				Swap(&num[j], &num[j + 1]);
}
//²åÈëÅÅÐò
void InsertionSort(int num[],int len)
{
	int temp[100] = { 0 },numlen=0;
	for (int i = 0;i < len;i++)
		temp[i] = num[i];
	for(int i=0;i<len;i++)
	{
		int pos = numlen-1;
		while (pos >= 0 && cmp(temp[i], num[pos]))
			num[pos + 1] = num[pos], pos--;
		num[pos+1] = temp[i];
		numlen++;
	}
}
//¹é²¢ÅÅÐò
void MergeArr(int num[], int left, int mid, int right)
{
	int AL[100], AR[100],lenl=mid-left+1,lenr=right-mid;
	for (int i = 0;i < lenl;i++)
		AL[i] = num[left + i];
	for (int i = 0;i < lenr;i++)
		AR[i] = num[mid + 1 + i];
	int j = 0, k = 0,pos=left;
	while (j < lenl&&k < lenr)
	{
		if (cmp(AL[j], AR[k]))
			num[pos++] = AL[j++];
		else
			num[pos++] = AR[k++];
	}
	while (j < lenl)
		num[pos++] = AL[j++];
	while (k < lenr)
		num[pos++] = AR[k++];
}
void MergeSort(int num[], int left, int right)
{
	if (left < right)
	{
		int mid = (right + left) / 2;
		MergeSort(num, left, mid);
		MergeSort(num, mid+1, right);
		MergeArr(num, left, mid, right);
	}
}
//Í°ÅÅÐò
void BucketSort(int num[], int len)
{
	int bucket[10][100],pos=0;
	for (int i = 0;i < 10;i++)
		bucket[i][0] = 0;
	for (int i = 0;i < len;i++)
		bucket[num[i] / 10][++bucket[num[i] / 10][0]] = num[i];
	for (int i = 0;i < 10;i++)
		sort(bucket[i] + 1, bucket[i] + 1 + bucket[i][0], cmp);
	for (int i = 0;i < 10;i++)
		for (int j = 1;j <= bucket[i][0];j++)
			num[pos++] = bucket[i][j];
}
