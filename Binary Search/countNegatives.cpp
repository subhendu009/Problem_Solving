/*
1351. Count Negative Numbers in a Sorted Matrix.

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:

Input: grid = [[-1]]
Output: 1
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

Leetcode : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

// Time Complexity : O(m log n)
// Extra Space : O(1)

// Helper method to get count of -ve numbers in each row of the matrix.
// Use modified binary search.

int getNegativeNumbersFromRow(const std::vector<int> &numList)
{
    int lowIndex = 0;
    int highIndex = numList.size() - 1;
    int firstNegativeNumberIndex = -1;

    while(lowIndex <= highIndex)
    {
        int midIndex = lowIndex + (highIndex - lowIndex)/2;

        if(numList[midIndex] < 0)
        {
            firstNegativeNumberIndex = midIndex;
            highIndex = midIndex - 1;
        }
        else
        {
            lowIndex = midIndex + 1;
        }
    }

    if(-1 == firstNegativeNumberIndex)
    {
        return 0;
    }

    return numList.size() - firstNegativeNumberIndex;
}
    
  int countNegatives(const std::vector<std::vector<int>> &grid) 
  {
      int numRows = grid.size();

      if(0 == numRows)
      {
          return 0;
      }

      int numCols = grid[0].size();

      int numNegativeNumbers = 0;

      for(int row = 0; row < numRows; ++row)
      {
          numNegativeNumbers += getNegativeNumbersFromRow(grid[row]);
      }

      return numNegativeNumbers;
}
