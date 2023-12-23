/*
* 53. 最大子数组和
* 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。并返回子数组的起始索引。
* 子数组 是数组中的一个连续部分。
* Case1: 
* 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
* 输出：6, 3, 6
* 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
* Case2:
* 输入：nums = [-1]
* 输出：-1, 0, 0
*
*/

/*
* 解题思路：遍历数组，用curr_sum记住当前连续多个数的累加和，用max_sum表示当前序列的最大值。当curr_sum>max_sum时，最大值就被替换。
* 如果是curr_sum负数，此时对连续的数值和是负收益，所以清0，重新累加。
*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize, int *start, int *end) {
    int curr_sum;
    int max_sum;
    int idx;
    int startTemp;

    curr_sum = 0;
    max_sum = -32767;
    startTemp = 0;
    *end = 0;
    
    for(idx = 0; idx < numsSize; idx++)
    {
        curr_sum += *(nums + idx);
        if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
            (*start) = startTemp;
            (*end) = idx;
        }
        if(curr_sum < 0)
        {
            curr_sum = 0;
            startTemp = idx + 1;
        }
    }
    return max_sum;
}

void cmp(int *presultOut, int *presultRef,int CaseNum, int len)
{
    int idx;
    int resultOut;
    int resultRef;
    int ErrCnt;

    ErrCnt = 0;
    for(idx = 0; idx < len; idx++)
    {
        resultOut = *(presultOut + idx);
        resultRef = *(presultRef + idx);
        if(resultOut != resultRef)
        {
            ErrCnt++;
        }
    }
    if (ErrCnt == 0)
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
    int len;
    int result1[3] = {6,3,6};
    int result2[3] = {-1,0,0};
    int resultOut[3];

    len = sizeof(nums1)/sizeof(nums1[0]);
    resultOut[0] = maxSubArray(&nums1[0], len,&resultOut[1],&resultOut[2]);
    cmp(&resultOut[0], &result1[0],1,3);

    len = sizeof(nums2)/sizeof(nums2[0]);
    resultOut[0] = maxSubArray(&nums2[0], len,&resultOut[1],&resultOut[2]);
    cmp(&resultOut[0], &result2[0],2,3);
}