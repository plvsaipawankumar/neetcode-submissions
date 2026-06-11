class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i,j,n=matrix.size(),m=matrix[0].size();
        int mid,row=0,l=0,r=n-1;
        while(l<=r){
            mid= (l+r)/2;
            cout<<"mid : "<<mid<<"matrix[mid][0] : "<<matrix[mid][0]<<"matrix[mid][m-1] : "<<matrix[mid][m-1]<<endl;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                row=mid;
                break;
            }
            else if(matrix[mid][0]>target)
                r=mid-1;
            else
                l= mid+1;
        }
        cout<<"row : "<<row<<endl;
        l=0 , r= m-1; 
        while(l<=r){
            mid=(l+r)/2;
            if(matrix[row][mid]<target)
                l=mid+1;
            else if(matrix[row][mid]>target)
                r=mid-1;
            else
                return true;
        }
        return false;
    }
};
