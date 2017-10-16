//merge overlapping intervals problem
#include <stdio.h>
#include <stdlib.h>


 // * Definition for an interval.
struct Interval {
    int start;
    int end;
};

typedef struct Interval interval;

/*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * len : populate the length of returned array of intervals in len
 */
int intersect(interval i1, interval i2){
    if((i1.start<i2.end)&&(i2.start<i1.end))
        return 1;
    else
        return 0;
} 
 
interval* merge(interval *intervals, int sz, int *len) {
    //printf("check21\n");
    int tmp[sz];
    int i,j;
    //printf("check22\n");
    for(i=0;i<sz;i++){
        for(j=i;j<sz;j++){
            if(intersect(intervals[i],intervals[j])){
                if(intervals[i].start<intervals[j].start)
                    intervals[j].start=intervals[i].start;
                else
                    intervals[i].start=intervals[j].start;
                if(intervals[i].end>intervals[j].end)
                    intervals[j].end=intervals[i].end;
                else
                    intervals[i].end=intervals[j].end;
            }
        }
    }
    //printf("check23\n");
    for(i=0;i<sz;i++){
        tmp[i]=1;
    }
    //printf("check24\n");
    for(i=0;i<sz;i++){
        if(tmp[i]==0)
            continue;
        for(j=i+1;j<sz;j++){
            if(intersect(intervals[i],intervals[j]))
                tmp[j]=0;
                //printf("j=%d\n",j );
        }
    }
    //printf("check25\n");
    ////printf("%d\n",*len );
    len=(int*)malloc(1*sizeof(int));
    for(i=0;i<sz;i++){
        //printf("check26%d\n",i);
        if(tmp[i]==1)
            *len++;
    }
    //printf("%d\n", *len);
    //printf("check27\n");
    interval* result=(interval*)malloc((*len)*sizeof(interval));
    int k=0;
    for(i=0;i<sz;i++){
        if(tmp[i]==1){
            result[k]=intervals[i];
            k++;
        }
    }
    //printf("check28\n");
    return result;
    
}


int main(){
    int sz=6;
    //printf("check1\n");
    interval intervals[6]={{6, 6}, {2, 9}, {3, 8}, {4, 7}, {5, 6}, {1, 10}};
    int i;
    int *len;
    //printf("check2\n");
    interval* result=merge(intervals, sz, len);
    len=(int*)malloc(sizeof(int));
    *len=sizeof(result)/sizeof(interval);
    //printf("check3\n");
    ////printf("len: %d\n", *len);
    //printf("check4\n");
    for(i=0;i<*len;i++)
        //printf("(%d,%d)\n", result[i].start, result[i].end);
    //printf("check5\n");
    return 0;


}