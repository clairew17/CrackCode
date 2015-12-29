
#include"header.h"

/*void quicksort(vector<int> &arr, int left, int right){
    int mid = (left+right)/2;
    cout<<"QS:"<<left<<","<<right<<"\n";

    int i = left;
    int j = right;
    int pivot = arr[mid];

    while(left<j || i<right)
    {
        while(arr[i]<pivot)
        i++;
        while(arr[j]>pivot)
        j--;

        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }else{
            if(left<j)
                quicksort(arr, left, j);
            if(i<right)
                quicksort(arr,i,right);
            return;
        }
    }
}*/
int partition(vector<int> &arr, const int left, const int right) {
    const int mid = left + (right - left) / 2;
    const int pivot = arr[mid];
    // move the mid point value to the front.
    swap(arr[mid],arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    //i-1: the last variable < pivot
    swap(arr[i - 1],arr[left]);
    return i - 1;
}

void quicksort(vector<int> &arr, const int left, const int right){
    if (left >= right) {
        return;
    }
    int part = partition(arr, left, right);
    quicksort(arr, left, part - 1);
    quicksort(arr, part + 1, right);
}

int main() { 
    vector<int> arr= {110, 5, 10,3 ,22, 100, 1, 23};
    PrintVector(arr);
    quicksort(arr, 0, arr.size()-1);
    PrintVector(arr);
    return 0;
}