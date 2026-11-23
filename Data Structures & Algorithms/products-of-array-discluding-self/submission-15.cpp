class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> postfix(nums.size(), 1);
        vector<int> output(nums.size(), 1);

        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i ++){
            prefix[i] = nums[i] * prefix[i-1];
        }

        postfix[nums.size()-1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i --){
            postfix[i] = postfix[i + 1] * nums[i];
        }

        output[0] = postfix[1];
        output[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i <= nums.size() - 2; i ++){
            output[i] = prefix[i - 1] * postfix[i + 1];
        }

        return output;
    }
};
