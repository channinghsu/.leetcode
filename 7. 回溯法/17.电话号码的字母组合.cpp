#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs",// 7
        "tuv", // 8
        "wxyz" // 9
    };

public:
    vector<string> result;
    string s;

    void dfs(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // Convert current digit character to integer
        const string& letters = letterMap[digit]; // Get corresponding letters

        for (char letter : letters) {
            s.push_back(letter);                // Add current letter to combination
            dfs(digits, index + 1);             // Recurse to next digit
            s.pop_back();                       // Backtrack to explore next letter
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;      // Return empty result if input is empty
        dfs(digits, 0);                         // Start DFS from index 0
        return result;
    }
};