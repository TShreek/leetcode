using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> aux(nums.size());
        mergeSort(nums, 0, nums.size() - 1, aux);
        return nums;
    }

    void mergeSort(vector<int>& arr, int left, int right, vector<int>& aux) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, aux);       // Sort left half
            mergeSort(arr, mid + 1, right, aux); // Sort right half
            merge(arr, left, mid, right, aux);   // Merge sorted halves
        }
    }

    void merge(vector<int>& arr, int left, int mid, int right, vector<int>& aux) {
        for (int i = left; i <= right; i++) {
            aux[i] = arr[i];
        }

        int i = left, j = mid + 1, k = left;

        // Merge back into the original array
        while (i <= mid && j <= right) {
            if (aux[i] <= aux[j]) {
                arr[k++] = aux[i++];
            } else {
                arr[k++] = aux[j++];
            }
        }

        while (i <= mid) {
            arr[k++] = aux[i++];
        }
    }
};
