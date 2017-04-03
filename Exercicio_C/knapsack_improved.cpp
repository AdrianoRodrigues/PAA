#include <vector>
#include <algorithm>
#include <cstdio>

struct KPItem
{
    long weight;
    long value;

    bool operator< (const KPItem & other) const
    {
        return value < other.value;
    }
};

long knapsack_improved(long W, const std::vector<KPItem> & V, int n)
{
    long M[n+1][W+1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0) 
                M[i][w] = 0;
            else if (V[i].weight <= w)
                M[i][w] = std::max(V[i].value + M[i-1][w-V[i].weight], M[i-1][w]);
            else
                M[i][w] = M[i-1][w];
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
        V.push_back(item);
    }
    std::sort(V.begin(), V.end());
    long best = knapsack_improved(W, V, V.size() - 1);
    printf("\nbest = %d\n\n", best);    
}