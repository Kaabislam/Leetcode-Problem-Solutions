class Solution {
public:
    int numSquares(int n) {
        int a[n+5];
        for(int i = 1;i <= n;i++) a[i] = INT_MAX;
        for(int  i = 0;;i++){
            if(i*i > n) break;
            a[i*i] = 1;
        }
        for(int i = 2;i <= n;i++){
            for(int j = i-1;j >= i/2;j--){
                //cout << i << " " << j << endl;
                int c1 = a[j],b = i-j;
                int c2 = a[b];
                
                a[i] = min(a[i],c1+c2);
            }
        }
        // for(int i = 1;i <= 10;i++){
        //     cout << i << " " << a[i] << endl;
        // }
        
        return a[n];
    }
};