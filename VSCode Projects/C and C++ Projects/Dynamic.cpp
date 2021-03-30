#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main(){
    int capacity = 0;
    int n = 0;
    cin >> capacity >> n;
    int value[n + 1];
    int weight[n + 1];
    int dp[n + 1][capacity + 1];
    value[0] = weight[0] = 0;
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= capacity ; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n ; i++){
        cin >> weight[i]>>value[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1; j <= capacity ; j ++){
            if(j < weight[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - weight[i]] + value[i]);

            }
        }
    }
    for(int i = 1; i <= n ; i ++){
        for(int j = 1; j <= capacity ; j ++){
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<dp[n][capacity];
}