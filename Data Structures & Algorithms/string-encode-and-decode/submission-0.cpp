class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto str:strs){
            s += to_string(str.length()) + "#" + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> es;
        int i = 0;
        while (i < s.length()){
            int hashPos = s.find("#", i);
            int size = stoi(s.substr(i, hashPos - i));
            string exS = s.substr(hashPos + 1, size);
            es.push_back(exS);
            i = hashPos + 1 + size;
        }
        return es;
    }
};
