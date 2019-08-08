#include <vector>
#include <cstdio>
#define MAX 4001
using namespace std;

int n,m;
int g[MAX][MAX];
vector<int> adj[MAX];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    g[u][v] = 1;
}

void readInput(){
    scanf("%d %d%*c",&n,&m);
    int u,v,i;

    for(i=1;i<=m;i++) {
        scanf("%d %d%*c", &u, &v);
        addEdge(u,v);
    }
}

void solve(){
    int count = 0;
    int i,j,k;
    for (i=1;i<=n;i++){
        vector<int>::size_type sz = adj[i].size();
        for(j=0;j<sz;j++){
            for(k=j+1;k<sz;k++){
                if(g[adj[i][j]][adj[i][k]]==1) count++;
            }
        }
    }
    printf("%d\n",count);
}

int main(){
    readInput();
//    addEdge(1,2);
//    addEdge(1,3);
//    addEdge(1,5);
//    addEdge(2,3);
//    addEdge(2,4);
//    addEdge(3,4);
//    addEdge(3,5);
//    addEdge(4,5);
    solve();
    return 0;
}
