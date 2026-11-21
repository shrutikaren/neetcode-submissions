
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> elementToIterationNumber;
        vector<int> finalResult;

        for (int element : nums) {
            elementToIterationNumber[element] += 1;
        }

        // Sort in terms of frequency (highest first)
        vector<pair<int, int>> sortedElements(
            elementToIterationNumber.begin(),
            elementToIterationNumber.end()
        );

        sort(sortedElements.begin(), sortedElements.end(),
            [](auto a, auto b) {
                return a.second > b.second;
            });

        // Get the first k keys
        int i = 0;
        for (auto pair : sortedElements) {
            finalResult.push_back(pair.first);
            i++;
            if (i == k) {
                return finalResult;
            }
        }

        return finalResult;
    }
};
