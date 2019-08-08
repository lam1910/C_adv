#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int m,n;
int z[MAX],A[MAX][MAX];
char color[MAX];
int cc_num;
void readData(char * filename){
    int u,v;
    FILE* f = fopen(filename,"r");
    fscanf(f,"%d %d",&n,&m);
    for (int i =1; i<=m ; i++){
        fscanf(f,"%d %d",&u,&v);
        A[u][z[u]++] = v;
        A[v][z[v]++] = u;

    }
    fclose(f);
}
void init(){
    for (int i =1; i<=n; i++){
        color[i] = 'B';
    }
}

void dfs(int s){
    color[s] = 'W';
    for(int i=0; i< z[s]; i++){
        int v = A[s][i];
        if (color[v] == 'B'){
            dfs(v);
        }
    }
}

void solve(){
    init();
    for (int i =1 ; i<= n; i++)
        if (color[i] == 'B') {
            dfs(i);
            cc_num++;
        }

    printf("%d\n",cc_num);
}

int main()
{
    readData("input.inp");
    solve();
    return 0;
}
