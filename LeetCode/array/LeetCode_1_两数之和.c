/*
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 暴力求解法：时间复杂度为O(n^2).
 * 空间复杂度：O(1)
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int)*2);
    int idx;
    int idj;
    for(idx = 0; idx < numsSize - 1; idx++)
    {
       for(idj = idx + 1; idj < numsSize; idj++)
       {
           if(nums[idx] + nums[idj] == target)
           {
               *arr = idx;
               *(arr + 1) = idj; 
               *returnSize = 2;
               return arr;
           }
       }
    }
    *returnSize = 0;
    return NULL;
}

void cmp(int *resultOut, int *resultRef, int len, int CaseNumId)
{
    int tempOut;
    int tempRef;
    int idx;
    int ErrCnt;
    ErrCnt = 0;
    for(idx = 0; idx < len; idx++)
    {
        tempOut = *(resultOut + idx);
        tempRef = *(resultRef + idx);
        if(tempOut != tempRef)
        {
            ErrCnt++;
        }
    }
    if(ErrCnt == 0)
    {
        printf("Case%d is pass.\n", CaseNumId);
    }
    else
    {
        printf("Case%d is fail.\n", CaseNumId);
    }
}
void main()
{
    int Case1_arr[] = {2,7,11,15};
    int Case1_target = 9;
    int resultRef[2] = {0,1};
    int Case1_returnSize;
    int *Case1_return = twoSum(Case1_arr, sizeof(Case1_arr)/sizeof(int), Case1_target, &Case1_returnSize);
    cmp(Case1_return, &resultRef[0], 2, 0);
    free(Case1_return);

    int Case2_arr[] = {3,2,4};
    int Case2_target = 6;
    int resultRef2[2] = {1,2};
    int Case2_returnSize;
    int *Case2_return = twoSum(Case2_arr,sizeof(Case2_arr)/sizeof(int), Case2_target, &Case2_returnSize);
    cmp(Case2_return, &resultRef2[0], 2, 1);
    free(Case2_return);
}