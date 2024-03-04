#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
int pivot=arr[low];

int c=0;
for(int i=low+1;i<=high;i++){
    if(arr[i]<=pivot)
    c++;
  
}

int pivotIndex=low+c;
  swap(arr[low],arr[pivotIndex]);
int i=low;
int j=high;
while(i<pivotIndex|| j>pivotIndex ){
while(arr[i]<=pivot){
    i++;
}
while(arr[j]>pivot){
    j--;
}

if(i<pivotIndex&& j>pivotIndex){
    swap(arr[i++],arr[j--]);
}

}
return pivotIndex;

}

void qs(int arr[],int low,int high){
    if(low>=high){
        return;
    }
int index=partition(arr,low,high);
qs(arr,low,index-1);
qs(arr,index+1,high);

}

int main(){
int n=7;
int arr[]={2,4,1,67,2,6,15};
qs(arr,0,n-1);
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}


    return 0;
}