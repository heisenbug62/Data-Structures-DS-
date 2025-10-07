#include <iostream>
using namespace std;

template <typename T>
void printSearchResult(int idx, T key)
{
    if (idx == -1)
        cout << "Key '" << key << "' not found." << endl;
    else
        cout << "Desired key '" << key << "' found at index: " << idx << endl;
}

template <typename T>
int binarySearch(T array[], T key, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == key)
        {
            return mid; 
        }
        else if (array[mid] < key)
        {
            low = mid + 1; 
        }
        else
        {
            high = mid - 1; 
        }
    }

    return -1; 
}

int main()
{
    // Test with an integer array (sorted)
    int intArray[5] = { 11, 12, 22, 25, 64 };
    int intKey = 22;
    int intIndex = binarySearch(intArray, intKey, 5);
    printSearchResult(intIndex, intKey);

    // Test with a float array (sorted)
    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, floatKey, 4);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array (sorted)
    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, stringKey, 4);
    printSearchResult(stringIndex, stringKey);

    return 0;
}
