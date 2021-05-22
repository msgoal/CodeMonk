#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> x;
        int len = nums.size();
        if(nums.size() < 3) return x;
        sort(nums.begin(),nums.end());

        for(int i = 0;i < len - 2; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int l=i+1,u=len-1,s,c=0;
            while(l < u){
                s = nums[l] + nums[u];
                if(s == -nums[i]){
                    vector<int> row;
                    row.push_back(nums[i]);
                    row.push_back(nums[l]);
                    row.push_back(nums[u]);
                    x.push_back(row);
                    while(l < u && nums[l]==nums[l+1]){l++;}
                    while(l < u && nums[u]==nums[u-1]){u--;}
                    l++;
                }else if(s < -nums[i])
                    l++;
                else
                    u--;
            }
        }
        return x;
    }
};

int main_3sum(){
    Solution s;
    vector<int> nums{-1,0,1,2,-1,-4};
    //vector<int> nums{-1,0,1,0};
    //vector<int> nums{0,0,0,0};

    vector<vector<int>> x = s.threeSum(nums);

    for(auto i : x){
        for(auto j : i){
            cout<<"  "<<j;
        }
        cout<<endl;
    }
}
