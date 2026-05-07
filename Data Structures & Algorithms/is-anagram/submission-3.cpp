class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[123];
        int i;
        for(i=0;i<123;i++)arr[i]=2;

        for(i=0;i<s.size();i++){
            arr[s[i]]++;
        }
        
        for(i=0;i<t.size();i++){
            cout<<arr[t[i]];
            arr[t[i]]--;
        }

        for(i=0;i<123;i++)
        {
            if(arr[i]!=2)
                return false;
        }
        
        return true;
    }
};
