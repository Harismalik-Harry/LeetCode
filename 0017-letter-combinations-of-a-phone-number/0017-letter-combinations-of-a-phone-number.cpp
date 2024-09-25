class Solution {
public:
    string getLetters(char digit) {
        if (digit == '2') return "abc";
        if (digit == '3') return "def";
        if (digit == '4') return "ghi";
        if (digit == '5') return "jkl";
        if (digit == '6') return "mno";
        if (digit == '7') return "pqrs";
        if (digit == '8') return "tuv";
        if (digit == '9') return "wxyz";
        return "";
    }

    void calculateCombinations(string &subset, int index, vector<string> &arr, const string &digits) {
        if (subset.size() == digits.length()) {
            arr.push_back(subset);
            return;
        }

        string letters = getLetters(digits[index]);
        for (int i = 0; i < letters.length(); i++) {
            subset.push_back(letters[i]);
            calculateCombinations(subset, index + 1, arr, digits);
            subset.pop_back();  
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> combinations;
        string subset;
        calculateCombinations(subset, 0, combinations, digits);
        return combinations;
    }
};
