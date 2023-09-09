class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            cout<<i<<" ";
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'){
                int j=i;
                string temp;
                 while(j>=0&&s[j]!=' '){
                     temp+=s[j];
                     j--;
                 }
                 while(j>=0&&s[j]==' ') j--;
                 reverse(temp.begin(),temp.end());
                 ans+=temp;
                 ans+=' ';
                 i=j+1;
            }
        }
        if(*ans.rbegin()==' ') ans.pop_back();
        return ans;
    }
};