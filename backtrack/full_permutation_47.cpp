class Solution {
public:
    string vtos(vector<int> &v){
        string s;
        for(auto i:v){
            s = s+to_string(i);
        }
        return s;
    }
    unordered_set<string> s1;
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len){
        if(first == len){
            if(!s1.count(vtos(output))){
                res.emplace_back(output);
                s1.insert(vtos(output));
            }
            return ;
        }

        for(int i = first ; i < len ; ++i){
            swap(output[first], output[i]);
            backtrack(res, output, first + 1, len);
            swap(output[first], output[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }
};
