
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }
        unordered_map<int,int> mpp;
        for(int i = 0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int cnt = 0;
        if(k==0){
            for(auto it: mpp)
            {
               if(it.second>1) 
               {
                   cnt++; 
            }
            }
        
            return cnt;
        }
        for(auto it : mpp)
        {
            if(mpp.count(it.first-k)) cnt++;
        }
        return cnt;
    }
    
};