#include <algorithm>
#include <vector>
#include <iostream>
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
            scanf("%d",  &mVector[i]);
                
        radixsort(mVector); // Apply radix sort        
        printVector(mVector); // print vector
    }            
}

void radixsort(std::vector<int> & aV)
{
	auto maxElement = std::max_element(aV.begin(), aV.end());
	int maxValue = *maxElement;	

	for (int exp = 1; maxValue/exp > 0; exp *= 10) 
	{	    
		std::vector<std::vector<int> > buckets(10);
		
		for (int i : aV)
			buckets[(i / exp) % 10].push_back(i);		

		int j = 0;		
		for (auto it = buckets.begin(); it != buckets.end(); ++it)
		{			
			for (int i : *it)
			{		
				aV[j] = i;				
				j++;
			}
		}
	}
}

void printVector(std::vector<int> & aV)
{	
    for (int i : aV)    
        printf("%d ", i);
    printf("\n");
}