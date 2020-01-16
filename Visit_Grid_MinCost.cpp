#include<bits/stdc++.h>
using namespace std;
#define int long long int
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

//4 4
//1 2 1 3
//2 1 1 2
//1 2 3 4
//7 5 4 1
//2 2

int32_t main(){
    fast();
    int row, col; cin>>row>>col;
    int cost[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>cost[i][j];
        }
    }
    int minCost[row][col];
    minCost[0][0] = cost[0][0];
    //find min cost for 1st row
    for(int i=1; i<col; i++){
        minCost[0][i] = minCost[0][i-1] + cost[0][i];
    }
    //find min cost for 1st col
    for(int i=1; i<row; i++){
        minCost[i][0] = minCost[i-1][0] + cost[i][0];
    }
    //now using minCost of 1st row and 1st col calculate minCost of all row and col
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            minCost[i][j] = min(minCost[i-1][j], minCost[i][j-1]) + cost[i][j]; //only for down and right
            //minCost[i][j] = min(minCost[i-1][j-1], min(minCost[i-1][j], minCost[i][j-1])) + cost[i][j];
                        //for down, right and diagonal

        }
    }
    int x,y; cin>>x>>y; //0 based index
    cout<<minCost[x][y]<<"\n";

    return 0;
}
