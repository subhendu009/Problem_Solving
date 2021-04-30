/*
Binary Array Sorting.

Given a binary array A[] of size N. The task is to arrange the array in increasing order.
Note: The binary array contains only 0  and 1.
 
Example 1:

Input:
1 0 1 1 0

Output: 
0 0 1 1 1

Explanation: 
After arranging the elements in increasing order, elements will be as 0 0 1 1 1.

Example 2:

Input:
1 0 1 1 1 1 1 0 0 0

Output: 
0 0 0 0 1 1 1 1 1 1

Explanation: 
After arranging the elements in increasing orde, elements will be 0 0 0 0 1 1 1 1 1 1.

Geeksforgeeks: https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1#

*/

// Time Complexity : O(N) where N is the length of the given array
// Extra Space : O(1)

void sortZeroesOnes(std::vector<int> &numList)
{
   int lowIndex = 0;
   int midIndex = 0;

   while(midIndex < numList.size())
   {
       switch (numList[midIndex])
       {
           case 0:
           {
               //std::swap(numList[lowIndex], numList[midIndex]);
               int temp = numList[lowIndex];
               numList[lowIndex] = numList[midIndex];
               numList[midIndex] = temp;

               ++lowIndex;
               ++midIndex;
               break;
           }

           case 1:
           {
               ++midIndex;
               break;
           }
       }
   }
}
