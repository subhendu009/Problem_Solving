/*
Maximum Value in an Bitonic (Increasing or Decreasing or first increasing and then decreasing) array.

Example 1: [1,2,3,4] // Only increasing. Maximum value = 4.
Example 2: [1,2,3,4,5,3,0] // increasing and then decreasing. Maximum value = 5.
Example 3: [4,3,2,1] // Only decreasing. Maximum value = 4.

*/
#include <iostream>
#include <vector>

// Time Complexity : O(log n) where n is the length of the given array.
// Extra Space : O(1)

// As the array is either increasing or decreasing or bitonic, we can use modified Binary Search.
int getMaxInBitonicArray(const std::vector<int>& numList)
{
    int lowIndex = 0;
    int highIndex = numList.size() - 1;

    while (lowIndex <= highIndex)
    {
        // If lowIndex and highIndex are equal, we are left with only one element.
        // Return it.
        if (lowIndex == highIndex)
        {
            return numList[lowIndex];
        }

        //if we are left with only two elements, return the maximum between those two.
        if ((lowIndex + 1) == highIndex)
        {
            return std::max(numList[lowIndex], numList[highIndex]);
        }

        int midIndex = lowIndex + (highIndex - lowIndex) / 2;

        // check if we have found the maximum number or not.
        // The maximum number will have smaller numbers on both side.
        if ((numList[midIndex - 1] < numList[midIndex]) && 
            (numList[midIndex + 1] < numList[midIndex]))
        {
            return numList[midIndex];
        }

        // We have not found the maximum number yet.
        // Hence pick either left or right half of midIndex.
        
        if ((numList[midIndex - 1] < numList[midIndex]) &&
            (numList[midIndex] < numList[midIndex + 1]))
        {
            lowIndex = midIndex + 1;
        }
        else
        {
            highIndex = midIndex - 1;
        }
    }

    return 0;
}

int main()
{
    /*
    * Test Input:
    * []
    * [1]
    * [1,2]
    * [2,1]
    * [4,3,2,1]
    * [1,2,3,4,5]
    * [10,20,30,40,50,45]
    * [10,20,30,40,50,45,40,35,30,25,20,15,10,5,0]
    */
    std::vector<int> numList{ 10,20,30,40,50,45,40,35,30,25,20,15,10,5,0 };
    int maxValue = getMaxInBitonicArray(numList);
    std::cout << maxValue << std::endl;
    return 0;
}
