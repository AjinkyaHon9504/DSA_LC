class Solution {
public:

    void merge(vector<int>& arr, int left, int mid, int right) {

        vector<int> temp;

        int i = left;
        int j = mid + 1;

        // Compare elements from both sorted halves
        while(i <= mid && j <= right) {

            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        // Remaining elements in left half
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining elements in right half
        while(j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy sorted elements back
        for(int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }


    void mergeSort(vector<int>& arr, int left, int right) {

        // Base case
        if(left >= right)
            return;

        // Find middle
        int mid = left + (right - left) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both sorted halves
        merge(arr, left, mid, right);
    }


    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};