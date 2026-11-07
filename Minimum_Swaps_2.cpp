int minimumSwaps(Vector<int> arr) {
    size_t sizeArr = arr.size();
    int swapCount = 0;

    for (int i = 0; i < sizeArr; i++) {
        if(arr[i] - i != 1){
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
            swapCount++;
            i--;
        }
    }

    return swapCount;
}
