#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tem(nums);
        sort(nums.begin(), nums.end());
        int pl = 0, pr = nums.size()-1;
        int sum = 0;
        vector<int> answer;
        while (1){
            sum = nums[pl] + nums[pr];
            if (sum == target){
                // answer.push_back(pl);
                // answer.push_back(pr);
                break;
            }
            else if (sum < target){
                pl++;
            }
            else{
                pr--;
            }
        }
        for (int i=0; i<tem.size(); i++){
            if (tem[i] == nums[pl] || tem[i] == nums[pr]){
                answer.push_back(i);
            }
        }
        return answer;
    }
};
