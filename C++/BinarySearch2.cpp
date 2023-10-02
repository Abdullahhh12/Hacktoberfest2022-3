#include <iostream>
using namespace std;

void reverse(int arr[],int n)
{
    int start=0;
    int end = n-1;
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void printArr(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
 int arr[10]= {1,2,3,45,6,7,9,8,0,-5};
 int brr[5]={7,8,9,6,4};

 reverse(arr,10);
 reverse(brr,5);

 printArr(arr,10);
 printArr(brr,5);

 return 0;
 
}
