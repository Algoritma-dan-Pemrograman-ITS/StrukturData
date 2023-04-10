#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<set<long>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].insert(vertex2);
        adjList[vertex2].insert(vertex1);
        edgeCount++;
    }

    void dfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
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

            for(auto vertex:adjList[temp]){
                if (!visited[vertex])
                    st.push(vertex);
            }
        }
    }

    void bfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();

            for(auto vertex:adjList[temp]){
                if (!visited[vertex]){
                    q.push(vertex);
                    visited[vertex] = true;
                    result.push_back(vertex);
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