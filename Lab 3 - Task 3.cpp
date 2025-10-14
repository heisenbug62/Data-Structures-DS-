#include <iostream>
#include <string>
using namespace std;

// Input: A Sorted array, A of N elements and value to be searched
// Output: Index of searched element or -1 if not found

// low = 0, high = N-1;
// While (low <= high)
//   mid = (low + high)/2;
//   If ( A[mid] == Value )
//      Return mid;
//   Else-if ( A[mid] < Value )
//      low = mid + 1;
//   Else
//      high = mid – 1;
//   End-if
// End-While
// return -1;
template <class T>
void printSearchResult(int ind, T key)
{
    cout << "Your key: " << key << " found at index: " << ind << endl; 
}

template <class T>
int binarySearch(T arr[], T key)
{
    int low = 0;
    int high = 5 - 1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;  
        
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;  // key not found
}

int main() 
{
    // Test with an integer array (sorted) of size 5
    int intArray[5] = {11, 12, 22, 25, 64};
    int intKey = 22;
    int intIndex = binarySearch(intArray, intKey);
    printSearchResult(intIndex, intKey);

    // Test with a float array (sorted) of size 4
    float floatArray[5] = {0.57, 1.62, 2.71, 3.14, 4.22};
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, floatKey);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array (sorted) of size 4
    string stringArray[5] = {"apple", "banana", "grape", "orange", "Pomi"};
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}
