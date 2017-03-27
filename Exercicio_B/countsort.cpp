#include <algorithm>
#include <vector>
#include <stdio.h>

void countsort(std::vector<int> &);
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

void countsort(std::vector<int> & aV)
{
	//auto maxElement = std::max_element(aV.begin(), aV.end());
	//int maxValue = *maxElement;
	int maxValue = 999;

	// Initialize a C vector of 0..maxValue
	std::vector<int> C(maxValue + 1);	

	//printf("max value: %d\n", maxValue);	

	// Counting
	for (int i = 0; i < aV.size(); i++)
	{
		C[aV[i]]++;
		//printf("i: %d; aV[i]: %d\n", i, aV[i]);
	}

	//printVector(C);

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

void printVector(std::vector<int> & aV)
{
	// Print vector
    for (int i : aV)
    {                    
        printf("%d ", i);
    }        
    printf("\n");
}