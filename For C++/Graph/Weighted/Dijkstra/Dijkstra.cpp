#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertex, edge;
    vector<vector<pair<long, long>>> adjList;
    
    void init(long v){
        vertex = v;

        for(int i=0; i<vertex; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        if(find(adjList[vertex1].begin(), adjList[vertex1].end(), make_pair(vertex2, weight)) != adjList[vertex1].end()) return; // check if vertex already inserted

        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
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
                if (!visited[it.first])
                    st.push(it.first);
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
                if (!visited[it.first]){
                    q.push(it.first);
                    visited[it.first] = true;
                    result.push_back(it.first);
                }
            }
        }
    }

    void dijkstra(vector<long> &result, long start){
        vector<bool> visited(vertex, false);
        priority_queue <pair<long, long>, 
                        vector <pair<long, long>>, 
                        greater <pair<long, long>> > pq;
        result = vector<long>(vertex, -1);
        result[start] = 0;
        pq.push(make_pair(0, start));

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            if(visited[temp.second]) continue;

            visited[temp.second] = true;

            for(auto &it:adjList[temp.second]){
                long nextVertex = it.first;
                long weight = it.second;

                if(temp.first + weight < result[nextVertex] || result[nextVertex] == -1) {
                    result[nextVertex] = temp.first + weight;
                    pq.push({result[nextVertex], nextVertex});
                }
            }
        }
    }
};

int main(){
    graph g;
    g.init(6);
    g.add_edge(0, 1, 2);
    g.add_edge(0, 5, 4);
    g.add_edge(1, 3, 9);
    g.add_edge(5, 3, 2);
    g.add_edge(3, 4, 1);
    g.add_edge(3, 2, 5);

    vector<long> dijkstra;

    g.dijkstra(dijkstra, 0);

    for(int i=0; i<dijkstra.size(); i++){
        cout << i << " " << dijkstra[i] << endl;
    }

    return 0;
}