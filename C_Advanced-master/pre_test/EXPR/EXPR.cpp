#include <iostream>
#include <fstream>

#define P 1000000007
#define MAX 32

int n, b;
int A[MAX];
int x[MAX];
int sum[MAX];
int t[] = {-1,1};
int count ;
int res;
using namespace std;

void input(char *filename){
    FILE* f = fopen(filename,"r");
    //FILE* f = stdin;
    fscanf(f,"%d %d",&n,&b);
    for (int i =0; i< n; i++){
        fscanf(f,"%d",&A[i]);
    }
    fclose(f);
}

void TRY(int k){
    //nhánh cận
    if (res + sum[k] < b) return;// Nếu res + tổng những thằng còn lại < b thì return;
    if (res - sum[k] > b) return;// Nếu res - tổng những thằng còn lại > b thì return;

    for (int v =0; v < 2; v++){
        res += t[v]*A[k];
        if (k == n-1){
            if (res == b) {
                    count++;
                    if (count == P) count = 0;
            }

        }
        else TRY(k+1);
        res -= t[v]*A[k];
    }
}

void solve(){
    res += A[0];
    sum[n-1] = A[n-1];
    for (int i =n-2; i>= 0; i--){
        sum[i] += sum[i+1]+ A[i];
    }
    TRY(1);
    printf("%d",count);
}

int main()
{
    input("input.inp");
    solve();
    return 0;
}
