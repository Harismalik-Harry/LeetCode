class Solution {
public:
void helper(vector<vector<int>> &res,vector<int>& can, int t,vector<int> &help,int s)
{
    
    int sum=0;
    for(auto elem:help)
    {
        sum+=elem;
    }
    if(sum==t)
    {
        res.push_back(help);
        return;
    }
    if(sum>t)
    {
        
        return;
    }
    for(int i=s;i<can.size();i++)
{help.push_back(can[i]);
    helper(res,can,t,help,i);
    help.pop_back();

}
}
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<vector<int>> res;
        vector<int> help;
        helper(res,can,t,help,0);
        return res;
    }
};