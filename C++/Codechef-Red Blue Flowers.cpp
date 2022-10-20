Codechef-Red Blue Flowers

//code

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=20007;
const int mod=1e9+7;
const double eps=1e-9;
const double pi=    3.14159265358979323846;
using namespace std;  
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    op_set;

int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int t;
   cin >> t;
   while(t--)
   {
        int n;
        cin >> n;

        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
            cin >> b[i];

        int sum=accumulate(a.begin(),a.end(),0);

        vector<int> dp(sum+1,-1);
        dp[sum]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=sum-a[i];j++)
            {
                if(dp[j+a[i]]!=-1)
                    dp[j]=std::max(dp[j],b[i]+dp[j+a[i]]);
            }
        }

        int ans=0;
        for(int i=0;i<=sum;i++)
        {
            if(dp[i]!=-1)
                ans=std::max(ans,std::min(i,dp[i]));
        }

        cout << ans << "\n";
   }
}
