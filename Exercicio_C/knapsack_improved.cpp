#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

struct KPItem
{
    long weight;
    long value;

    bool operator< (const KPItem & other) const
    {
        return (value / weight) < (other.value / other.weight);
    }
};
 
bool greater(const KPItem & item1, const KPItem & item2)
{
    return (item1.value / item1.weight) > (item2.value / item2.weight);
}

long max(long a, long b)
{
    return (a >= b) ? a : b;
}

long knapsack_improved(long W, const std::vector<KPItem> & V, int n)
{
    long M[n+1][W+1];
    //std::vector<std::vector<long> > M(n+1, std::vector<long>(W+1));

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            //std::cout << "[ " << i << " : " << w << " ]" << std::endl;
            //if (i == 0 || w == 0) 
            //    M[i][w] = 0;
            //else 
            if (i > 0)
            {
                if (V[i-1].weight <= w)
                    M[i][w] = max(V[i-1].value + M[i-1][w-V[i-1].weight], M[i-1][w]);
                else
                    M[i][w] = M[i-1][w];
            }
        }
    }

    return M[n][W];
}

int main() 
{
    long W; // capacidade da mochila.
    int L; // quantidade de itens.        

    scanf("%ld", &W);
    scanf("%d", &L);

    long aux[2*L]; // vetor auxiliar.
    for (int i = 0; i < 2 * L; i++)
    {
        scanf("%ld", &aux[i]);
    }

    std::vector<KPItem> V(L); // itens da mochila.
    for (int i = 0; i < L; i++)
    {
        KPItem item = { aux[i], aux[i+L] };
        V[i] = item;
    }
    std::sort(V.begin(), V.end(), greater);
    //printf("first element = %d\n\n", V[L-1].value);
    long best = knapsack_improved(W, V, L-1);
    printf("\nbest = %ld\n\n", best);    
}