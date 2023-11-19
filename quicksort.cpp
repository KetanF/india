#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = (low-1);
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void d(vector<int>& arr, int low, int high){
    if(low<high){
        int median = (low+high)/2;
        if(arr[low]>arr[high])  swap(arr[low],arr[high]);
        if(arr[low]>arr[median])  swap(arr[low],arr[median]);
        if(arr[median]>arr[high])  swap(arr[median],arr[high]);
        swap(arr[median],arr[high]);
        int pivot = partition(arr,low,high);
        d(arr,low,pivot-1);
        d(arr,pivot+1,high);
    }
}

void r(vector<int>& arr, int low, int high){
    if(low<high){
        int randomPivot = low+ rand()%(high-low+1);
        swap(arr[randomPivot],arr[high]);
        int pivot = partition(arr,low,high);
        r(arr,low,pivot-1);
        r(arr,pivot+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter no of elmeents: ";
    cin>>n;

    vector<int> arr(n), D, R;
    for(int i=0;i<n;i++){
        cout<<"element"<<i+1<<": ";
        cin>>arr[i];
    }
    D = arr;
    R = arr;

    auto start1 = chrono::high_resolution_clock::now();
    d(D,0,n-1);
    auto end1 = chrono::high_resolution_clock::now();
    double time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count() * 1e-6;

    auto start2 = chrono::high_resolution_clock::now();
    r(R,0,n-1);
    auto end2 = chrono::high_resolution_clock::now();
    double time2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count() * 1e-6;

    cout << endl;

    cout<<"sorted d \n";
    for(int i=0;i<n;i++){
        cout<<D[i];
    }    cout << endl;

    cout<<"sorted r \n";
    for(int i=0;i<n;i++){
        cout<<R[i];
    }

    size_t spaceComplexity = sizeof(arr) + sizeof(D) + sizeof(R);

    cout << "Deterministic Quicksort Time: " << fixed << time1 << " seconds" << endl;
    cout << "Randomized Quicksort Time: " << fixed << time2 << " seconds" << endl;
    cout << "Space Complexity: " << spaceComplexity << " bytes" << endl;

    return 0;
}