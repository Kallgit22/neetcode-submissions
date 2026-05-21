class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int a = nums[i];
                int b = nums[j];
                if(a==b){
                    return true;
                }
            }
        }
        return false;
    }
};