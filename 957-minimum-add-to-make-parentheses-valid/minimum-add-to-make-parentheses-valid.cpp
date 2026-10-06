class Solution {
public:
    int minAddToMakeValid(string s) {
        int add = 0,open = 0;
        for (char ch : s)
        {
            if(ch == '(')
            {
                open++;
            }
            else if(ch == ')')
            {
                if (open>0) 
                {
                    open--;
                }
                else 
                {
                    add++;
                }
            }
        }
        return open + add;
    }
};