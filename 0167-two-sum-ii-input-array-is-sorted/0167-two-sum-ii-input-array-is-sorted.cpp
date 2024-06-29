class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r=numbers.size()-1;
        int l=0;
        vector<int>v(2);
        while(l<r)
        {
            if(numbers[l]+numbers[r]==target)
            {
              v[0]=l+1;
              v[1]=r+1;
                break;
            }
            else if(numbers[l]+numbers[r]>target)
            {
                r--;
            }
            else
            l++;


        }
        return v;
    }
};