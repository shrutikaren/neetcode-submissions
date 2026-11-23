class Solution {
public:
    int maxArea(vector<int>& heights) {
        // [1,7,2,5,4,7,3,6]
        // sort pair<int, int> with value and index 
        int maxArea = 0; 
        int i = 0; 
        int j = heights.size() - 1;
        while (i < heights.size() && j > 0){
            int minimumHeight = min(heights[i], heights[j]);
            int newMaxArea = (j - i) * minimumHeight;
            if (newMaxArea > maxArea){
                maxArea = newMaxArea;
            }
            
            // need a better judgement on when to move the pointers around 
            if (heights[j] > heights[i]){
                i++;
            }
            else if (heights[i] > heights[j]){
                j --;
            }
            else{
                i ++;
                j--;
            }
        }
                
        return maxArea;
    }
};
