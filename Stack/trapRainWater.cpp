/*
42. Trapping Rain Water.

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

Leetcode : https://leetcode.com/problems/trapping-rain-water/
*/

// Time Complexity : O(n)
// Extra Space : O(n), where n is the length of the list.

void getMaxNumToLeftList(const std::vector<int>& heightList, std::vector<int> &maxNumList)
{
    int leftMax = heightList[0];
    maxNumList[0] = leftMax;

    for(int index = 1; index < heightList.size(); ++index)
    {
        leftMax = std::max(leftMax, heightList[index]);
        maxNumList[index] = leftMax;
    }
}

 void getMaxNumToRightList(const std::vector<int>& heightList, std::vector<int> &maxNumList)
{
    int rightMax = heightList[heightList.size() - 1];
    maxNumList[heightList.size() - 1] = rightMax;

    for(int index = heightList.size() - 2; index >= 0; --index)
    {
        rightMax = std::max(rightMax, heightList[index]);
        maxNumList[index] = rightMax;
    }
}

int trapRainWater(const std::vector<int>& heightList)
{
    int heightListLength = heightList.size();

    // If the length of the heightList is less than 2, return 0.
    if(heightListLength < 2)
    {
        return 0;
    }

    std::vector<int> maxNumToLeftList(heightListLength);
    std::vector<int> maxNumToRightList(heightListLength);

    // Get lists of left and right max of a number.
    getMaxNumToLeftList(heightList, maxNumToLeftList);
    getMaxNumToRightList(heightList, maxNumToRightList);

    int totalTrappedWater = 0;

    // Calculate totalTrapped Water.
    for(int index = 0; index < heightListLength; ++index)
    {
        // For each index, the maximum height of trapped water will be the minimum of left and right
        // max value minus the height at that index.
        totalTrappedWater += std::min(maxNumToLeftList[index],maxNumToRightList[index]) - heightList[index];
    }

    return totalTrappedWater;
}
