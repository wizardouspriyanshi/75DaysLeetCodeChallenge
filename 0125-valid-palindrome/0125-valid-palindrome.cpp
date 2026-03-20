#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right) {

            // skip non-alphanumeric from left
            while(left < right && !isalnum(s[left])) {
                left++;
            }

            // skip non-alphanumeric from right
            while(left < right && !isalnum(s[right])) {
                right--;
            }

            // compare after converting to lowercase
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};