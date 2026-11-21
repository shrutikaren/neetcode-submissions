class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> finalResult;
        unordered_map<string, vector<string>> sortedStringToList;

        for (string s: strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            sortedStringToList[sortedS].push_back(s);
        }

        for (auto pair: sortedStringToList){
            finalResult.push_back(pair.second);
        }

        return finalResult;
    }
};
