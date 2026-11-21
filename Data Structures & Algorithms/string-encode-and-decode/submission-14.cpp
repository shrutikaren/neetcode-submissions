class Solution {
public:

    string encode(vector<string>& strs) {
        string finalResult;
        for (string s: strs){
            finalResult += to_string(s.length()) + "#" + s;
        }
        return finalResult;
    }

     vector<string> decode(string s) {
        vector<string> finalResult;
        int numNumberOfCharactersPreviousWord = 0;
        int hashtagIndex = 0;

        while (numNumberOfCharactersPreviousWord < s.length()) {
            hashtagIndex = numNumberOfCharactersPreviousWord;

            while (s[hashtagIndex] != '#') {
                hashtagIndex++;
            }

            int numOfCharacters = stoi(s.substr(
                numNumberOfCharactersPreviousWord,
                hashtagIndex - numNumberOfCharactersPreviousWord
            ));

            finalResult.push_back(s.substr(hashtagIndex + 1, numOfCharacters));

            numNumberOfCharactersPreviousWord = hashtagIndex + 1 + numOfCharacters;
        }

        return finalResult;
    }
};
