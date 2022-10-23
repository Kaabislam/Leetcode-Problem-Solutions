class Solution {
public:
    bool check(unordered_map<char,int>m1,unordered_map<char,int>m2){
        bool f = true;
        for(auto i:m2){
            if(!m1.count(i.first)) f = false;
            else{
                if(m1[i.first]  < i.second) f = false;
            }
            if(!f) break;
        }
        return f;
    }
    void printmap(map<char,int>m){
        for(auto i:m){
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        unordered_map<char,int>mt,ms;
        for(int i = 0;i < t.length();i++){
            mt[t[i]] += 1;
        }
        int l = 0,r = 0,c1 = 0,c2 = mt.size();
        int a = INT_MAX;
        pair<int,int>p;
        for(int i = 0;i < s.length();i++){
            ms[s[i]] += 1;

            if(ms[s[i]] == mt[s[i]]) c1++;
            if(c1 == c2){
               for(int j = l;j <= i;j++){
                   //cout << i << " " << l << endl;
                   if(c1 == c2 and (i-j+1 < a)){
                       a = i-j+1;
                       p = {i,j};
                   }
                   ms[s[j]] -= 1;
                   if(ms[s[j]] < mt[s[j]]) c1--;
                   if(c1 != c2){
                       l = j+1;
                       break;
                   }
               }
            }
            
        }
        if(a == INT_MAX) return "";
        string res = "";
        res = s.substr(p.second,a);
       
        
        return res;
    }
};