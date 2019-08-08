#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>

using namespace std;
#define MAX 1002

int n,m, C[MAX][MAX];
char color[MAX][MAX];
int cc_num;
int vertices;
int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};
int start_i, start_j;
int back_i[MAX];
int back_j[MAX];


int min(int ,int );
void init();
void BFS();
void solve();
void input(char*);
bool check(int,int);

int main()
{
    input("matrix.inp");
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
    return true;
}

void solve(){
    init();
    BFS();
}

void BFS(){
    queue<int> q;
    q.push(start_i);
    q.push(start_j);
    q.push(0);
    int res = 0;
    while (!q.empty()){
        int i = q.front(); q.pop();
        int j = q.front(); q.pop();
        int d = q.front(); q.pop();
        for (int u = 0; u< 4; u++){
            int next_i = i + di[u];
            int next_j = j + dj[u];
            if ( (next_i < 1) || (next_i > n) || (next_j < 1) || (next_j > m) ){
                printf("%d",d+1);
                return;
            }
            if ( check(next_i, next_j) ){
                q.push(next_i);
                q.push(next_j);
                q.push(d+1);
                //back[next_i] = i;
                //back[next_j] = j;
                color[next_i][next_j] = 'W';
            }

        }
    }

    printf("%d\n",res);
}

void input( char* filename){
    FILE* f = fopen(filename,"r");
    //FILE* f = stdin;
    fscanf(f,"%d %d %d %d",&n,&m, &start_i, &start_j);
    for (int i=1; i<= n;i++)
        for (int j=1; j<= m; j++){
            fscanf(f,"%d",&C[i][j]);
        }
    for (int i=1; i<= n;i++){
        for (int j=1; j<= m; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }


    fclose(f);
}

int min(int a,int b){
    return a > b ? a : b;
}
