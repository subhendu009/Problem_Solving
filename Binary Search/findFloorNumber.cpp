/*
Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. 
Write efficient functions to find floor of x.

Examples:

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
Output : 2
2 is the largest element in arr[] smaller than 5.

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20
Output : 19
19 is the largest element in arr[] smaller than 20.

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 0
Output : -1
Since floor doesn't exist, output is -1.

Geeksforgeeks: https://www.geeksforgeeks.org/floor-in-a-sorted-array/
*/


#include <iostream>

using std::cout;
using std::endl;


int findFloor(long long int numList[], int arrSize, long long int key)
{
	if(!numList)
	{
	return -1;
	}

	int lowIndex = 0;
	int highIndex = arrSize - 1;

	int floorIndex = -1;

	while (lowIndex <= highIndex)
	{
		int midIndex = lowIndex + (highIndex - lowIndex) / 2;
		if (numList[midIndex] == key)
		{
			return midIndex;
		}

		if (numList[midIndex] < key)
		{
			floorIndex = midIndex;
			lowIndex = midIndex + 1;
		}
		else
		{
			highIndex = midIndex - 1;
		}
	}

	return floorIndex;
}
