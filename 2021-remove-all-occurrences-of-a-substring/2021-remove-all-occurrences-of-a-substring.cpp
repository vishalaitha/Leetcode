class Solution {
public:
    bool check(stack<char> st, string &part){
        int n=part.size()-1;
        while(!st.empty() &&n>=0 && st.top()==part[n]){
            st.pop();
            n--;
        }
        return n<0?true:false;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n=part.size();
        for(int j=0;j<s.size();j++){
            st.push(s[j]);
            if(st.size()>=n){
                if(check(st,part)){
                    int n1=part.size();
                    while(n1--)
                        st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};