/*
Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the right side of x in array.
Elements for which no greater element exist, consider next greater element as -1.

Examples:

For any array, rightmost element always has next greater element as -1.
For an array which is sorted in decreasing order, all elements have next greater element as -1.

For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
Element        NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.
  Element         NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1

Geeksforgeeks : https://www.geeksforgeeks.org/next-greater-element/
https://www.youtube.com/watch?v=sDKpIO2HGq0&ab_channel=TECHDOSE
*/

#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;

// Brute Force Solution.
// Time Complexity : O(n ^2) where n is the length of the given array.
// Extra Space : O(1)
std::vector<long long> getNextLargerElementList(const std::vector<long long>& numList)
{
	std::vector<long long> resList(numList.size());

	for (int i = 0; i < numList.size(); ++i)
	{
		resList[i] = -1;

		for (int j = i + 1; j < numList.size(); ++j)
		{
			if (numList[i] < numList[j])
			{
				resList[i] = numList[j];
				break;
			}
		}
	}

	return resList;
}


// Time optimized solution using stack
// Time Complexity : O(n)
// Extra Space : O(n) where n is the length of the given array.

std::vector<long long> getNextLargerElementList(const std::vector<long long>& numList)
{
	std::vector<long long> resList(numList.size());

	std::stack<long long> rightGreaterNumStack;

	for (int index = numList.size() - 1; index >= 0; --index)
	{
		while (rightGreaterNumStack.empty() == false &&
			   rightGreaterNumStack.top() <= numList[index])
		{
			rightGreaterNumStack.pop();
		}

		if (rightGreaterNumStack.empty())
		{
			resList[index] = -1;
		}
		else
		{
			resList[index] = rightGreaterNumStack.top();
		}

		rightGreaterNumStack.push(numList[index]);
	}

	return resList;
}
