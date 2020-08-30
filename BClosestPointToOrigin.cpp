vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    priority_queue<pair<double,vector<int> >, vector<pair<double,vector<int> > >, greater<pair<double,vector<int> > > >disQ;
    vector<vector<int> >closestPoints;
    
    for(int i=0;i<A.size();i++){
        double eucDis = sqrt(pow((A[i][0]),2)+pow((A[i][1]),2)); //calc distance
        //cout<<eucDis<<endl;
        disQ.push({eucDis,A[i]});
    }
    while(B--){
        closestPoints.push_back(disQ.top().second);
        disQ.pop();
    }
    return closestPoints;
}
