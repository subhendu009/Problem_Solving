/*
Search a number in an nearly sorted and rotated array.

A nearly sorted array has all its numbers sorted and except the numbers which have been placed in 
either i - 1  or i + 1 position w.r.t to their original position i.

As for example, [1,2,3,4,5] is a sorted array.

Now, if we place 2 in place of 1 or 3, [2,1,3,4,5] is nearly sorted.
Similarly we can get [2,1,3,5,4] as nearly sorted.

Now, let us rotate it towards left by 2 positions to get a nearly sorted and rotated array as [3,5,4,2,1].

*/

// Time Complexity : O(log n) where n is the length of the given array.
// Extra Space : O(1)

int searchInNearlySortedRotatedArray(const std::vector<int>& numList, int key)
{
	int lowIndex = 0;
	int highIndex = numList.size() - 1;

	while (lowIndex <= highIndex)
	{
		int midIndex = lowIndex + (highIndex - lowIndex) / 2;

    // Check if we have found the key in middleIndex.
    // We also need to check if the key should have been at middleIndex position, but has been placed before or after that.
		if (numList[midIndex] == key)
		{
			return midIndex;
		}

    // <-- Only this part of code has been added w.r.t to the code for searchInSortedRotatedArray()
		if ((midIndex > lowIndex) && (numList[midIndex - 1] == key))
		{
			return midIndex - 1;
		}

		if ((midIndex < highIndex) && (numList[midIndex + 1] == key))
		{
			return midIndex + 1;
		}
    // -->
    
    // Check which half of the array is nearly sorted.
		if (numList[lowIndex] <= numList[midIndex])
		{
			if ((numList[lowIndex] <= key) && (key < numList[midIndex]))
			{
				highIndex = midIndex - 2;
			}
			else
			{
				lowIndex = midIndex + 2;
			}
		}
		else
		{
			if ((numList[midIndex] < key) && (key <= numList[highIndex]))
			{
				lowIndex = midIndex + 2;
			}
			else
			{
				highIndex = midIndex - 2;
			}
		}
	}

	return -1;
}
