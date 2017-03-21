#include <vector>
#include <iostream>

void printArray(const std::vector<int> &);
void insertionSort(std::vector<int> &);
void insertionSortImproved(std::vector<int> &);
std::vector<int> mergeSortedArray(std::vector<int> &, std::vector<int> &);
void mergeSort(std::vector<int> &);
void heapify(std::vector<int> &, int, int);
void buildHeap(std::vector<int> &);
void heapSort(std::vector<int> &);
int partition(std::vector<int> &, int, int);
void quickSort(std::vector<int> &, int, int);

int main()
{
    size_t vectorSize;    
    while (true)
    {        
        std::cin >> vectorSize;
        std::vector<int> vectorToSort(vectorSize);
        if (vectorSize == 0) break;
        for (int i = 0; i < vectorSize; i++)
        {
            std::cin >> vectorToSort[i];
        }
        //insertionSort(vectorToSort);
        //mergeSort(vectorToSort);
        heapSort(vectorToSort);
        //quickSort(vectorToSort, 0, vectorSize - 1);
        printArray(vectorToSort);
    }            
}

void insertionSort(std::vector<int> & aVector)
{
    int temp;
    for (int i = 0; i < aVector.size(); i++)
    {
        for (int j = i + 1; j < aVector.size(); j++)
        {
            if (aVector[i] > aVector[j])
            {
                temp = aVector[i];
                aVector[i] = aVector[j];
                aVector[j] = temp;
            }
        }
    }
}

void insertionSortImproved(std::vector<int> &aVector)
{
    bool changes;
    int temp;
    for (int i = 0; i < aVector.size(); i++)
    {
        changes = false;
        for (int j = i + 1; j < aVector.size(); j++)
        {
            if (aVector[i] > aVector[j])
            {
                temp = aVector[i];
                aVector[i] = aVector[j];
                aVector[j] = temp;
                changes = true;
            }
        }
        if (!changes) break;
    }
}

std::vector<int> mergeSortedArray(std::vector<int> &aVector1, std::vector<int> &aVector2)
{
    std::vector<int> mergedVector(aVector1.size() + aVector2.size());
    int i = 0;
    int j = 0;
    for (int k = 0; k < mergedVector.size(); k++)
    {
        if (j >= aVector2.size())
        {
            mergedVector[k] = aVector1[i];
            i++;
        } 
        else if (i >= aVector1.size())
        {
            mergedVector[k] = aVector2[j];
            j++;
        }
        else if (aVector1[i] <= aVector2[j])
        {
            mergedVector[k] = aVector1[i];
            i++;
        }
        else
        {
            mergedVector[k] = aVector2[j];
            j++;
        }                
    }
    return mergedVector;
}

void mergeSort(std::vector<int> & aVector)
{    
    if (aVector.size() > 1)
    {
        int middle = aVector.size() / 2;
        std::vector<int> left(aVector.begin(), aVector.begin() + middle);
        std::vector<int> right(aVector.begin() + middle, aVector.end());        
        mergeSort(left);
        mergeSort(right); 
        aVector = mergeSortedArray(left, right);
    }    
}

void heapify(std::vector<int> & aVector, int aPos, int aHeapSize)
{
    int temp;
    if (aVector.size() > 1)
    {
        int left = (2 * aPos) + 1;
        int right = left + 1;
        int largest = aPos;
        if (left < aHeapSize && aVector[left] > aVector[largest])
            largest = left;
        if (right < aHeapSize && aVector[right] > aVector[largest])
            largest = right;
        if (largest != aPos)
        {
            temp = aVector[aPos];
            aVector[aPos] = aVector[largest];
            aVector[largest] = temp;
            heapify(aVector, largest, aHeapSize);
        }
    }
}

void buildHeap(std::vector<int> & aVector)
{
    size_t vectorSize = aVector.size();
    for (int i = vectorSize / 2; i >= 0; i--)
        heapify(aVector, i, vectorSize);
}

void heapSort(std::vector<int> & aVector)
{
    buildHeap(aVector);
    for (int i = aVector.size() - 1; i >= 0; i--)
    {
        if (aVector[0] > aVector[i])
        {
            int temp = aVector[0];
            aVector[0] = aVector[i];
            aVector[i] = temp;
            heapify(aVector, 0, i - 1);
        }
    }
}

int partition(std::vector<int> & aVector, int aLeft, int aRight)
{    
    int pivot = aVector[(aLeft + aRight) / 2];
    //std::cout << "pivot = " << pivot << std::endl;
    int i = aLeft;
    int j = aRight;
    while (true)
    {
        while (aVector[j] > pivot) j--;        
        while (aVector[i] < pivot) i++;         
        if (i <= j)
        {
            int temp = aVector[i];
            aVector[i] = aVector[j];
            aVector[j] = temp;
            i++;
            j--;
        } 
        else return j;
    }
}

void quickSort(std::vector<int> & aVector, int aLeft, int aRight)
{    
    if (aLeft < aRight)
    {
        int middle = partition(aVector, aLeft, aRight);  
        if (aLeft < middle)        
            quickSort(aVector, aLeft, middle);
        if (middle < aRight)
            quickSort(aVector, middle + 1, aRight);
    }
}

void printArray(const std::vector<int> & aVector)
{
    for (int item : aVector)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;        
}