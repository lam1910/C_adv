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
char color[MAX];
int maxx = -MAX;
queue<int> Q;

int max(int a, int b){
    return a > b ? a : b;
}
void input(char* filename){
    //FILE* f = fopen(filename,"r");
    FILE* f = stdin;
    fscanf(f,"%d %d",&n,&m);
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
            if(color[v] == 'W'){
                color[v] = 'G';
                d[v] = d[u] + 1;
                p[v] = u;
                Q.push(v);
                maxx = max(maxx,d[v]);

            }
        }
        color[u] = 'B';
    }
}
void init(){
    for(int v = 1; v <= n; v++)
        color[v] = 'W';
}
void bfs(){
    init();
    for(int v = 1; v <= n; v++){
            init();
            bfsVisit(v);
        }
    printf("%d",maxx);
}
int main(){
    input("DIAM.inp");
    bfs();
    //bfs();
}
