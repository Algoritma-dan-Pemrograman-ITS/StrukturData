#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertex, edge;
    vector<vector<pair<long, long>>> adjList;
    vector<pair<long, pair<long, long>>> edgeList;
    
    void init(long v){
        vertex = v;
        edge = 0;

        for(int i=0; i<vertex; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        if(find(adjList[vertex1].begin(), adjList[vertex1].end(), make_pair(vertex2, weight)) != adjList[vertex1].end()) return; // check if vertex already inserted

        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));

        edgeList.push_back(make_pair(weight, make_pair(vertex1, vertex2)));
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

            for(auto it:adjList[temp.second]){
                long nextVertex = it.first;
                long weight = it.second;

                if(temp.first + weight < result[nextVertex] || result[nextVertex] == -1) {
                    result[nextVertex] = temp.first + weight;
                    pq.push({result[nextVertex], nextVertex});
                }
            }
        }
    }

    long find_parent(vector<long> &parent, long v){
        if(v == parent[v]) return v;

        return find_parent(parent, parent[v]);
    }

    void union_set(vector<long> &parent, long vertex1, long vertex2){
        parent[vertex2] = parent[vertex1];
    }

    void kruskal(vector<pair<long, pair<long, long>>> &result){
        vector<long> parent;
        for(int i=0; i<vertex; i++) parent.push_back(i);

        sort(edgeList.begin(), edgeList.end());
        
        for(auto it:edgeList){
            long vertex1 = it.second.first;
            long vertex2 = it.second.second;
            if(find_parent(parent, vertex1) != find_parent(parent, vertex2)){
                result.push_back(it);
                union_set(parent, vertex1, vertex2);
                if(result.size() == vertex-1) return;
            }
        }
    }
};

int main(){
    graph g;
    g.init(5);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 4);
    g.add_edge(0, 3, 6);
    g.add_edge(0, 4, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 8);
    g.add_edge(3, 4, 9);

    vector<pair<long, pair<long, long>>> kruskal;

    g.kruskal(kruskal);

    for(auto it:kruskal){
        cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    }

    return 0;
}