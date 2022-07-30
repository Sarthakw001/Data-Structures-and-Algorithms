#include <bits/stdc++.h>
using namespace std;

//Approach -> either use hashing Function or ordered_map or unordered_map

// hashing -> T.C -> O(N) , S.C -> O(no. of alphabets)
// ordered_map -> T.C -> O(N*log(n))  S.C -> O(no. unique characters in string)
// unordered_map -> T.C -> O(N)  S.C -> O(no. unique characters in string)



// unordered_map  approach

vector<char> duplicates(string s)
{
    unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    vector<char> ans;
    for(auto i: mp)
    {
        if(i.second>1)
        {
            ans.push_back(i.first);
        }
    }
    return ans;
}

int main()
{
    vector<char> ans = duplicates("aaaaaaaaaaaaaaaaaaa");
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}