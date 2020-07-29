// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,len=INT_MAX,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=s){
                len=min(len,i-l);
                sum-=nums[l];
                l++;
            }
        }
        if(len==INT_MAX){
            len=-1;
        }
        return len+1;
    }
};
