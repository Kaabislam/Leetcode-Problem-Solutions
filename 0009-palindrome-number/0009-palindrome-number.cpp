class Solution {
public:
    bool isPalindrome(int x) {
        string s = "";
        while(x){
            s += to_string(x%10);
            x/=10;
        }
        for(int i = 0;i < (s.length()/2);i++){
            int x = s.length()-i-1;
            if(s[i] != s[x]) return false;
        }
        return true;
    }
};