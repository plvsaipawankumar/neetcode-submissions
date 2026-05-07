class MedianFinder {
private:
    vector<int>elements;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        int i,j,n=elements.size()+1;
        elements.push_back(num);
        for(i=0;i<n-1;i++)
        {
            if(elements[i]>num)
                break;
        }
        for(j=n-1;j>i;j--)
            swap(elements[j],elements[j-1]);
        cout<<"num : "<<num<<endl;
        return;
    }
    
    double findMedian() {
        int i,n=elements.size();
        for(i=0;i<n;i++)
        {
            cout<<elements[i]<<",";
        }cout<<endl;
        if(n>=2)
        {
            cout<<"n/2 : "<<elements[n/2]<<" n/2-1 :"<<elements[(n/2)-1]<<endl;
        }
        double ans=elements[n/2];
        return (n%2==0)?(ans+(double)elements[(n/2)-1])/2:ans;
    }
};
