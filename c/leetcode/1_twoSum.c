/*************************************************************************
	> File Name: 1_twoSum.c
	> Author: DennisGao
	> Mail: DennisGao 
	> Created Time: 2019年03月02日 星期六 19时05分08秒
 ************************************************************************/
/*
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - 1 - j; i++)
		{
			if(a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
	int *res = (int*)malloc(sizeof(int)*2);
	memset(res, 0, sizeof(int)*2);

	for (int i=numsSize-1; i>=0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (target == nums[i] + nums[j])
			{
				res[0] = j;
				res[1] = i;
				return res;
			}
		}
	}
	return res;
}

void test1()
{
	int nums[4] = {2, 7, 11, 15};
	int target = 9;
	int *resp = twoSum(nums, 4, target);
	printf("%d %d\n", resp[0], resp[1]);// 0 1
	free(resp);
}
void test2()
{
	int nums[4] = {2, 7, 11, 15};
	int target = 13;
	int *resp = twoSum(nums, 4, target);
	printf("%d %d\n", resp[0], resp[1]);// 0 2
	free(resp);
}
void test3()
{
	int nums[4] = {2, 7, 11, 15};
	int target = 26;
	int *resp = twoSum(nums, 4, target);
	printf("%d %d\n", resp[0], resp[1]);// 2 3
	free(resp);
}
void test4()
{
	int nums[3] = {3, 2, 3};
	int *resp = twoSum(nums, 3, 6);
	printf("%d %d\n", resp[0], resp[1]);//0 2
	free(resp);
}
void test5()
{
	int nums[4] = {-3,4,3,90};
	int *resp = twoSum(nums, 4, 0);
	printf("%d %d\n", resp[0], resp[1]);//0 2
	free(resp);
}

int main(int argc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}

