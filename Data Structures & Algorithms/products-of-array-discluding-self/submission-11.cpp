class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> finalResult(nums.size(), 1);
        vector<int> prefix(nums.size(), 1);
        vector<int> postfix(nums.size(), 1); 
        /*
        1 | 2 | 4 | 6 
        prefix: 1 | 2 | 8 | 48
        postfix: 48 | 48 | 24 | 6
        output: 48 | 24 | 12 | 8
        We just need a prefix times the postfix to get the value for that index 
        */
        
        prefix[0] = nums[0];
        postfix[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = 1; i < nums.size(); i ++ ){
            prefix[i] = prefix[i - 1] * nums[i]; 
        }

        for (int i = nums.size() - 2; i >= 0; i --){
            postfix[i] = postfix[i + 1] * nums[i];
        }

        finalResult[0] = postfix[1];
        finalResult[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i ++){
            finalResult[i] = prefix[i - 1] * postfix[i + 1];
        }
        return finalResult;
    }
};
