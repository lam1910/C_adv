#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1002

int t_i[] = {-2, -2, -1, -1,  1, 1,  2, 2};
int t_j[] = {-1,  1, -2,  2, -2, 2, -1, 1};
int x_i[MAX*MAX], x_j[MAX*MAX];
int n,start_i,start_j;
bool visited[MAX][MAX];
int count;

void init();
void solve();
void input(char*);
bool check(int, int);
void printSol();
void TRY(int);

int main()
{
    input("knight.inp");
    solve();
    return 0;
}

void init(){
    for (int i = 0; i<=  n; i++)
        for (int j = 0; j <= n; j++)
            visited[i][j] = false;
}
void input( char* filename){
    //FILE* f = fopen(filename,"r");
    FILE* f = stdin;
    fscanf(f,"%d %d %d",&n, &start_i, &start_j);

    fclose(f);
}

bool check(int i, int j){
    if ( (i <1) || (i >n) || (j <1) || (j >n) ) return false;
    if (visited[i][j] ) return false;
    return true;
}

void printSol(){
    count++;
    for (int k = 1; k <= n*n; k++){
        printf("(%d , %d) ",x_i[k],x_j[k]);
    }
    printf("\n");
}

void TRY(int k){

    for (int v =0; v< 8; v++){
        int newI = x_i[k-1] + t_i[v];
        int newJ = x_j[k-1] + t_j[v];

        if (check(newI,newJ)){
            visited[newI][newJ] = true;
            x_i[k] = newI;
            x_j[k] = newJ;
            if ( k == n*n) printSol();
            else TRY(k+1);
            visited[newI][newJ] = false;
        }
    }
}

void solve(){
    init();
    visited[start_i][start_j] = true;
    x_i[1] = start_i;
    x_j[1] = start_j;
    TRY(2);
    printf("total : %d way(s)\n", count);

}
