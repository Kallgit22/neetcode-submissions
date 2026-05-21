class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        
        // Step 1: Count frequencies
        for(int num : nums) {
            countMap[num]++;
        }

        int n = nums.size();
        // Step 2: Create buckets where index = frequency. 
        // Size is n + 1 so we can safely index up to n.
        vector<vector<int>> buckets(n + 1);

        // Step 3: Populate the buckets
        for(auto& it : countMap) {
            int element = it.first;
            int frequency = it.second;
            buckets[frequency].push_back(element);
        }

        vector<int> output;
        
        // Step 4: Traverse backwards to get the most frequent elements first
        for(int i = n; i >= 0; i--) {
            for(int element : buckets[i]) {
                output.push_back(element);
                
                // Stop immediately once we have collected k elements
                if(output.size() == k) {
                    return output;
                }
            }
        }

        return output;
    }
};
