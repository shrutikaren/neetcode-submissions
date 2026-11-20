class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ourmap;
        vector<vector<string>> finalresult;
        for (string s: strs){
            string sorteds = s;
            sort(sorteds.begin(), sorteds.end());
            ourmap[sorteds].push_back(s);
        }

        for (auto s: ourmap){
            finalresult.push_back(s.second);
        }

        return finalresult;
    }
};
