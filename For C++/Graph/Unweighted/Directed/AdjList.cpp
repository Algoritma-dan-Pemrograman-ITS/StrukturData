#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertex, edge;
    vector<vector<long>> adjList;
    
    void init(long v){
        vertex = v;

        for(int i=0; i<vertex; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2){
        if(find(adjList[vertex1].begin(), adjList[vertex1].end(), vertex2) != adjList[vertex1].end()) return; // check if vertex already inserted

        adjList[vertex1].push_back(vertex2);
    }

    void dfs(vector<long> &result, long start){
        vector<bool> visited(vertex, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!st.empty()){
            long temp = st.top();
            st.pop();

            if(!visited[temp]){
                result.push_back(temp);
                visited[temp] = true;
            }

            for(auto it:adjList[temp]){
                if (!visited[it])
                    st.push(it);
            }
        }
    }

    void bfs(vector<long> &result, long start){
        vector<bool> visited(vertex, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();

            for(auto it:adjList[temp]){
                if (!visited[it]){
                    q.push(it);
                    visited[it] = true;
                    result.push_back(it);
                }
            }
        }
    }
};

int main(){
    graph g;
    g.init(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    g.add_edge(1, 4);

    vector<long> dfs, bfs;
    g.dfs(dfs, 0);

    for(auto it:dfs){
        cout << it << " ";
    }
    cout << endl;

    g.bfs(bfs, 0);

    for(auto it:bfs){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}