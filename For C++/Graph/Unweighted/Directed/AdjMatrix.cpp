#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<long>> adjMatrix;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;
        vector<long> zero(vertexCount, 0);

        for(int i=0; i<vertexCount; i++){
            adjMatrix.push_back(zero); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2){
        adjMatrix[vertex1][vertex2] = 1;
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

            for(long i=0; i<vertexCount; i++){
                if (adjMatrix[temp][i] && !visited[i])
                    st.push(i);
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

            for(long i=0; i<vertexCount; i++){
                if (adjMatrix[temp][i] && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                    result.push_back(i);
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

    vector<long> dfs_result, bfs_result;
    g.dfs(dfs_result, 0);

    for(auto it:dfs_result){
        cout << it << " ";
    }
    cout << endl;

    g.bfs(bfs_result, 0);

    for(auto it:bfs_result){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}