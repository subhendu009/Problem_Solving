/*
34. Find First and Last Position of Element in Sorted Array.

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9

Leetcode Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Geeksforgeeks : https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/

*/

// Time Complexity : O(log n) where n is the length of the array.
// Extra Space : O(1)

int findStartOrEndIndex(const std::vector<int> &nums, int target, bool bIsStartIndex)
{
    int lowIndex = 0;
    int highIndex = nums.size() - 1;
    int middleIndex = 0;
    int foundIndex = -1;

    while(lowIndex <= highIndex)
    {
        middleIndex = lowIndex + (highIndex - lowIndex)/2;

        if(nums[middleIndex] == target)
        {
            foundIndex = middleIndex;
            if(true == bIsStartIndex)
            {
                highIndex = middleIndex - 1; 
            }
            else
            {
                lowIndex = middleIndex + 1;
            }
        }
        else if(nums[middleIndex] < target)
        {
            lowIndex = middleIndex + 1;
        }
        else
        {
            highIndex = middleIndex - 1;
        }

    }

    return foundIndex;
}
    
std::vector<int> searchRange(const std::vector<int> &nums, int target) 
{
    std::vector<int> indicesList;
    indicesList.push_back(findStartOrEndIndex(nums, target, true));
    indicesList.push_back(findStartOrEndIndex(nums, target, false));

    return indicesList;
}
