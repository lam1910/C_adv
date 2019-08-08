#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1002

int n,m, C[MAX][MAX];
char color[MAX][MAX];
int cc_num;
int vertices;
int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};

void init();
void dfs(int,int);
void solve();
void input(char*);
bool check(int,int);

int main()
{
    input("room.inp");
    solve();
    return 0;
}

void init(){
    for (int i = 1; i<= n; i++)
        for (int j = 1; j<= m; j++)
            if (C[i][j] == 0)
                color[i][j] = 'B';
            else color[i][j] = 'W';
}

bool check(int i, int j ){
    if ( color[i][j] == 'W' ) return false;
    if ( (i < 1) || (i > n) || (j < 1) || (j > m) ) return false;
    return true;
}

void dfs(int si, int sj){
    color[si][sj] = 'W';
    for (int u=0; u< 4; u++){
        int i = si + di[u];
        int j = sj + dj[u];
        if (check(i,j)) dfs(i,j);
    }

}

void solve(){
    init();
    for (int i =1 ; i<= n; i++)
        for (int j =1; j<= m; j++)
            if (color[i][j] == 'B') {
                dfs(i,j);
                cc_num++;
            }

    printf("%d\n",cc_num);
}


void input( char* filename){
    FILE* f = fopen(filename,"r");
    //FILE* f = stdin;
    fscanf(f,"%d %d",&n,&m);
    for (int i=0; i< n;i++)
        for (int j=0; j<n; j++){
            fscanf(f,"%d",&C[i][j]);
        }

    fclose(f);
}
