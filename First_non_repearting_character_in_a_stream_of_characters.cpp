string Solution::solve(string A) 
{
    string res;
    vector<int> visited(26,0);
    queue<int> q; 
    
    for(int i=0;i<A.size();i++)
    {
       
        if(visited[A[i]-'a']==0)
        {
            visited[A[i]-'a']=1;
            q.push(A[i]);
        }else
        {
            visited[A[i]-'a']=2;
        }
        
        while(!q.empty()&&visited[q.front()-'a']==2)
            q.pop();
            
        if(!q.empty())
        {
           
            
            res.push_back(q.front());
        }else
        {
            res.push_back('#');
        }
    }
    
    return res;
}
