class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j = numbers.size()-1;
        vector<int> ans;
        while(i<j)
        {
            cout<<i<<" "<<j<<endl;
            if((numbers[i]+numbers[j])==target)
            {
                cout<<numbers[i]<<" ans "<<numbers[j]<<endl;
                ans={i+1,j+1};
                break;
            }
            if((numbers[i]+numbers[j])<target)
                i++;
            else
                j--;
        }
        return ans;
    }
};
