class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        string res  = "";
        sort(str.begin(), str.end());
        string a = str[0];
        string b = str[str.size() - 1];
        
        for(int i = 0; i < a.size(); i++){
            if(a[i]==b[i]){
                res += a[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};