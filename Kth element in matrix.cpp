#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
      return 0;
}



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int min_ele=mat[0][0],max_ele=mat[0][n-1];
  for(int i=1;i<n;i++){
      min_ele=min(min_ele,mat[i][0]);
      max_ele=max(max_ele,mat[i][n-1]);
  }
  while(min_ele<max_ele){
      int mid=(min_ele+max_ele)/2;
      int ele=0;
      for(int i=0;i<n;i++)
      ele+=upper_bound(mat[i],mat[i]+n,mid)-mat[i];
      if(ele<k)
      min_ele=mid+1;
      else
      max_ele=mid;
  }
  return max_ele;
  
}
