#include <iostream>
#include <fstream>

#define MAX 1000

using namespace std;

int n;
int A[MAX],B[MAX];
int count;


void input(char *filename){
    FILE* f = fopen(filename,"r");
    //FILE* f = stdin;
    fscanf(f,"%d",&n);
    for (int i =0; i< n; i++){
        fscanf(f,"%d %d",&A[i],&B[i]);
    }
    fclose(f);
}

bool isBetter(int i, int j){
    if ( (A[i] > A[j]) && (B[i] > B[j]) ) return true;
    return false;
}
void solve(){

    for (int i =0; i < n; i++){
        bool check = true;
        for (int j= 0; j< n; j++){
            if (isBetter(i,j)) {
                check = false;
                break;
            }
        }
        if (check) count++;
    }
    printf("%d",count);
}

int main()
{
    input("SVG.inp");
    solve();
    return 0;
}

