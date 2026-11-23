class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniquePairs;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k && j < nums.size() && k > 0){
                if ((nums[i] + nums[j] + nums[k]) < 0){
                    j ++;
                }
                else if ((nums[i] + nums[j] + nums[k]) > 0){
                    k --;
                }
                else if ((nums[i] + nums[j] + nums[k]) == 0){
                    vector<int> iterResult;
                    iterResult.push_back(nums[i]);
                    iterResult.push_back(nums[j]);
                    iterResult.push_back(nums[k]);
                    uniquePairs.insert(iterResult);
                    j ++;
                    k --;
                }
            }
        }
        vector<vector<int>> finalResult(uniquePairs.begin(), uniquePairs.end());
        return finalResult;
    }
};
