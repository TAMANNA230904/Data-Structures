The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. 
  Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

  class Solution {
public:

    string countAndSay(int n) {
        if (n == 1) {
        return "1";
    }

    string prev = countAndSay(n - 1);
    string result = "";
    int count = 1;

    for (int i = 0; i < prev.length(); i++) {
        if (i + 1 < prev.length() && prev[i] == prev[i + 1]) {
            count++;
        } else {
            result += to_string(count) + prev[i];
            count = 1;
        }
    }

    return result;
    }
};
