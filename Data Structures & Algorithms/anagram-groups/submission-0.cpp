class Solution {
public:
    // Custom hash function for vector<int> to use it as an unordered_map key
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::map<vector<int>, vector<string>> anagram_map;
    
    for (const string& s : strs) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        anagram_map[count].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto& pair : anagram_map) {
        result.push_back(pair.second);
    }
    return result;
}
};
