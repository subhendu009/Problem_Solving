/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

Example 3:

Input: nums = [0]
Output: []
 
Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105

Leetcode : https://leetcode.com/problems/3sum/
Study Link : https://www.youtube.com/watch?v=onLoX6Nhvmg&list=PLgUwDviBIf0rBT8io74a95xT-hDFZonNs
*/

/*
Method 1
-------------------------------------------------------------- 
1.  sort the array
2.  for each number in array
		find other two numbers using two pointer approach
		skip same values

Time Complexity : O(n ^ 2)
Extra Space : O(n) in worst case for std::sort()
Drawback : Array will be modified.


Method 2:
----------------------------------------------------------------------
for each number in array:   // n
	find other two numbers using a hash set // Extra Space : O(n) // n
		if a valid triplet
			check if it is already existing one or not in the map
				if not present
					add that to the map
					add that to the end result


// Time Complexity : O(n ^ 2 log m)
// Extra Space : O(n + m), where n is the length of the array and m is the number of triplets.

ordered map:
Key                           value
1st value of the triplet	  a pair of other two numbers of the triplet
*/

std::vector<std::vector<int>> threeSum(std::vector<int>& numList) 
{
	std::vector<std::vector<int>> tripletList;
	
	int listLength = numList.size();
	std::sort(numList.begin(), numList.end());
	
	for(int i = 0; i < listLength; ++i)
	{
		int leftIndex = i + 1;
		int rightIndex = listLength - 1;
		
		while(leftIndex < rightIndex)
		{
			int currentSum = numList[i] + numList[leftIndex] + numList[rightIndex];
			if(currentSum > 0)
			{
				--rightIndex;
			}
			else if(currentSum < 0)
			{
				++leftIndex;
			}
			else
			{
				std::vector<int> triplet(3);
				triplet[0] = numList[i];
				triplet[1] = numList[leftIndex];
				triplet[2] = numList[rightIndex];
				tripletList.push_back(triplet);
				
				while((leftIndex < rightIndex) && (numList[leftIndex] == numList[leftIndex + 1]))
				{
					++leftIndex;
				}
				
				++leftIndex;
				
				while((leftIndex < rightIndex) && (numList[rightIndex] == numList[rightIndex - 1]))
				{
					--rightIndex;
				}
				
				--rightIndex;
			}
		}
		
		 while((i < (listLength - 1)) && (numList[i] == numList[i + 1]))
		{
			++i;
		}
	}
			   
	return tripletList;
}
