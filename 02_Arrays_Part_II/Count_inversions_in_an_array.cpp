int merge(vector<int> &arr, int low, int mid, int high) {
    // Temporary array to store merged elements
    vector<int> temp;
    // Starting index of left half
    int left = low;
    // Starting index of right half
    int right = mid + 1;
    // Variable to count inversions
    int cnt = 0;
    // Merge elements in sorted order and count inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //only significant change in mergesort
            right++;    // All remaining left elements are inversions
        }
    }

    // If left half still has elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If right half still has elements
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    // Return inversion count
    return cnt;
}

// Merge sort function that counts inversions
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt =0;
    // Base case
    if (low >= high) return;
    int mid = (low + high) / 2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid + 1, high);
    cnt+=merge(arr, low, mid, high);
    return cnt;
}

// Function to get number of inversions
int numberOfInversions(vector<int>& a, int n) {
    return mergeSort(a, 0, n-1);
}
