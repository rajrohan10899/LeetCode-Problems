class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size()-1, maxArea = 0;

        while(left < right) {

            // int h = min(height[left], height[right]); // 7
            // int w = right - left; // 7
            // int currArea = w * h; //49

            int currArea = min(height[left], height[right]) * (right - left);

            maxArea = max(maxArea, currArea); // 49

            if(height[left] > height[right]) {
                right--; 
            }
            else {
                left++;
            }
        }
        return maxArea;
    }
};

/*
Approach (Two Pointer)

Time Complexity: O(N)
Space Complexity: O(1)

Step 1:
Initialize two pointers:
left = 0 and right = height.size() - 1.

Step 2:
Calculate area using:
area = min(height[left], height[right]) * (right - left)

Step 3:
Update maxArea with maximum value.

Step 4:
Move the pointer with smaller height
because smaller height limits the container.

Step 5:
Repeat until left < right and return maxArea.

*/