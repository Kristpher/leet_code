class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>map1;
        for(int i=0;i<target.size();i++){
            map1[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(map1[arr[i]]>=1)
            {
                map1[arr[i]]--;
            }
            else{
                return false;
            }
        }
       return true;
    }
};