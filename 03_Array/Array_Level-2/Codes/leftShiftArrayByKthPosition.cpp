#include<iostream>
using namespace std;

void shiftArrayByKthPosition(int arr[], int size, int k) {

    // Create an array of 'k' size to store Kth element
    int temp[k];

    // Store the first 'Kth' element of array in 'temp'
    for(int i = 0; i < k; i++){
        temp[i] = arr[i];
    }

    // Left shift the remaining element of array
    for(int i = 0; i < size - k; i++){
            arr[i] = arr[i + k];
    }

    // Copy back the elements from 'temp' to original array
    for(int i = size - k; i < size; i++){
        arr[i] = temp[i - (size - k)];
    }
}


int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int k;

    cout << "Enter the number for K : " << endl;
    cin >> k;

    shiftArrayByKthPosition(arr, size, k);
    
    // Print Array
    cout << "Shifted Array : " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}