#include <iostream>
#include <fstream>

#define p 1000000007
#define MODU 1000000007
#define MAX 1000006
int n;
long long A[MAX],B[MAX];
long long  sum;
using namespace std;

void swap(long long *a, long long *b){
  long long tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

long long addmod(long long a, long long b, long long P){
    a = a % P;
    b = b % P;
    long long tmp = P - b;
    if (a>= tmp) return a - tmp;
    else return a + b ;
}

long long mulmod(long long a, long long b, long long P){
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b%P;
    if (b == 1) return a%P;
    if (a > b) swap(&a, &b);
    long long c = mulmod(a/2, b, P);
    c = addmod(c, c, P);
    if (a%2 == 0) return c;
    else return addmod(c, b, P);
}

void input(char *filename){
    FILE* f = fopen(filename,"r");
    //FILE* f = stdin;
    fscanf(f,"%d",&n);
    for (int i =0; i< n; i++){
        fscanf(f,"%d",&A[i]);
    }
    for (int i =1; i< n; i++){
        fscanf(f,"%d",&B[i]);
    }
    B[0] = 1;
    fclose(f);
}

void solve(){
    int i = n-1;
    int temp;
    while (i >= 0){
        temp = A[i];
        if (B[i] == 2){
            while ( (i >= 0 ) && (B[i] == 2) ){
                i--;
                temp = mulmod(temp,A[i],p);

            }
        }
        if (B[i] == 1) {
            sum = addmod(sum, temp,p);
        }
        else {
                sum -= temp;
                if (sum < 0) sum +=p; // Dòng này quan trọng vl
        }

        i--;
    }

    printf("%d",sum);
}

int main()
{
    input("EXPREVAL.inp");
    solve();
    return 0;
}


