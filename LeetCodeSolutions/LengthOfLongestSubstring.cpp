#include <string>
#include <set>
#include <assert.h>
#include <iostream>

class Solution {
public:
    static int lengthOfLongestSubstring1(std::string s) {
        if (s.size() == 1) return 1;
        std::set<char> substringChars;
        int size = 0;
        int maxSize = 0;
        std::string::size_type i, j;
        for (i = 0; i < s.size() - 1; i++) {
            substringChars.insert(s[i]);
            size++;
            for (j = i + 1; j < s.size(); j++) {
                bool breakingOut = false;
                if (substringChars.find(s[j]) != substringChars.end()) {
                    maxSize = size > maxSize ? size : maxSize;
                    substringChars.clear();
                    size = 0;
                    breakingOut = true;
                    break;
                }
                if (breakingOut) break;
                substringChars.insert(s[j]);
                size++;
            }
            size = 0;
        }
        
        return maxSize;
    }
    
    static int lengthOfLongestSubstring2(std::string s) {
        int sLength = static_cast<int>(s.size());
        if (sLength == 1) return  1;
        std::set<char> substringChars;
        int i = 0, j = 0, maxSize = 0;
        while (i < sLength && j < sLength) {
            if (substringChars.find(s[j]) != substringChars.end()) {
                while (s[i] != s[j]) {
                    if (s[i] != s[j]) substringChars.erase(s[i]);
                    i++;
                }
                i++;
            } else {
                substringChars.insert(s[j]);
                maxSize = std::max(maxSize, static_cast<int>(substringChars.size()));
            }
            j++;
        }
        return maxSize;
    }
};

void TestCase1(Solution &sln) {
    std::string testString = "pwwkew";
    if (sln.lengthOfLongestSubstring1(testString) == sln.lengthOfLongestSubstring2(testString))
        std::cout << "PASSED\n" << std::endl;
    else
        std::cout << "FAILED\n" << std::endl;
}

void TestCase2(Solution &sln) {
    std::string testString = "pwwabqckew";
    if (sln.lengthOfLongestSubstring1(testString) == sln.lengthOfLongestSubstring2(testString))
        std::cout << "PASSED\n" << std::endl;
    else
        std::cout << "FAILED\n" << std::endl;
}

void TestCase3(Solution &sln) {
    std::string testString = "abcabcbb";
    if (sln.lengthOfLongestSubstring1(testString) == sln.lengthOfLongestSubstring2(testString))
        std::cout << "PASSED\n" << std::endl;
    else
        std::cout << "FAILED\n" << std::endl;
}

void TestCase4(Solution &sln) {
    std::string testString = "aaaaa";
    if (sln.lengthOfLongestSubstring1(testString) == sln.lengthOfLongestSubstring2(testString))
        std::cout << "PASSED\n" << std::endl;
    else
        std::cout << "FAILED\n" << std::endl;
}

void TestCase5(Solution &sln) {
    std::string testString = " ";
    if (sln.lengthOfLongestSubstring1(testString) == sln.lengthOfLongestSubstring2(testString))
        std::cout << "PASSED\n" << std::endl;
    else
        std::cout << "FAILED\n" << std::endl;
}

void TestCase6(Solution &sln) {
    std::string testString = "au";
    int result1 = sln.lengthOfLongestSubstring1(testString);
    int result2 = sln.lengthOfLongestSubstring2(testString);
    if (result1 == result2)
        std::cout << "PASSED\n" << std::endl;
    else
        std::cout << "FAILED\n" << std::endl;
}

int main() {
    Solution sln;
//    TestCase1(sln);
//    TestCase2(sln);
//    TestCase3(sln);
//    TestCase4(sln);
//    TestCase5(sln);
    TestCase6(sln);
    return 0;
}
