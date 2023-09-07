#define pb push_back
#define pp pop_back
class Solution {
public:
    vector<vector<int>> ans1;
    set<vector<int>> ans;
    void solve(int ind,vector<int>& candidates, int target, vector<int> &current){
        if(target==0){
            vector<int>copy=current;
            sort(copy.begin(),copy.end());
            ans.insert(copy);
            return;
        }
        if(target<0) return;
        for(int i=ind;i<candidates.size();i++){
                current.pb(candidates[i]);
                solve(ind,candidates,target-candidates[i],current);
                current.pp();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //int sum=0;
        vector<int> current;
        //sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,current);
        for(auto i :ans)ans1.pb(i);
        return ans1;
    }
};