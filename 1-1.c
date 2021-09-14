#include<stdio.h>

int main()
{
    printf("Name: Ivy N. Noguera BSIT - 2\n\n");

    int arr[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    },x,y;
    char select;
    
    printf(">>3x4 Array<<\n");
    printf("Select a task to perform:\n");
    printf("[a]-Display all elements\n");
    printf("[b]-Display all elements of a row\n");
    printf("[c]-Display all elements of a column\n");
    printf("[d]-Display all elements\n");
    printf("[0]-Exit");

    for(;;) {
        printf("\n==========================\n");
        printf("Perform task <- ");
        scanf("\n %c", &select);

        switch (select) {
        case 'a': {
            //Display all The element
            printf("Display all Elements\n");
            for(x=0; x<3; x++) {
                for(y=0; y<4; y++) {
                    printf("%d ", arr[x][y]);
                    if(y==3&&x!=2) {
                        printf("\n");
                    }
                }
            }
        }
        break;

        case 'b': {
            //Display Row
            printf("Display Row <- ");
            scanf("%d",&x);
            x--;
            for(y=0; y<4; y++) {
                printf("%d ", arr[x][y]);
            }
        }
        break;

        case 'c': {
            //Display Column
            printf("Display Column <- ");
            scanf("%d",&y);
            y--;
            for(x=0; x<3; x++) {
                printf("%d", arr[x][y]);
                if(x!=2) {
                    printf("\n");
                }
            }
        }
        break;

        case 'd': {
            //Display Sum and Average
            int total=0;
            float ave=0;
            for(x=0; x<3; x++) {
                for(y=0; y<4; y++) {
                    total+= arr[x][y];
                }
            }
            ave=total/12;
            printf("Sum of all the element -> %d", total);
            printf("\nAverage of all elements -> %.2f", ave);
        }
        break;

        case '0': {
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