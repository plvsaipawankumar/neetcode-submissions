class Solution {
public:
    vector<string> ans;
    void ComboNumber(map<char,vector<string>> phone,string digits,int i,string word)
    {
        if(i==digits.size())
        {
            ans.push_back(word);
            return ;
        }
        cout<<"word : "<<word<<endl;
        for(int j=0;j<phone[digits[i]].size();j++)
            ComboNumber(phone,digits,i+1,word+phone[digits[i]][j]);

        return ;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return ans;
        map<char,vector<string>> phone;
        phone['2'] = {"a","b","c"};
        phone['3'] = {"d","e","f"};
        phone['4'] = {"g","h","i"};
        phone['5'] = {"j","k","l"};
        phone['6'] = {"m","n","o"};
        phone['7'] = {"p","q","r","s"};
        phone['8'] = {"t","u","v"};
        phone['9'] = {"w","x","y","z"};
        ComboNumber(phone,digits,0,"");
        return ans;
    }
};
