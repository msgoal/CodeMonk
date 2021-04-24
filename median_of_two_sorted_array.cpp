#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num1len = nums1.size(),num2len = nums2.size();
        int n1cnt=0,n2cnt=0,s = (num1len+num2len),x=s/2,res=0;
        if(s == 0) return 0;
        double *merged = new double[num1len+num2len];
        while(true){

            if(n1cnt < num1len) {
                if(n2cnt >= num2len){
                    merged[res++] = nums1[n1cnt++];
                }else
                if (nums1[n1cnt] <= nums2[n2cnt] )
                    merged[res++] = nums1[n1cnt++];
            }

            if(n2cnt < num2len) {
                if(n1cnt >= num1len) {
                    merged[res++] = nums2[n2cnt++];
                }else
                if(nums2[n2cnt] <= nums1[n1cnt])
                    merged[res++] = nums2[n2cnt++];
            }

            if(res > x){
                break;
            }
        }

        if(s & 1){
            return (double)merged[x];
        }else {
            return (double) (merged[x] + merged[x - 1]) / 2.0;
        }
    }

    double findMedianSortedArraysrec(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int x = nums1.size();
        int y = nums2.size();

        int high = x;
        int low = 0;
        while(low<=high){
            int divideX = low + (high - low)/2;
            int divideY = (x + y + 1)/2 - divideX;

            double maxLeftX = (divideX == 0 ? INT_MIN : nums1[divideX-1]);
            double minRightX = (divideX == x ? INT_MAX : nums1[divideX]);

            double maxLeftY = (divideY == 0 ? INT_MIN : nums2[divideY-1]);
            double minRightY = (divideY == y ? INT_MAX : nums2[divideY]);

            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((x+y)%2==0){
                    return (max(maxLeftX,maxLeftY) + min(minRightX,minRightY))/2.0;
                }else{
                    return max(maxLeftX,maxLeftY);
                }
            }else if(maxLeftX>minRightY){
                high = divideX-1;
            }else{
                low = divideX +1;
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {},nums2 = {1,2,3,4,5};
    cout<<s.findMedianSortedArrays(nums1,nums2);
}