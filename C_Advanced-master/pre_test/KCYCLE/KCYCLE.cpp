#include <iostream>
#include <fstream>
#include <set>
#include <queue>

#define MAX 30

using namespace std;

int z[MAX],x[MAX],visit[MAX];
char color[MAX];
int n,m,k;
int A[MAX][MAX];
int C[MAX][MAX];
int W[MAX][MAX];
int sum,minn=100000;

void input( char* filename){
    //FILE* f = stdin;
    FILE* f = fopen(filename,"r");
    fscanf(f,"%d %d %d",&n,&m,&k);
    for (int i =1; i<= m; i++){
        int u,v,w;
        fscanf(f,"%d%d%d",&u,&v,&w);
        z[v] ++;
        z[u] ++;
        C[u][v] = 1;
        C[v][u] = 1;
        A[u][z[u]] = v;
        A[v][z[v]] = u;
        W[u][v] = w;
        W[v][u] = w;
    }

    fclose(f);
}

int min(int a,int b){
    return a<b ? a : b;
}

void init(){
    for (int i =1; i<= n; i++){
        color[i] = 'B';
    }

}

void DFS( int na,int vert, int start,int weight)
{
    color[vert] = 'W';
    if (na == 1) {

        color[vert] = 'B';
        if (C[vert][start])
        {
            weight += W[vert][start];
            minn = min(minn,weight);
            return;
        } else
            return;
    }

    for (int i = 1; i <= n; i++)
        if (color[i] == 'B' && C[vert][i] && weight+ W[vert][i] < minn)
            DFS(na-1, i, start, weight+ W[vert][i]);

    color[vert] = 'B';
}

void solve(){
    init();
    for(int i = 1; i<= n-k+1; i++){
        //int start = i;
        DFS(k,i,i,0);
    }
    printf("%d",minn);
}

int main()
{
    input("KCYCLE.inp");
    solve();
    return 0;
}
