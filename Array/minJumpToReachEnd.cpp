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

int minJumpToReachEnd(const std::vector<int> &stepsList)
{
	int listLength = stepsList.size();

    	// if empty list, return -1.
	if(listLength == 0)
	{
		return -1;
	}

	// If list contains only 1 element, return 0.
	if(listLength == 1)
	{
	    return 0;
	}

	// If list contains more than 1 element and the first element is 0, return -1.
	if(stepsList[0] == 0)
	{
	    return -1;
	}

	int minJumps = 1;
	int remainingSteps = stepsList[0];
	int maxSteps = stepsList[0];

    	// Traverse the list starting from index 1.
	for(int index = 1; index < (listLength - 1); ++index)
	{
		--remainingSteps;
		--maxSteps;

        	// Update maxSteps
		if(maxSteps < stepsList[index])
		{
			maxSteps = stepsList[index];
		}

        	// If currentMaxStepsPossible is 0, we can't reach the end.
        	// Hence return -1.
		if(0 == maxSteps)
		{
			return -1;
		}

        	// If there is no more remaining steps for the previous jump,
        	// update remainingSteps and minJumps.
		if(0 == remainingSteps)
		{
			++minJumps;
			remainingSteps = maxSteps;
		}
	}

	return minJumps;
}
