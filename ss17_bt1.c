#include <stdio.h>
void inputArray(int *a,int *m);
void printArray(int *a,int *m);
int sumItem(int *a,int *m);
int maxItem(int *a,int*m);
int main(int argc, const char * argv[]) {
    int a[100];
    int m;
    int choice;
    do {
        printf("\tMENU\n");
        printf("1. Nhập vào số phần tử và từng phần tử\n");
        printf("2. Hiển thị các phần tử trong mảng\n");
        printf("3. Tính độ dài mảng\n");
        printf("4. Tính tổng các phần tử trong mảng\n");
        printf("5. Hiện thị phần tử lớn nhất\n");
        printf("6. Thoát\n");
        printf("Hãy nhập lựa chọn của bạn : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                inputArray(a,&m);
                break;
            case 2:
                printArray(a,&m);
                break;
            case 3:
                printf("Độ dài của mảng là : %d",m);
                break;
            case 4:
                printf("Tổng các phần tử trong mảng là : %d\n", sumItem(a, &m));
                break;
            case 5:
                printf("Phần tử lớn nhất trong mảng là : %d\n", maxItem(a,&m));
                break;
            default:
                printf("Lựa chọn không hợp lệ...........\n");
                break;
        }
    } while (choice!=6);
    return 0;
}
void inputArray(int *a,int *m){
    printf("Hãy nhập số phần tử cho mảng : ");
    scanf("%d",&*m);
    for(int i = 0;i<*m;i++){
        printf("Nhập phần tử arr[%d] = ",i);
        scanf("%d",&*(a+i));
    }
}
void printArray(int *a,int *m){
    printf("Mảng của bạn là :\n");
    for(int i=0;i<*m;i++){
        printf("%d\t",*(a+i));
    }
    printf("\n");
}
int sumItem(int *a,int *m){
    int sum=0;
    for(int i =0;i<*m;i++){
        sum+=*(a+i);
    }
    return sum;
}
int maxItem(int *a,int*m){
    int max=*a;
    for(int i=0;i<*m;i++){
        if(*(a+i)>max){
            max=*(a+i);
        }
    }
    return max;
}
