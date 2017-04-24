#include <cstdio> 

int v[4];
int n, p, r; 

int checa() {
    int contP=0, contR=0;
    int maior, i;

    maior = v[0];
    contP = 1;
    for(i=1; i<n; i++) {
        if(v[i]>maior) {
            contP++;
            maior = v[i];
        }
    }

    maior = v[n-1];
    contR = 1;
    for(i=n-2; i>=0; i--) {
        if(v[i]>maior) {
            contR++;
            maior=v[i];
        }
    }

    return contP==p && contR==r;
}

 

unsigned long q(int index) {
    if(index>=n) {
        return checa() ? 1 : 0;
    }

    unsigned long sum = 0;
    for(int i=1; i<=n; i++) {
        int hasI = 0;
        for(int j=0; j<=index; j++) {
            if(v[j]==i) {
                hasI=1;
                break;
            }
            if(!hasI) {
                v[index] = i;
                sum += q(index+1);
            }
        }
    }
    return sum;
}

/*
unsigned long bt( ??? ) {
    ????
}
*/

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &p, &r);
        printf("%ld\n", q(0));

        for (int i = 0; i < 4; i++) {
            printf("%d ", v[i]);
        }

        //printf("%ld\n", bt(n, p, r));
    }
}
