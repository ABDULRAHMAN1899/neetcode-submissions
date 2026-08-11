#include <bits/stdc++.h>
class Solution {
public:
    int t[101][101][201];
    bool solve(int i,int j,int k,
    string & s1,string & s2,string & s3){
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        if(i==n1 && j==n2 && k==n3){
            return true;
        }
        if(k>=n3){
            return false;
        }
        if(t[i][j][k]!=-1){
            return t[i][j][k];
        }
        bool result=false;
        if(s1[i]==s3[k]){
            result=solve(i+1,j,k+1,s1,s2,s3);
        }
        if(result==true){
            return t[i][j][k]=result;
        }
        else if(s2[j]==s3[k]){
            result=solve(i,j+1,k+1,s1,s2,s3);
        }
        return t[i][j][k]=result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        memset(t,-1,sizeof(t));
        if((n1+n2)!=n3){
            return false;
        }
        return solve(0,0,0,s1,s2,s3);

    }
};
