#include <algorithm>
#include <vector>
#include <stdio.h>

void countsort(std::vector<int> &, int);
void radixsort(std::vector<int> &);
void printVector(std::vector<int> &);

int main()
{
    int mVecSize;    
    while (true)
    {                
    	// Load arrays from stdin
        scanf("%d", &mVecSize);
        if (mVecSize == 0) break;
        
        std::vector<int> mVector(mVecSize);        
        for (int i = 0; i < mVecSize; i++)
        {            
            scanf("%d",  &mVector[i]);
        }
        
        // Apply count sort
        countsort(mVector);

        // print
        printVector(mVector);
    }            
}

void countsort(std::vector<int> & aV, int aExp)
{
	int maxValue = 9;	
	
	// Initialize a C vector of 0..maxValue
	std::vector<int> C(maxValue + 1);		

	// Counting
	for (int i = 0; i < aV.size(); i++)
	{
		C[aV[i]]++;		
	}	

	// Sort
	int j = 0;
	for (int i = 0; i <= maxValue; i++)
	{
		while (C[i] > 0)
		{
			aV[j] = i;
			j++;
			C[i]--;
		}
	}	
}

void radixsort(std::vector<int> & aV)
{
	auto maxElement = std::max_element(aV.begin(), aV.end());
	int maxValue = *maxElement;

	for (int exp = 1; maxValue/exp > 0; exp *= 10) 
	{	    
		countSort(aV, exp);
	}
}

void printVector(std::vector<int> & aV)
{
	// Print vector
    for (int i : aV)
    {                    
        printf("%d ", i);
    }        
    printf("\n");
}