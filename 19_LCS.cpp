#include<iostream>
#include<vector>
using namespace std;

int LCS(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
            if(s1[i-1]==s2[j-1])
                dp[i][j]= 1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[n1][n2];
}
int main()
{

    string s1,s2;
    cout<<"Enter the first String: ";
    cin>>s1;
    cout<<"Enter the second String: ";
    cin>>s2;
    int ans= LCS(s1,s2);
    cout<<"L Nargest common subsequence: "<<ans;


}
