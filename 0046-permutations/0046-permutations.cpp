class Solution {
public:
    vector<vector<int>> result;  // to store all permutations

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {           // base case: a full permutation
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);      // choose
            backtrack(nums, start + 1);      // explore
            swap(nums[start], nums[i]);      // un-choose (backtrack)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};