/*
Sort Colors. (Dutch National Flag Problem).

Given an array with n objects colored red, white or blue,
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

Leetcode : https://leetcode.com/problems/sort-colors/

Geeksforgeeks :
	https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
	https://www.geeksforgeeks.org/sort-array-0s-1s-2s-simple-counting/
	https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
*/

// Method 1 : Two-pass solution
// Time Complexity : O(n) where n is the length of the given list.
// Extra Space : O(1), constant space.
void sortColors(std::vector<int> &numList)
{
	int zeroes = 0;
	int ones = 0;

	for(int number : numList)
	{
		if(number == 0)
		{
			++zeroes;
		}
		else if(number == 1)
		{
			++ones;
		}
	}

	for(int index = 0; index < zeroes; ++index)
	{
		numList[index] = 0;
	}

	for(int index = 0; index < ones; ++index)
	{
		numList[zeroes + index] = 1;
	}

	int twos = numList.size() - totalZeroesOnes;

	for(int index = 0; index < twos; ++index)
	{
		numList[zeroes + ones + index] = 2;
	}
}

// Single pass solution.

// Time Complexity : O(n) where n is the length of the given list.
// Extra Space : O(1), constant space.
void sortColors(std::vector<int>& nums)
{
	int lowIndex = 0;
	int midIndex = 0;
	int highIndex = nums.size() - 1;

	while(midIndex <= highIndex)
	{
		if (0 == nums[midIndex])
		{
			std::swap(nums[lowIndex], nums[midIndex]);
			++lowIndex;
			++midIndex;
		}
		else if (1 == nums[midIndex])
		{
			++midIndex;
		}
		else
		{
			std::swap(nums[highIndex], nums[midIndex]);
			--highIndex;
		}
	}
}
