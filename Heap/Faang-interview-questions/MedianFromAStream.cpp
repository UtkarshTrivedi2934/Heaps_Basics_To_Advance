//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<double> first;
    priority_queue<double, vector<double>, greater<double>> second;
    
    public:
    void insertHeap(int &x) {
        // make sure that first will take only small elements 
        // and if this will create unbalanced sizes then balanceHeaps() will
        // take care of this and send the smallest element from second heap to 
        // first and thus both heaps will have equal/mid elements and there 
        // top will give the medians :)
        
        if(first.size() == 0 || first.top() > x) first.push(x);
        else second.push(x);
        
        balanceHeaps();
    }
    
    void balanceHeaps() {
        if(first.size() > second.size() + 1) {
            second.push(first.top()); first.pop();
            
        } else if(second.size() > first.size()) {
            first.push(second.top()); second.pop();
        }
    }
    
    //Function to return Median.
    double getMedian() {
        double median;
        
        if(first.size() == second.size()) {
            median = (first.top() + second.top()) / 2.0;
        } else {
            median = first.top();
        }
        
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends