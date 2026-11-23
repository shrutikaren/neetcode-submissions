class Solution {
public:
    bool isPalindrome(string s) {
        string newS;

        for (char c: s){
            if (isalnum(static_cast<unsigned char> (c))){
                newS += tolower(static_cast<unsigned char> (c));
            }
        }

        for (int i = 0, j = newS.length() - 1; i < j; i ++, j --){
            if (newS[i] != newS[j]){
                return false;
            }
        }
        return true;
    }
};
