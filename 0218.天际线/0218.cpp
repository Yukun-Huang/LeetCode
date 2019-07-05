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
#include <functional>	// greater, less
#include <limits>

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

/*
 设计一个数据结构，对所有建筑物的左右端点进行存储、排序、查询 -> vector<vector<int>>
 设计一个数据结构，能够对当前的高度从大到小排序，且允许增添和删除元素 -> multiset实现最大堆
*/


struct points_cmp
{
    bool operator () (const vector<int>& a, const vector<int>& b)
    {
        if (a[0] < b[0])
            return true;
        else if (a[0] > b[0])
            return false;
        else
            return a[1] < b[1];
    }
};


class Solution {
public:

    vector<vector<int>> points;
    multiset<int, greater<>> heights;
    int h;
    vector<vector<int>> output;

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        for (auto building : buildings){
            points.push_back(vector<int>({building[0], 0, building[2]}));
            points.push_back(vector<int>({building[1], 1, building[2]}));
        }
        buildings.clear();

        sort(points.begin(), points.end(), points_cmp());

        for (auto point : points){
            if (!point[1]){
                heights.insert(point[2]);
            }
            else{
                heights.erase(heights.lower_bound(point[2]));
            }
            // get current height
            if (heights.empty())
                h = 0;
            else
                h = *(heights.begin());
            // save output
            if (!output.empty() && (output.back()[0] == point[0] || output.back()[1] == h))
                output.back()[1] = h;
            else{
                vector<int> tmp = {point[0], h};
                output.emplace_back(tmp);
            }
//            cout << point[0] << "  " << h << endl;
        }
        return output;
    }
};


int main() {

    ios_base::sync_with_stdio(false);

    vector<vector<int>> buildings = {{2,9,10}, {2,12,6}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};

    Solution S;
    S.getSkyline(buildings);
}
