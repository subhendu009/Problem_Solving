/*
Maximum Rectangular Area in a Histogram
------------------------------------------------------------------------------------------

Find the largest rectangular area possible in a given histogram where the largest rectangle can be 
made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7

arr[] = {6,2,5,4,5,1,6}

Output: 12 

Example 2:

Input:
N = 8

arr[] = {7 2 8 9 1 3 6 5}

Output: 16

Explanation: Maximum size of the histogram will be 8  and there will be 2 consecutive histogram. 
And hence the area of the histogram will be 8x2 = 16.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 106
1 <= arr[i] <= 1012

Geeksforgeeks:
    https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/
    https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
    https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
    
Leetcode : https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

// Function to get list of next smaller elements to left.
// Time Complexity : O(n)
// Extra Space : O(n), where n is the length of the array.
std::vector<int> nextSmallerElementToLeft(long long arr[], int n)
{
    std::stack<int> indexStack;
  
    // Initialize the result vector with all -1.
    std::vector<int> indicesList(n, -1);

    for(int currentIndex = 0; currentIndex < n; ++currentIndex)
    {
        while(!indexStack.empty() && arr[currentIndex] <= arr[indexStack.top()])
        {
            indexStack.pop();
        }

        if(false == indexStack.empty())
        {
            indicesList[currentIndex] = indexStack.top();
        }

        indexStack.push(currentIndex);
    }

    return indicesList;
}

// Function to get list of next smaller elements to right.
// Time Complexity : O(n)
// Extra Space : O(n), where n is the length of the array.
std::vector<int> nextSmallerElementToRight(long long arr[], int n)
{
    std::stack<int> indexStack;
  
    // Initialize the result vector with all n.
    std::vector<int> indicesList(n, n);

    for(int currentIndex = n - 1; currentIndex >= 0; --currentIndex)
    {
        while(!indexStack.empty() && arr[currentIndex] <= arr[indexStack.top()])
        {
            indexStack.pop();
        }

        if(false == indexStack.empty())
        {
            indicesList[currentIndex] = indexStack.top();
        }

        indexStack.push(currentIndex);
    }

    return indicesList;
}

// Time Complexity : O(n)
// Extra Space : O(n), where n is the length of the given array.
long long getMaxArea(long long arr[], int n)
{
    // Validate input parameters.
    if((arr == nullptr) || (n < 1))
    {
        return 0;
    }

    long long maxArea = 0;

    std::vector<int> smallerToLeftList = nextSmallerElementToLeft(arr, n);
    std::vector<int> smallerToRightList = nextSmallerElementToRight(arr, n);

    for(int index = 0; index < n; ++index)
    {
        maxArea = std::max(maxArea, 
                          (smallerToRightList[index] - smallerToLeftList[index] - 1) * arr[index]);
    }

    return maxArea;
}
