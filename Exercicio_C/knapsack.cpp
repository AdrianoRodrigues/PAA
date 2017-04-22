#include <vector>
#include <algorithm>
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

long knapsack(long W, const std::vector<KPItem> & V, int i)
{
    if (i >= V.size())
        return 0;
    long best = knapsack(W, V, i+1);
    if (V[i].weight <= W)
    {
        long aux = knapsack(W-V[i].weight, V, i+1) + V[i].value;
        if (aux > best)
            best = aux;
    }
    return best;
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
    long best = knapsack(W, V, 0);
    printf("\nbest = %ld\n\n", best);    
}