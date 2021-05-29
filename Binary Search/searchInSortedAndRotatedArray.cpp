/*
33. Search in Rotated Sorted Array.

You are given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
If target is found in the array return its index, otherwise, return -1.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1

Leetcode : https://leetcode.com/problems/search-in-rotated-sorted-array/
Geeksforgeeks : https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
Mycodeschool  : https://www.youtube.com/watch?v=uufaK2uLnSI&list=PL2_aWCzGMAwL3ldWlrii6YeLszojgH77j&index=7&ab_channel=mycodeschool
*/

/*
Clarifying Questions:
 1. Are elements of nums are unique or not.
 2. nums is guranteed to be rotated at some pivot.
 
If answers to both the questions are YES, we can use some form of binary search, else we need to use linear search.
*/

// We can solve this problem in two methods.
// 1. Perform a linear seach. 
//        Time Complexity : O(n), Extra Space : O(1)
// 2. Since the array is sorted and rotated, we can perform a modified Binary Search. 
//        Time Complexity : O(log n), Extra Space : O(1)

int searchInSortedAndRotatedArray(std::vector<int>& nums, int target) 
{
    int lowerIndex = 0;
    int higherIndex = nums.size() - 1;
    int middleIndex = -1;

    while(lowerIndex <= higherIndex)
    {
        middleIndex = lowerIndex + (higherIndex - lowerIndex)/2;
        
        // If the middle element is the target, return middle element.
        if(nums[middleIndex] == target)
        {
            return middleIndex;
        }
      
        // If nums[lowerIndex] <= nums[middleIndex], left half of the array is sorted, else right half of the array is sorted.
        if(nums[lowerIndex] <= nums[middleIndex])
        {
            if((nums[lowerIndex] <= target) && (target < nums[middleIndex]))
            {
                higherIndex = middleIndex - 1;
            }
            else
            {
                lowerIndex = middleIndex + 1;
            }
        }
        else
        {
            if((nums[middleIndex] < target) && (target <= nums[higherIndex]))
            {
                lowerIndex = middleIndex + 1;
            }
            else
            {
                higherIndex = middleIndex - 1;
            }
        }
    }

    return -1;
}

