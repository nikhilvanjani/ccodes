#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int middle;
    int end;
};

typedef struct Interval interval;

int main(){
    int sz=6;
    interval intervals[6]={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18}};
    int i;
    for(i=0;i<sz;i++)
        printf("(%d,%d,%d)\n", intervals[i].start, intervals[i].middle, intervals[i].end);

    return 0;

}