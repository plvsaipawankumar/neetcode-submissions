class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j,r=numbers.size()-1,l=0;
        while(l<r){
            if(numbers[r]+numbers[l]<target){
                l++;
            }
            else if (numbers[r]+numbers[l]>target){
                r--;
            }
            else{
                return {l+1,r+1};
            }
        }
        return {};
    }
};
