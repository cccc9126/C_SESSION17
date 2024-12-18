#include <stdio.h>
void inputArray(int *a,int *length);
void printEven(int *a,int *length);
void printPrime(int *a, int *length);
void reverseArray(int *a, int *length);
void increase(int *a, int *length);
void decrease(int *a, int *length);
void binarySearch(int *a,int *length);
int main(int argc, const char * argv[]) {
    int a[100];
    int length;
    int choice;
    int sort;
    do {
        printf("\tMENU\n");
        printf("1. Nhập vào số phần tử và từng phần tử\n");
        printf("2. In ra các phần tử là số chẵn\n");
        printf("3. In ra các phần tử là số nguyên tố\n");
        printf("4. Đảo ngược mảng\n");
        printf("5. Sắp xếp mảng\n");
        printf("6. Nhập vào một phần tử và tìm kiếm phần tử trong mảng\n");
        printf("7. Thoát\n");
        printf("Hãy nhập lựa chọn của bạn :");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                inputArray(a,&length);
                break;
            case 2:
                printEven(a,&length);
                break;
            case 3:
                printPrime(a,&length);
                break;
            case 4:
                reverseArray(a,&length);
                break;
            case 5:
                sort = 0;
                while(sort !=1&&sort!=2){
                    printf("1. Tăng dần\n2. Giảm dần");
                    printf("hãy nhập lựa chọn của bạn : ");
                    scanf("%d",&sort);
                }
                if(sort==1){
                    increase(a,&length);
                }else if(sort==2){
                    decrease(a,&length);
                }
                break;
            case 6:
                binarySearch(a,&length);
                break;
            default:
                break;
        }
    } while (choice!=7);
    return 0;
}
void inputArray(int *a,int *length){
    printf("Hãy nhập số phần tử cho mảng : ");
    scanf("%d", &*length);
    for(int i =0;i<*length;i++){
        printf("Hãy nhập phần tử arr[%d] : ",i);
        scanf("%d",&*(a+i));
    }
}
void printEven(int *a,int *length){
    for(int i=0;i<*length;i++){
        if(*(a+i)%2==0){
            printf("%d\t",*(a+i));
        }
    }
    printf("\n");
}
void printPrime(int *a, int *length){
    for(int i = 0;i<*length;i++){
        if(*(a+i)>=2){
            int count = 0;
            for (int j = 2; j<*(a+i); j++) {
                if(*(a+i)%j==0){
                    count++;
                }
            }
            if(count==0){
                printf("%d",*(a+i));
            }
        }
    }
}
void reverseArray(int *a, int *length){
    for(int i = 0;i<*length/2;i++){
        int temp = *(a+i);
        *(a+i)=*(a+*length-1-i);
        *(a+*length-1-i)=temp;
    }
    for(int i = 0;i<*length;i++){
        printf("%d\t",*(a+i));
    }
    printf("\n");
}
void increase(int *a, int *length){
    for(int i=0;i<*length-1;i++){
        int min =i;
        for(int j=i+1;j<*length;j++){
            if(*(a+j)<*(a+min)){
                int temp = *(a+min);
                *(a+min) = *(a+j);
                *(a+j)=temp;
            }
        }
    }
    for(int i=0;i<*length;i++){
        printf("%d\t",*(a+i));
    }
    printf("\n");

}
void decrease(int *a, int *length){
    for(int i=0;i<*length-1;i++){
        int max =i;
        for(int j=i+1;j<*length;j++){
            if(*(a+j)>*(a+max)){
                int temp = *(a+max);
                *(a+max) = *(a+j);
                *(a+j)=temp;
            }
        }
    }
    for(int i=0;i<*length;i++){
        printf("%d\t",*(a+i));
    }
    printf("\n");

}
void binarySearch(int *a,int *length){
    int start =0;
    int end = *length-1;
    int mid;
    int number;
    printf("%d %d",start,end);
    printf("Hãy nhập phần tử bạn muốn tìm kiếm : ");
    scanf("%d",&number );
    while(start<=end){
        mid=start + (end - start) / 2;
        if (*(a+mid)==number){
            printf("vị trí %d", mid);
            return;
            
        }else if(*(a+mid)<number){
            start = mid+1;
        }else if(*(a+mid)>number){
            end = mid-1;
        }
    }

}
