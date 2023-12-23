/*
* 53. 最大子数组和
* 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
* 子数组 是数组中的一个连续部分。
* Case1: 
* 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
* 输出：6
* 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
* Case2:
* 输入：nums = [-1]
* 输出：-1
*
*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int curr_sum;
    int max_sum;
    int idx;

    curr_sum = 0;
    max_sum = -32767;
    
    for(idx = 0; idx < numsSize; idx++)
    {
        curr_sum += *(nums + idx);
        if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }
        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}

void cmp(int resultOut, int resultRef,int CaseNum)
{
    if(resultOut == resultRef)
    {
        printf("Case %d is pass!\n", CaseNum);
    }
    else
    {
        printf("Case %d is fail!\n", CaseNum);
    }
}

void main()
{
    int nums1[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int nums2[1] = {-1};
    int maxSum;
    int len;
    int result1 = 6;
    int result2 = -1;

    len = sizeof(nums1)/sizeof(nums1[0]);
    maxSum = maxSubArray(&nums1, len);
    cmp(maxSum, result1,1);

    len = sizeof(nums2)/sizeof(nums2[0]);
    maxSum = maxSubArray(&nums2, len);
    cmp(maxSum, result2,2);
}