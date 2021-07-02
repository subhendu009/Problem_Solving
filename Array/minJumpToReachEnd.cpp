/*
45. Jump Game II.

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 
Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000

Leetcode : https://leetcode.com/problems/jump-game-ii/
*/

//Clarifying Question : Can we always reach the end or not ? What should we return if we can not reach the end ?
// Here, we are returning -1.

// Time Complexity : O(n) where n is the length of the given array.
// Extra Space : O(1)

int jump(const std::vector<int>& numList) 
{
    // Edge cases.
    // 1. The first element is 0 OR
    // 2. The list has only 1 element.
    if((0 == numList[0]) || (1 == numList.size()))
    {
        return 0;
    }

    int remainingSteps = numList[0];
    int currentMaxStepsPossible = numList[0];
    int minimumJumps = 1;
    int lastIndex = numList.size() - 1;

    // Traverse the list starting from index 1.
    for(int index = 1; index < lastIndex; ++index)
    {
        --remainingSteps;
        --currentMaxStepsPossible;

        // Update maxJumps
        if(currentMaxStepsPossible < numList[index])
        {
            currentMaxStepsPossible = numList[index];
        }

        // If currentMaxStepsPossible is 0, we can't reach the end.
        // Hence return -1.
        if(0 == currentMaxStepsPossible)
        {
            return -1;
        }

        // If there is no more remaining steps for the previous jump,
        // update remainingPlaces and minimumJumps.
        if(0 == remainingSteps)
        {
            remainingSteps = currentMaxStepsPossible;
            ++minimumJumps;
        }
    }

    return minimumJumps;
}
