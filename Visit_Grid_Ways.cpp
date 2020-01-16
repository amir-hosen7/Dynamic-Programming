#include<bits/stdc++.h>
using namespace std;
#define int long long int
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int32_t main(){
    fast();
    int row, col; cin>>row>>col;
    int ways[row][col];
    ways[0][0] = 1;
    //fill up 1st row
    for(int i=1; i<col; i++){
        ways[0][i] = 1;
    }
    //fill up 1st col
    for(int i=1; i<row; i++){
        ways[i][0] = 1;
    }
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            ways[i][j] = ways[i-1][j] + ways[i][j-1];
        }
    }
    int x, y; cin>>x>>y;    //0 based index
    cout<<ways[x][y]<<"\n";
    return 0;
}


