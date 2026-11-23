class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> pairedAnswer;

        int j = 0, k = numbers.size() - 1;
        while (j < numbers.size() - 1 && k > 0){
            if (numbers[k] + numbers[j] > target) {
                k --;
            }
            else if (numbers[k] + numbers[j] < target){
                j ++;
            }
            else {
                pairedAnswer.push_back(j + 1);
                pairedAnswer.push_back(k + 1);
                return pairedAnswer;
            }
        }
        return pairedAnswer;
    }
};
