class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> elementToIterationNumber;
        vector<int> finalResult;

        for (int element : nums){
            elementToIterationNumber[element] += 1;
        }

        // sorted it in terms of the values
        vector<pair<int, int>> elementToIterationNumberVector(elementToIterationNumber.begin(), elementToIterationNumber.end());

        sort(elementToIterationNumberVector.begin(), elementToIterationNumberVector.end(), [] (auto a, auto b){
            return a.second > b.second;
        });

        int i = 1;
        // for loop k times and get the first k keys 
        for (auto pair: elementToIterationNumberVector){
            finalResult.push_back(pair.first);
            if (i == k){
                return finalResult;
            }
            i++;
        }
        return finalResult;
    }
};