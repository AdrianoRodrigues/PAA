#include <vector>
#include <stdio.h>

typedef struct
{
    int weight;
    int value;
} KPItem;

int knapsack(int W, std::vector<KPItem> V, int i)
{
    if (i >= V.size())
        return 0;
    int best = knapsack(W, V, i+1);
    if (V[i].weight <= W)
    {
        int aux = knapsack(W-V[i].weight, V, i+1) + V[i].value;
        if (aux > best)
            best = aux;
    }
    return best;
}

int main() 
{
    int W; // capacidade da mochila.
    int L; // quantidade de itens.        

    scanf("%d", &W);
    scanf("%d", &L);

    int aux[2*L]; // vetor auxiliar.
    for (int i = 0; i < 2 * L; i++)
    {
        scanf("%d", &aux[i]);
    }

    std::vector<KPItem> V(L); // itens da mochila.
    for (int i = 0; i < L; i++)
    {
        KPItem item = { aux[i], aux[i+L] };
        V.push_back(item);
    }
    int best = knapsack(W, V, 0);
    printf("the best value is %d", best);    
}