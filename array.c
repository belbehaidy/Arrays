/*Implementation of functions declared in Header file*/

#define ARRAY_C

#ifndef ARRAY_H
#include "array.h"
#endif

void zero_array(int *array,int size)
{
	for(;size;array[--size]=0);
}

void EnterArrayData(int *array,int size)
{
	printf("\nPlease, enter the value of array elements : ");
	for(int i=0; i<size;i++)
	{
		printf("\t[%d] = ",i);
		scanf("%d",&i);
	}
}

int sum_array(int *array,int size)
{
	int sum=0;
	
	for(int i=0;i < size;sum+=array[i++]);
	
	return sum;
}

int max_array(int *array,int size)
{
	int max=array[--size];
	for(;size>=0;size--)
	{
		if(max<array[size]) max=array[size];
	}
	return max;
}

int min_array(int *array,int size)
{
	int min=array[--size];
	for(;size>=0;size--)
	{
		if(min>array[size]) min=array[size];
	}
	return min;
}

void reverse_array(int *array,int size)
{
	for(int low=0,high=size-1;high>low;low++,high--)
	{
		array[low]^=array[high]^=array[low]^=array[high];
	}
}

int linear_search(int *array,int size,int target)
{
	int i=0;
	for(;i<size && array[i]!=target;i++);
	return ((i==size)? (-1):i);
}

int binary_search(int *array,int size,int target)
{
	int left=0, right=size-1 ,mid;
	
	bubble_sort(array,size);
	
	while(right>=left)
	{
		mid=(right+left)/2;
		if(array[mid]>target) left=++mid;
		else if(array[mid]<target) right=--mid;
		else break;
	}
	return ((array[mid]!=target)? (-1):mid );	
}

void bubble_sort(int *array,int size)
{
	for(i=0;i<size-1,i++)
	{
		int count=0;
		for(int j=0;j<size-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				array[j]^=array[j+1]^=array[j]^=array[j+1];
				count++;
			}	
		}
		if(!count) break;
	}
}