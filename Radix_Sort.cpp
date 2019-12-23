#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getIndex(int value, int div)
{
    return (value / div) % 10;
}

void radix_sort(int arr[], int n)
{
    int max = arr[0], div = 1;
    vector<queue<int>> radix(10);
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max) max = arr[i];
    }
    while(max > 0)
    {
        for(int i = 0; i < n; i++)
        {
            radix[getIndex(arr[i], div)].push(arr[i]);
        }
        for(int i = 0, j = 0; i < radix.size(); i++)
        {
            while(!radix[i].empty())
            {
                arr[j] = radix[i].front();
                radix[i].pop();
                j++;
            }
        }
        div *= 10;
        max /= 10;
    }
}

int main()
{
    int arr[] = { 237, 259, 348, 152, 235, 48, 36, 62 };
    cout << "Array before sorting..." << endl;
    for(int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;
	cout << "Applying radix sort algorithm..." << endl;
    radix_sort(arr, 8);
    cout << "Array after sorting..." << endl;
    for(int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}