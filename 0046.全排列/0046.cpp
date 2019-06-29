class Solution {
    int n = 0;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> output;
        backtrack(nums, output, 0);
        return output;
    }
    
    void swap(vector<int>& nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>>& output, int first){
        if(first == n)
            output.push_back(nums);
        for(int i=first; i<n; ++i){
            swap(nums, first, i);
            backtrack(nums, output, first+1);
            swap(nums, first, i);
        }
    }
};
