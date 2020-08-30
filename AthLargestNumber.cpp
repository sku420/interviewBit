vector<int> Solution::solve(int B, vector<int> &A) {
    //cout<<A.size();
    if(B>A.size()){
        return {};
    }
    priority_queue<int, vector<int>, greater<int> >q;
    vector<int>ans(A.size());
    for(int i=0;i<B;i++){
        q.push(A[i]);
        ans[i]= -1;
    }
    ans[B-1]=q.top();
    for(int i=B;i<A.size();i++){
        if(q.size() == B){
            if(q.top()<=A[i]){
                q.pop();
                q.push(A[i]);
            }
            ans[i]=q.top();
        }
    }
    ans[A.size()-1]=q.top();
    //cout<<ans.size();
    return ans;
}
