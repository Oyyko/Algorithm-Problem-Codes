#include "base.hpp"

class Solution
{
public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();
        
        for(auto&v:edges){

        }
        vector<int> bob_time(n, 0);
        auto dfs_bob=[&](int x,int fa,int t)->void{
            if(x==0){
                bob_time[x]=t;
            }
            for 
        }
    }
};

int main()
{
}