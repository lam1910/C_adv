#include <stdio.h>
#include <stdbool.h>

#define MAX 10002
#define inf 1000000


int z[MAX];
int A[MAX][MAX];
int n,m,s,t;
int W[MAX][MAX];
int d[MAX]; //d[v] la can tren duong di ngan nhat tu s den v
int p[MAX]; // p[v]: dinh ma tu do di den v
bool fix[MAX]; // fix[v] = true : dinh v da tim duoc duong di ngan nhat

void input(char * filename){
    FILE* f = fopen(filename,"r");
    //FILE* f = stdin;
    fscanf(f,"%d %d",&n,&m);
    for (int v=1; v<=n; v++) z[v] = 0;
    for (int k =1; k<= m; k++){
        int u,v,w;
        fscanf(f,"%d%d%d",&u,&v,&w);
                //undirected graph
//        z[u]++;
//        z[v]++;
//        A[u][ z[u]-1 ] = v;
//        A[v][ z[v]-1 ] = u;
//        W[u][ z[u]-1 ] = w;
//        W[v][ z[v]-1 ] = w;

        //directed graph
        z[u]++;
        A[u][ z[u]-1 ] = v;
        W[u][ z[u]-1 ] = w;

    }
    fscanf(f,"%d%d",&s,&t);
    fclose(f);
}


int findMin(){
    int minD = inf;
    int sel_v = -1;
    for (int v = 1; v<= n; v++)
        if (!fix[v]){
            if (minD > d[v]){
                minD = d[v];
                sel_v = v;
            }
        }
    return sel_v;

}

void dijkstra(){
    for (int v=1; v<= n; v++){
        d[v] = inf;
        fix[v] = false;
    }

    for (int i=0; i< z[s]; i++){
        int v = A[s][i];
        d[v] = W[s][i];
        p[v] = s;
    }
    while (1){
        int v = findMin();
        if (v == -1) break;
        fix[v] = true;
        for (int i=0; i < z[v]; i++){
            int x = A[v][i];
            if (!fix[x] && d[x] > d[v] + W[v][i]){
                d[x] = d[v] + W[v][i];
                //p[x] = v;
            }
        }
    }
    printf("%d",d[t]);


}


int main()
{
    input("graph_dijkstra.inp");
    //s=1;
    dijkstra();

    return 0;
}
