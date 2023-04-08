#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertex, edge;
    vector<vector<long>> adjMatrix;
    
    void init(long v){
        vertex = v;
        edge = 0;
        vector<long> zero(vertex, 0);

        for(int i=0; i<vertex; i++){
            adjMatrix.push_back(zero); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        adjMatrix[vertex1][vertex2] = weight;
        adjMatrix[vertex2][vertex1] = weight;
        edge++;
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

            for(long i=0; i<vertex; i++){
                if (adjMatrix[temp][i] != 0 && !visited[i])
                    st.push(i);
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

            for(long i=0; i<vertex; i++){
                if (adjMatrix[temp][i] != 0 && !visited[i]){
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
    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 20);
    g.add_edge(0, 3, 30);
    g.add_edge(1, 3, 40);
    g.add_edge(1, 4, 50);

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