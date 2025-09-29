class Solution {
public:

    bool check(unordered_map<int , vector<int>>&mp, vector<bool> &visited , int source , int destination)
    {
        if(source==destination) return true;

        if(visited[source]==true) return false;

        visited[source] = true;

        for(int &node : mp[source])
        {
            if(!visited[node])
            if(check(mp ,  visited , node , destination))
            return true ;
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<bool>visited(n , 0);
       unordered_map<int , vector<int>>mp;
        for(vector<int>  &edge : edges)
        {
              int u = edge[0];
              int v = edge [1];
              mp[u].push_back(v);
              mp[v].push_back(u);

        }

               return check(mp , visited , source , destination);

        

    }
};