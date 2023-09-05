class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({s[i],i});
            }
            else if(st.top().first=='('&&s[i]==')'){
                st.pop();
            }
            else{
                st.push({s[i],i});
            }
        }
        vector<pair<int,int>>v;
        int prev=n;
        int maxi=0;
        if(st.empty()){
            maxi=n;
        }
        while(!st.empty()){
            maxi=max(maxi,prev-st.top().second-1);
            prev=st.top().second;
            v.push_back(st.top());
            st.pop();
        }

        int maxi2=0;
        int prevhere=0;
        reverse(v.begin(),v.end());
        for(auto &it:v) cout<<it.first<<" "<<it.second<<endl;
        for(int i=0;i<v.size();i++){
            cout<<prevhere<<" "<<v[i].second<<endl;
            maxi2=max(maxi2,v[i].second-(prevhere));
            prevhere=v[i].second+1;
        }

        return max(maxi2,maxi);
    }
};