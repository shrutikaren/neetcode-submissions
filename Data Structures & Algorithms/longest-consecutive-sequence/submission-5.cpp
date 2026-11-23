class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int finalResult = 0; 
        int currentStreak = 0;
        set<int> sortedNums;

        for (int num: nums) {
            sortedNums.insert(num);
        }


        for (auto it = sortedNums.begin(); it != sortedNums.end(); it ++) {
            if (it != sortedNums.begin() && (*it - *prev(it)) == 1) {
                currentStreak +=1;
            }
            else {
                currentStreak = 1;
            }

            finalResult = max(finalResult, currentStreak);
        }

        return finalResult; 
    }
};
