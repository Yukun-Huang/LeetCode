#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
#include <functional>


#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;


class Solution_slow {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> sol(3, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < n ; ++i){
            sol[1] = nums[i];
            left = i - 1;
            right = i + 1;
            while(1){
                if (left < 0 || right >= n)
                    break;
                int tmp = nums[left] + nums[right] + nums[i];
                if(!tmp){
                    sol[0] = nums[left];
                    sol[2] = nums[right];
                    output.push_back(sol);
                    left--;
                    right++;
                }
                else if(tmp > 0){
                    left--;
                }
                else{
                    right++;
                }
            }
        }
        // 去重复
        sort(output.begin(), output.end());
        output.erase(unique(output.begin(), output.end()), output.end());
        return output;
    }
};


class Solution_complex {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> sol(3, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < n ; ++i){
            if (i >= 2 && nums[i] == nums[i-2])
                continue;
            sol[1] = nums[i];
            left = i - 1;
            right = i + 1;
            while(1){
                if (left < 0 || right >= n)
                    break;
                int tmp = nums[left] + nums[right] + nums[i];
                if(!tmp){
                    sol[0] = nums[left];
                    sol[2] = nums[right];
                    output.push_back(sol);
                    //------ special case ------
                    if(nums[i] == nums[i-1] && sol[0] != sol[1]){
                        output.pop_back();
                        break;
                    }
                    //--------------------------
                    do{
                        left--;
                        if (left < 0) break;
                    }while(nums[left] == nums[left+1]);
                    do{
                        right++;
                        if (right >= n-1) break;
                    }while(nums[right] == nums[right+1]);
                }
                else if(tmp > 0){
                    left--;
                }
                else{
                    right++;
                }
            }
        }
        return output;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> sol(3, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < n - 2 ; ++i){
            if(nums[0] > 0) break;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            sol[0] = nums[i];
            left = i + 1;
            right = n - 1;
            while(left < right){
                int tmp = nums[left] + nums[right] + nums[i];
                if(!tmp){
                    sol[1] = nums[left];
                    sol[2] = nums[right];
                    output.push_back(sol);
                    do{
                        left++;
                        if (left < 0 || left > n-1) break;
                    }while(nums[left] == nums[left-1]);
                    do{
                        right--;
                        if (right < 0 || right > n-2) break;
                    }while(nums[right] == nums[right+1]);
                }
                else if(tmp > 0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return output;
    }
};


Solution S;

int main(){
    vector<int> input = {-1, 0, 1, 2, -1, 4};
//    vector<int> input = {0, 0, 0};
//    vector<int> input = {-3, -3, -1, -1, 0, 1, 1, 2, 2, 3, 3};
//    vector<int> input = {-3, -3, -3, -1, -1, -1, 0, 1, 1, 1, 1, 2, 2, 3, 3};
//    vector<int> input(9999, 0);
    vector<vector<int>> answer = S.threeSum(input);

    cout << "done" << endl;
}

