#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}

//time complexity of bubble sort is O(n^2)
//space complexity of O(1)

void bubble_sort(int arr[],int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(cmp(arr[j],arr[j+1])!=true) //arr[j]>arr[j+1] instead of writing this we can create a comparision function
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    cout<<"Sorted array using bubble sort:";

    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

//time complexity O(n^2)
//space complexity O(1)

void insertion_sort(int arr[],int n)
{
    for(int i=1 ; i<n ; i++)
    {
        int curr=arr[i];
        int j;
        for(j=i-1 ; j>=0 ; j--)
        {
            if(arr[j]>curr)
            {
                arr[j+1]=curr;
            }
            else{
                break;
            }
        }
        arr[j+1]=curr;

    }

    cout<<"\nSorting using insertion sort:";

    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

//time complexity O(n^2)
//sapce complxity O(1)
 
void selection_sort(int arr[],int n)
{
    for(int i=0 ; i<n ; i++)
    {
       int min_idx=i;
       for(int j=i+1 ; j<n ; j++)
       {
           if(cmp(arr[j],arr[min_idx])==true)
           {
               min_idx=j;
           }
       }

       swap(arr[i],arr[min_idx]);
    }

    cout<<"\nSorting using selection sort:";
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void counting_sort(int arr[],int n)
{
    map<int,int> m;

    for(int i=0 ; i<n ; i++)
    {
        m[arr[i]]++;
    }

    cout<<"\nSorting using counting sort:";
    for(auto x : m)
    {
        int k=x.second;

        while(k--)
        {
            cout<<x.first<<" ";
        }
    }

}

int partition(int arr[],int a,int b)
{
    int pivot=arr[b];
    int i=a-1;

    for(int j=a ; j<=b ; j++)
    {
        if(cmp(arr[j],pivot))
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[b]);

    return i+1;
}

void quick_sort(int arr[],int a,int b)
{
    if(a>=b)
    {
        return;
    }

    int p=partition(arr,a,b);

    quick_sort(arr,a,p-1);
    quick_sort(arr,p+1,b);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    
    bubble_sort(arr,n);
    insertion_sort(arr,n);
    selection_sort(arr,n);
    counting_sort(arr,n);
    

    quick_sort(arr,0,n-1);
    
    cout<<"Sorting using quick sort:";
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}
