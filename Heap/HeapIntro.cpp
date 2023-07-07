#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size+=1;
        int index = size;
        arr[index] = val;

        while(index>1) {
            int parent = index/2;
            if(arr[index] > arr[parent]) {
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else
            return;
        }
    }

    void print() {
        for(int i = 1;i<=size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap() {
        arr[1] = arr[size];
        size--;

        int parent = 1;
        while(parent<size) {
            int leftIndex = 2*parent;
            int rightIndex = 2*parent + 1;

            if(parent<size and arr[parent] < arr[leftIndex]) {
                swap(arr[parent],arr[leftIndex]);
                parent = leftIndex;
            }
            else if(parent<size and arr[parent] < arr[rightIndex]){
                swap(arr[parent],arr[rightIndex]);
                parent = rightIndex;
            }
            else
            return;
        }
    }

    void heapify(int arr[],int n,int index) {
        int largest = index;
        int left = 2*index;
        int right = 2*index + 1;

        if(left <= n and arr[largest] < arr[left]) {
            largest = left;
        }

        if(right <= n and arr[largest] < arr[right]) {
            largest = right;
        }

        if(largest != index) {
            swap(arr[largest],arr[index]);
            heapify(arr,n,largest);
        }
    }

    void heapSort(int arr[],int n) {
        int t = n;
        while(t>1) {
            swap(arr[t],arr[1]);
            t--;
            heapify(arr,t,1);
        }
        
    }
};

int main()
{
    heap h;
    h.insert(55);
    h.insert(50);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i = n/2;i>0;i--) {
        h.heapify(arr,n,i);
    }

    for(int i = 1;i<=n;i++) {
        cout<<arr[i]<<" "; 
    }cout<<endl;

    h.heapSort(arr,n);
    for(int i = 1;i<=n;i++) {
        cout<<arr[i]<<" "; 
    }cout<<endl;

    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(54);
    pq.push(55);
    cout<<pq.top()<<endl;

 return 0;
}