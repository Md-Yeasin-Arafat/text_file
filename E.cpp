#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    int t;
    cin>>t;

    for(int i=1;i<=t;i++){

        int p;
        cin>>p;

        int arr[p],total=0,flag=0,cnt1=0,cnt2=0;
        for(int i=0;i<p;i++){
            cin>>arr[i];
            if(arr[i]>0){
                total+=arr[i];
                cnt1++;
                if(flag==0)cnt2++;
            }
            if(arr[i]<0 && cnt2>0)flag=1;
        }

        int sum1=0;
        for(int i=0;i<(p+1)/2;i++){
            if(arr[i]>0){
                for(int j=(p+1)/2 -1;j>i;j-- ){
                    if(arr[j]<0){
                        int q;
                        q=arr[j];
                        arr[j]=arr[i];
                        arr[i]=q;
                        sum1++;
                        break;
                    }
                }
            }
        }

        int sum2=0;
        for(int i=(p+1)/2;i<p;i++){
            if(arr[i]<0){
                for(int j=p-1;j>i;j--){
                    if(arr[j]>0){
                        int q;
                        q=arr[j];
                        arr[j]=arr[i];
                        arr[i]=q;
                        sum2++;
                        break;
                    }
                }
            }
        }

        if(cnt1==cnt2)cout<<"Case "<<i<<": "<<total<<" "<<0<<endl;
        else cout<<"Case "<<i<<": "<<total<<" "<<sum1+sum2<<endl;

    }

    return 0;
}




