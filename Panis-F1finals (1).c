#include <stdio.h>
#include <stdbool.h>
int arr[99999][99999],xsize,ysize[99999];
bool examine(int x, int y);

int main() {
    int w,x,y;
    bool acend;

    printf("Enter number for two dimentional array:");
    scanf("%d",&xsize);

    for(w = 0; w < xsize; w++) {
        printf("Enter the size of arr%d:",w);
        scanf("%d",&ysize[w]);
    }

    for(x = 0; x < xsize; x++) {
        printf("\nEnter elements for set %d :\n", x+1);
        for (y = 0; y < ysize[x]; y++)
            scanf("%d", &arr[x][y]);
    }

    for(x = 0; x < xsize; x++) {
        printf("\nNumber whose digit arrangement are acending, arr%d with size %d:\n",x,ysize[x]);
        for (y = 0; y < ysize[x]; y++) {
            acend=examine(x,y);
            if(acend) {
                printf("%d ", arr[x][y]);
            }
        }
        printf("\n");
    }
}

bool examine(int x, int y) {
    int a,b,temp,q=1,r,srem[99999],rem[99999], val, z;
    int count=0;
    val=arr[x][y];
    temp=val;

    for(z=0; q != 0; z++) {
        r=temp%10;
        srem[z]=r;
        q=temp/10;
        temp=q;
    }

    temp=0;
    for(a=0; a<z; a++) {
        for(b=0; b<z-1; b++) {
            if(srem[b]>srem[b+1]) {
                temp=srem[b];
                srem[b]=srem[b+1];
                srem[b+1]=temp;
            }
        }
    }

    temp=val;
    q=1;
    for(z=0; q != 0; z++) {
        r=temp%10;
        rem[z]=r;
        q=temp/10;
        temp=q;
    }
    a=0;
    b=z-1;
    while(a<z||b>-1) {
        if(rem[a]==srem[b]) {
            count++;
        }
        a++;
        b--;
    }

    if(z==1) {
        return false;
    }
    else if(count==z) {
        return true;
    }
    else {
        return false;
    }
}