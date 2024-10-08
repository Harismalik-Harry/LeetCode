class Solution {
public:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int p = start;

        while (start <= end) {
            // Move start forward until we find an element >= pivot
            do {
                start++;
            } while (start < end && nums[start] < pivot);
            
            // Move end backward until we find an element <= pivot
            do {
                end--;
            } while (start < end && nums[end] > pivot);
            
            // Only swap if start is still less than end
            if (start < end) {
                swap(nums[start], nums[end]);
            }
        }

        // Place pivot in its correct position
        swap(nums[p], nums[end]);
        return end; // Return the pivot index
    }

    void quicksort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int p = partition(nums, start, end);
            quicksort(nums, start, p);       // Sort the left half
            quicksort(nums, p + 1, end);     // Sort the right half
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size());
        return nums;
    }
};
