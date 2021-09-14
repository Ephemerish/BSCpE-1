#include <stdio.h>
#include <stdbool.h>
int arr[99999][99999],xsize,ysize[99999];
bool examine(int x, int y);
int bin(int largest);

int main() {
    int w,x,y;
    int largest=0;
    bool prime;

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
        largest=0;
        printf("\nLargest prime number found in arr%d, with size %d and its equivalent binary form: ",x,ysize[x]);
        for (y = 0; y < ysize[x]; y++) {
            prime=examine(x,y);
            if(prime) {
                if(largest < arr[x][y]) {
                    largest=arr[x][y];
                }
            }
        };
        printf("%d, ",largest);
        bin(largest);
        printf("\n");
    }
}

bool examine(int x, int y) {
    int num, flag, temp;
    num=arr[x][y];
    flag=0;

    for (temp = 2; temp <= num / 2; ++temp) {
        if (num % temp == 0) {
            flag = true;
            break;
        }
    }

    if (flag == 0) {
        return true;
    }
    else {
        return false;
    }
}

int bin(int largest) {

    int number,cnt,i;
    int bin[32];
    cnt=0;
    while(largest>0)
    {
        bin[cnt]=largest%2;
        largest=largest/2;
        cnt++;
    }
    for(i=(cnt-1); i>=0; i--)
        printf("%d",bin[i]);
    return 0;
}