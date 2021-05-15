/*
18. 4Sum.

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n where a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

https://leetcode.com/problems/4sum/
https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=21
*/

// Time Complexity : O(n ^ 3)
// Extra Space : O(n) in worst case, for sorting.
// Con : The given array will be modified as we are sorting that array.

std::vector<std::vector<int>> fourSum(std::vector<int>& numList, int target) 
{
    std::vector<std::vector<int>> fourSumList;

    // Sort the given number list.
    std::sort(numList.begin(), numList.end());

    std::vector<int> intList(4);

    int numListLength = numList.size();

    // Outer Loop.
    for(int i = 0; i < numListLength; ++i)
    {
        // First Inner loop.
        for(int j = i + 1; j < numListLength; ++j)
        {   
            // Use two pointer approach to find two elements.
            int left = j + 1;
            int right = numListLength - 1;

            while(left < right)
            {
                int currentElemSum = numList[i] + numList[j] + 
                                     numList[left] + numList[right];

                if(currentElemSum < target)
                {
                    ++left;
                }
                else if(currentElemSum > target)
                {
                    --right;
                }
                // we have found a pair here.
                else
                {
                    intList[0] = numList[i];  
                    intList[1] = numList[j];
                    intList[2] = numList[left];
                    intList[3] = numList[right];

                    // Add the number list to the fourSumList vector.
                    fourSumList.push_back(intList);

                    ++left;
                    --right;

                    // Move left index to right to pass over duplicates.
                    while((left <= right) && (numList[left - 1] == numList[left]))
                    {
                        ++left;
                    }

                    // // Move right index  to left to pass over duplicates.
                    while((left <= right) && (numList[right + 1] == numList[right]))
                    {
                        --right;
                    }
                }
            }

            // Ignore duplicates
            while((j < (numListLength - 1)) && (numList[j] == numList[j + 1]))
            {
                ++j;
            }
        }

        // Ignore duplicates
        while((i < (numListLength - 1)) && (numList[i] == numList[i + 1]))
        {
            ++i;
        }
    }

    return fourSumList;
}
