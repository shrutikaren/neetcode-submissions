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
        int currentPosition = 0;
        int hashtagIndex = 0;

        while  (currentPosition < s.length()) {
            hashtagIndex = currentPosition;

            while (s[hashtagIndex] != '#') {
                hashtagIndex++;
            }

            int numOfCharacters = stoi(s.substr(
             currentPosition,
                hashtagIndex - currentPosition
            ));

            finalResult.push_back(s.substr(hashtagIndex + 1, numOfCharacters));

         currentPosition = hashtagIndex + 1 + numOfCharacters;
        }

        return finalResult;
    }
};
