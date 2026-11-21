class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elementToIterationNumber;
        vector<int> finalResult;

        for (int element : nums){
            elementToIterationNumber[element] += 1;
        }

        vector<pair<int, int>> vectorOfElementToIterationNumber;
        for (auto pair: elementToIterationNumber){
            vectorOfElementToIterationNumber.push_back({pair.second, pair.first});
        }
        sort(vectorOfElementToIterationNumber.rbegin(), vectorOfElementToIterationNumber.rend());

        int i = 1;
        // for loop k times and get the first k keys 
        for (auto pair: vectorOfElementToIterationNumber){
            finalResult.push_back(pair.second);
            if (i == k){
                return finalResult;
            }
            i++;
        }
        return finalResult;
    }
};