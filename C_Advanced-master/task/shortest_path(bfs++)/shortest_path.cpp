#include <set>
#include <iostream>
#include <fstream>
#include <queue>
#define MAX 2000
using namespace std;

int n, m;
set<int> A[MAX]; // A[v] la tap dinh ke vs dinh v

int t;
int d[MAX];
int f[MAX];
int p[MAX];
int start,end;
char color[MAX];
int maxx = -MAX;
queue<int> Q;

int max(int a, int b){
    return a > b ? a : b;
}
void input(char* filename){
    FILE* f = fopen(filename,"r");
    //FILE* f = stdin;
    fscanf(f,"%d %d %d %d",&n,&m,&start,&end);
    for( int i =1; i <= m; i++){
        int u,v;
        fscanf(f,"%d %d",&u,&v);
        A[u].insert(v);
        A[v].insert(u);
    }
}

void bfsVisit(int s){
    color[s] = 'G';
    d[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        int u;
        u = Q.front();
        Q.pop();
        for(set<int>::iterator i = A[u].begin(); i != A[u].end(); i++){
            int v = *i;
            if(color[v] == 'B'){
                color[v] = 'G';
                d[v] = d[u] + 1;
                p[v] = u;
                Q.push(v);
                if (v == end) return;
            }
        }
        color[u] = 'W';
    }
}
void findPath(int u, int v){
    if (u == v)
        printf("%d ",v);
    else if (p[v] == -1)
        printf("Can't find path");
    else {
        findPath(u,p[v]);
        printf("%d ",v);
    }

}
void init(){
    for(int v = 1; v <= n; v++)
        color[v] = 'B';
}
void bfs(){
    init();
    bfsVisit(start);
    printf("%d\n",d[end]);
    printf("Trace : ");
    findPath(start,end);
}
int main(){
    input("shortest_path.inp");
    bfs();
}
