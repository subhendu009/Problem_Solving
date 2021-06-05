/*
85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 
Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6

Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = []
Output: 0

Example 3:

Input: matrix = [["0"]]
Output: 0

Example 4:

Input: matrix = [["1"]]
Output: 1

Example 5:

Input: matrix = [["0","0"]]
Output: 0
 
Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

Leetcode : https://leetcode.com/problems/maximal-rectangle/
*/

// Time Complexity : O(m * n)
// Extra Space : O(n), where the matrix has m rows and n columns.

void getLeftSmallerNumList(const std::vector<int> &heightList, std::vector<int> &leftSmallerNumList)
{
    std::stack<int> indicesStack;
    int heightListLength = heightList.size();

    for(int index = 0; index < heightListLength; ++index)
    {
        while(!indicesStack.empty() && heightList[indicesStack.top()] >= heightList[index])
        {
            indicesStack.pop();
        }

        if(indicesStack.empty())
        {
            leftSmallerNumList[index] = -1;
        }
        else
        {
            leftSmallerNumList[index] = indicesStack.top();
        }

        indicesStack.push(index);
    }
}

void getRightSmallerNumList(const std::vector<int> &heightList, std::vector<int> &rightSmallerNumList)
{
    std::stack<int> indicesStack;
    int heightListLength = heightList.size();

    for(int index = heightListLength - 1; index >= 0; --index)
    {
        while(!indicesStack.empty() && heightList[indicesStack.top()] >= heightList[index])
        {
            indicesStack.pop();
        }

        if(indicesStack.empty())
        {
            rightSmallerNumList[index] = heightListLength;
        }
        else
        {
            rightSmallerNumList[index] = indicesStack.top();
        }

        indicesStack.push(index);
    }
}

// Helper method to find maximum rectangular area in histogram.
int maxAreaRectangleInHistogram(const std::vector<int> &heightList)
{
    int maxRectSize = 0;

    int heightListLength = heightList.size();

    std::vector<int> smallerNumToLeftList(heightListLength);
    std::vector<int> smallerNumToRightList(heightListLength);

    // Get lists of indices of smaller numbers to left and right.
    getLeftSmallerNumList(heightList, smallerNumToLeftList);
    getRightSmallerNumList(heightList, smallerNumToRightList);

    // Calculate rectangular area for each index and calculate maximum.
    for(int index = 0; index < heightListLength; ++index)
    {
        int currentRectSize = (smallerNumToRightList[index] - smallerNumToLeftList[index] - 1) * heightList[index];
        if(maxRectSize < currentRectSize)
        {
            maxRectSize = currentRectSize;
        }
    }

    return maxRectSize;
}

int maximalRectangle(std::vector<std::vector<char>>& matrix) 
{
    int maxRowNum = matrix.size();
    if(0 == maxRowNum)
    {
        return 0;
    }

    int maxColumnNumber = matrix[0].size();

    int maxRectArea = 0;

    std::vector<int> heightList(maxColumnNumber, 0);

    for(int rowNum = 0; rowNum < maxRowNum; ++rowNum)
    {
        // Build histogram.
        for(int colNum = 0; colNum < maxColumnNumber; ++colNum)
        {
            // If we get a '0', we will neglect that column height,
            // as we are always considering same base.
            if('0' == matrix[rowNum][colNum])
            {
                heightList[colNum] = 0;
            }
            else
            {
                heightList[colNum] += 1;
            }
        }

        // Calculate maxumum rectangular area in this histogram.
        maxRectArea = std::max(maxRectArea, maxAreaRectangleInHistogram(heightList));
    }

    return maxRectArea;
}
