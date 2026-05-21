class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map_data;

    for(int i = 0; i < nums.size(); i++){
        map_data[nums[i]] = i;
    }

    for(int i = 0; i < nums.size(); i++){
        int difference = target - nums[i];

        if (map_data.count(difference) && map_data[difference] != i) {
            return {i, map_data[difference]}; // Use {} for vector return
        }
    }
    return {};
}
};
