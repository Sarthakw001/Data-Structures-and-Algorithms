#include <iostream>
#include <vector>
using namespace std;

int main() {
  
	
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
            int x ;
            cin>>x;
	        a[i] = x;
	    }
	    vector<int> ans;
	    for(int i=0;i<n;i++)
	    {
	        if(k == 0)
            {
                break;
            }
	       
	        ans.push_back(a[i]);
	         if(i== (n-1))
	        {
	            i = 0;
	        }
            k--;
	    }
	    for(int i=0;i<ans.size();i++)
	    {
	        cout<<ans[i]<<" ";
	    }
	
	return 0;
}
