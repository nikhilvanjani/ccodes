#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        char a1[1000],a2[1000];
        int b1[1000],b2[1000];
        int j=0,k=0;
        char s[200],t[1000];
        scanf("%s",s);
        scanf("%s",t);
        int slen=strlen(s);
        int tlen=strlen(t);
        printf("%d %d\n",slen,tlen );
        int l;
        for(l=0;l<slen;l++){
            a1[j]=s[l];
            b1[j]=1;
            while(((int)s[l]==(int)s[l+1])&&(l<slen)){
                b1[j]++;
                l++;
            }
            l++;
            j++;
        }
        for(l=0;l<tlen;l++){
            a2[k]=s[l];
            b2[k]=1;
            while(((int)t[l]==(int)t[l+1])&&(l<tlen)){
                b2[k]++;
                l++;
            }
            l++;
            k++;
        }
        int len1=j,len2=k;
        if(len1!=len2)
            printf("NO\n");
        else{
            int flag=1;
            for(j=0;j<len1;j++){
                if(((int)a1[j]!=(int)a2[j])||(b1[j]>b2[j])){
                    flag=0;
                    break;
                }
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
        
    }
    return 0;
}
