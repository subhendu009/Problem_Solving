/*
283. Move Zeroes.

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.


Example 1:
----------------------------------------
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
----------------------------------------
Input: nums = [0]
Output: [0]
 
Constraints:
----------------------------------------
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Leetcode : https://leetcode.com/problems/move-zeroes/
*/

void moveZeroes(std::vector<int>& numList) 
{
    int leftIndex = 0;

    for(int currentIndex = 0; currentIndex < numList.size(); ++currentIndex)
    {
        if(numList[currentIndex] != 0)
        {
            std::swap(numList[leftIndex], numList[currentIndex]);
            ++leftIndex;
        }
    }
}
