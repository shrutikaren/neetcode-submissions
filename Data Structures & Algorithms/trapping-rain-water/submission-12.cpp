class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeight = 0;
        int totalBoundaryArea = 0;
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);

        for (int h: height){
            if (h > maxHeight){
                maxHeight = h;
            }
        }

        totalBoundaryArea = height.size() * maxHeight; 

        // minus the actual bars from the area 
        for (int h: height){
            totalBoundaryArea -= h;
        }

        int currentLeftMax = 0;
        for (int i = 0; i < height.size(); i ++){
            currentLeftMax = max(currentLeftMax, height[i]);
            leftMax[i] = currentLeftMax;
        }

        int currentRightMax = 0;
        for (int i = height.size() - 1; i >= 0; i --){
            currentRightMax = max(currentRightMax, height[i]);
            rightMax[i] = currentRightMax;
        }

        for (int i = 0; i < height.size(); i ++) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            int minusWater = maxHeight - waterLevel;
            totalBoundaryArea -= minusWater;
        }

        return totalBoundaryArea;
    }
};
