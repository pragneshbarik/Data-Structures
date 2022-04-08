#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;

void dfs(map<int,vector<int>> graph, int index, vector<int> &visited){
    if(!visited[index]){
        cout<<index<<" ";
        visited[index]=1;
        for(int i=0; i<graph[index].size(); i++){
            dfs(graph, graph[index][i] , visited);
        }
    } 
}

void bfs(map<int,vector<int>> graph){
    vector<int> visited (graph.size(), 0);
    queue<vector<int>> q;
    q.push(graph[0]);
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        for(auto child : node){
            if(!visited[child]){
                visited[child]=1;
                cout<<child;
                q.push(graph[child]);
            }
        }
    }   
}

void bfs(map<int, vector<vector<int>>> w_graph){
    vector<int> visited(w_graph.size(), 0);
    queue<vector<vector<int>>> q;
    q.push(w_graph[0]);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        for(auto child : node){
            if(!visited[child[0]]){
                visited[child[0]]=1;
                cout<<"v="<<child[0]<<" ; w="<<child[1]<<endl;
                q.push(w_graph[child[0]]);
            }
        }
    }
}

void prim(map<int, vector<vector<int>>> w_graph){
    set<vector<int>> pq;
    vector<int> visited(w_graph.size(), 0);
    pq.insert({w_graph[0][1][1],w_graph[0][1][0]});
    while(!pq.empty()){
        auto begin_it = pq.begin();
        auto first  = *begin_it;
        pq.erase(begin_it);
        for(auto child : w_graph[first[1]]){
            if(!visited[first[1]]){
                visited[first[1]]=1;
                cout<<first[1]<<endl;
                pq.insert({child[0], child[1]});
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    map<int, vector<int>> graph;

    vector<int> vis(8,0);
    graph[0]={1,2,3};
    graph[1]={0,2};
    graph[2]={1,3,4};
    graph[3]={0,2,4};
    graph[4]={2,3,5,6};
    graph[5]={4};
    graph[6]={4};
    //bfs(graph);

    map<int, vector<vector<int>>> w_graph;
    // Representation as graph[u] = vector of (v,w)
    //node={{node, weight},{node, weight}...{node, weight}}
    w_graph[0] = {{1,25}, {5, 5}};
    w_graph[1] = {{0,25}, {2,9}, {6, 6}};
    w_graph[2] = {{1,9}, {3, 10}};
    w_graph[3] = {{2,10}, {4,12}, {6, 11}};
    w_graph[4] = {{3,12}, {5, 18}, {6, 16}};
    w_graph[5] = {{0,5}, {4, 18}};
    w_graph[6] = {{1,6}, {3, 11}, {4,16}};

    //bfs(w_graph);
    prim(w_graph);
    


    return 0;
}
