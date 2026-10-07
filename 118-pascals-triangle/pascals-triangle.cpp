class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long el = 1;
        vector <int> ans;
        ans.push_back(1);
        for (int i = 1 ; i <= rowIndex ; i++)
        {
            el = el * (rowIndex-i+1);
            el = el / i;
            ans.push_back(el);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> final;
        for (int i = 0 ; i < numRows  ; i++)
        {
           final.push_back(getRow(i));
        }
        return final;
    }
};