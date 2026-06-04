#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;

    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);

    cnt += mergeSort(arr, mid + 1, high);

    cnt += merge(arr, low, mid, high);

    return cnt;
}

int countInversions(vector<int>& nums, int n) {
    return mergeSort(nums , 0, n - 1);
}

int main() {

    vector<int> nums = {5,4,3,2,1};

    cout<<countInversions(nums , nums.size());

    return 0;
}
