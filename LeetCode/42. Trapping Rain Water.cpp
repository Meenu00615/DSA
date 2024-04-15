
class Solution {
public:
    int trap(vector<int>& heights)
{
    int left = 0, right = heights.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (heights[left] < heights[right]) {
            heights[left] >= left_max ? (left_max = heights[left]) : ans += (left_max - heights[left]);
            ++left;
        }
        else {
            heights[right] >= right_max ? (right_max = heights[right]) : ans += (right_max - heights[right]);
            --right;
        }
    }
    return ans;
}
};