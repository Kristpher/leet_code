class Solution {
public:
    void merge(vector<int>& nums, int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;
        
        vector<int> v1(n1);
        vector<int> v2(n2);
        
        for (int i = 0; i < n1; ++i) {
            v1[i] = nums[p + i];
        }
        
        for (int i = 0; i < n2; ++i) {
            v2[i] = nums[q + 1 + i];
        }
        
        int i = 0, j = 0, k = p;
        while (i < n1 && j < n2) {
            if (v1[i] <= v2[j]) {
                nums[k] = v1[i];
                i++;
            } else {
                nums[k] = v2[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            nums[k] = v1[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            nums[k] = v2[j];
            j++;
            k++;
        }
    }

    void ms(vector<int>& nums, int p, int r) {
        if (p < r) {
            int q = p + (r - p) / 2;
            ms(nums, p, q);
            ms(nums, q + 1, r);
            merge(nums, p, q, r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        ms(nums, 0, nums.size() - 1);
        return nums;
    }
};
