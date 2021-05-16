/*
5. Longest Palindromic Substring.

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Example 3:

Input: s = "a"
Output: "a"

Example 4:

Input: s = "ac"
Output: "a"
 
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case).

https://leetcode.com/problems/longest-palindromic-substring/
https://www.techiedelight.com/longest-palindromic-substring-non-dp-space-optimized-solution/
https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher.27s_algorithm
*/

// Time Complexity : O(n ^ 2) where n is the length of the given string.
// Extra Space : O(1)

// Helper method to identify the largest palindromic substring.
// Returns a pair of start index and length of the substring.
std::pair<int, int> calculateMaxLengthSubString(const std::string &str, bool bIsOddLengthSubString)
{
    int leftMostIndex = 0;

    int maxLength = 1;

    for(int currentIndex = 1; currentIndex < str.length(); ++currentIndex)
    {
        int currentCount = 1;
        int leftIndex = -1;

        // Check if two consecutive chars are same or not in case of palindromic substring with even length.
        if(false == bIsOddLengthSubString)
        {
            if(str[currentIndex] == str[currentIndex - 1])
            {
                ++currentCount;
                leftIndex = currentIndex - 2;

                if(maxLength < currentCount)
                {
                    leftMostIndex = currentIndex - 1;
                    maxLength = currentCount;
                }
            }
        }
        else
        {
            leftIndex = currentIndex - 1;
        }

        int rightIndex = currentIndex + 1;

        while((leftIndex >= 0) && (rightIndex < str.length()))
        {
            if(str[leftIndex] != str[rightIndex])
            {
                break;
            }

            --leftIndex;
            ++rightIndex;
            currentCount += 2;
        }

        ++leftIndex;
        --rightIndex;

        if (maxLength < currentCount)
        {
            leftMostIndex = leftIndex;
            maxLength = currentCount;
        }
    }

    return std::make_pair(leftMostIndex, maxLength);
}

std::string longestPalindrome(const std::string &str)
{
    std::pair<int, int> maxLenOddSubStrIndicesPair = calculateMaxLengthSubString(str, true);
    std::pair<int, int> maxLenEvenSubStrIndicesPair = calculateMaxLengthSubString(str, false);

    if(maxLenOddSubStrIndicesPair.second > maxLenEvenSubStrIndicesPair.second)
    {
        return str.substr(maxLenOddSubStrIndicesPair.first, maxLenOddSubStrIndicesPair.second);
    }
    else
    {
        return str.substr(maxLenEvenSubStrIndicesPair.first, maxLenEvenSubStrIndicesPair.second);
    }
}
