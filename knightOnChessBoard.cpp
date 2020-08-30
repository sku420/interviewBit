#include<bits/stdc++.h>

vector<pair<int,int> >moves({
    {1,2},
    {2,1},
    {2,-1},
    {1,-2},
    {-1,2},
    {-2,1},
    {-1,-2},
    {-2,-1}
});

bool isPossible(int A, int B, int x, int y){
    return x>=1 and x<=A and y>=1 and y<=B; //possible moves
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    queue<pair<pair<int,int>,int> >q;
    q.push({{C,D},0});
    vector<vector<bool> >marked(A+1,vector<bool>(B+1,false));
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if(x==E and y==F){ //reached
            return count;
        }
        marked[x][y] = true;
        for(auto i:moves){
            int currX = x+i.first;
            int currY = y+i.second;
            if(isPossible(A,B,currX,currY)){
                if(!marked[currX][currY]){
                    marked[currX][currY] = true;
                    q.push({{currX,currY},count+1});
                }
            }
        }
    }
    return -1;
}
