#include<stdio.h>

int arr[4][6] = {
    {1,2,3,4,5,6},
    {8,10,12,14,16,18},
    {21,24,27,30,33,36},
    {40,44,48,52,56,60}
},x,y,select;

void displayall();
void counteven();
void countodd();
void largestrow();
void lowestcolumn();

int main()
{
    printf("Name: Ivy N. Noguera BSIT - 2\n\n");

    printf(">>4x6 Array<<\n");
    printf("Select a task to perform:\n");
    printf("[1]-Display all elements\n");
    printf("[2]-Count even numbers\n");
    printf("[3]-Count odd numbers\n");
    printf("[4]-Largest number in a row\n");
    printf("[5]-Smallest number is a column\n");
    printf("[0]-Exit");

    for(;;) {
        printf("\n==========================\n");
        printf("Perform task <- ");
        scanf("\n %d", &select);

        switch (select) {
        case 1:
            displayall();
            break;

        case 2:
            counteven();
            break;

        case 3:
            countodd();
            break;

        case 4:
            largestrow();
            break;

        case 5:
            lowestcolumn();
            break;

        case 0: {
            //End Program
            return 0;
        }

        default: {
            printf("Invalid Input");
            break;
        }
        }
    }
    return 0;
}

void displayall() {
//Display all The element
    printf("Display all Elements\n");
    for(x=0; x<4; x++) {
        for(y=0; y<6; y++) {
            printf("%d ", arr[x][y]);
            if(y==5&&x!=3) {
                printf("\n");
            }
        }
    }
}

void counteven() {
//Count even numbers
    int count=0;
    printf("Count even numbers\n");
    for(x=0; x<4; x++) {
        for(y=0; y<6; y++) {
            if(arr[x][y]%2==0) {
                count++;
            }
        }
    }
    printf("Even Numbers -> %d", count);
}

void countodd() {
//Count odd numbers
    int count=0;
    printf("Count odd numbers\n");
    for(x=0; x<4; x++) {
        for(y=0; y<6; y++) {
            if(arr[x][y]%2!=0) {
                count++;
            }
        }
    }
    printf("Odd Numbers -> %d", count);
}

void largestrow() {
//Display largest number in a row
    int largest=0;
    printf("Largest in row <- ");
    scanf("%d",&x);
    x--;
    for(y=0; y<6; y++) {
        if(arr[x][y]>largest) {
            largest=arr[x][y];
        }
    }
    printf("Largest in row%d -> %d",x+1,largest);
}

void lowestcolumn() {
//Display lowest number in a Column
    int lowest=99999;
    printf("Lowest in column <- ");
    scanf("%d",&y);
    y--;
    for(x=0; x<3; x++) {
        if(arr[x][y]<lowest) {
            lowest=arr[x][y];
        }
    }
    printf("Lowest in column%d -> %d",y+1,lowest);
}