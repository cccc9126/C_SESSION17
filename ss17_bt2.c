
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void inputArray(char *a);
char printArray(char *a);
void letter(char *a,int *length);
void number(char *a,int *length);
void special(char *a,int *length);
int main(int argc, const char * argv[]) {
    char a[100];
    int choice;
    int length;
    do {
        printf("\tMENU\n");
        printf("1. Nhập vào chuỗi\n");
        printf("2. In ra chuỗi\n");
        printf("3. Đếm số lượng chữ cái trong chuỗi và in ra\n");
        printf("4. Đếm số lượng chữ số trong chuỗi và in ra\n");
        printf("5. Đếm số lượng kí tự đặc biệt trong chuỗi và in ra\n");
        printf("6. Thoát\n");
        printf("Hãy nhập lựa chọn của bạn :");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                inputArray(a);
                break;
            case 2:
                printArray(a);
                break;
            case 3:
                letter(a,&length);
                break;
            case 4:
                number(a,&length);
                break;
            case 5:
                special(a,&length);
                break;
            default:
                break;
        }
    } while (choice!=6);
    
    return 0;
}
void inputArray(char *a){
    printf("Hãy nhập một chuỗi bất kì : ");
    fgets(a, 100, stdin);
}
char printArray(char *a){
    printf("%s",a);
    return *a;
}
void letter(char *a,int *length){
    int count=0;
    *length = (int)strlen(a);
//    a[*length-1]='\0';
//    *length = (int)strlen(a);
    for(int i=0;i<*length;i++){
        if(isalpha(*(a+i))){
            count++;
        }
    }
    printf("Số ký tự trong chuỗi là : %d\n",count);
}void number(char *a,int *length){
    int count=0;
    *length = (int)strlen(a);
//    a[*length-1]='\0';
//    *length = (int)strlen(a);
    for(int i=0;i<*length;i++){
        if(isdigit(*(a+i))){
            count++;
        }
    }
    printf("Số chữ số trong chuỗi là : %d\n",count);
}
void special(char *a,int *length){
    int count=0;
    *length = (int)strlen(a);
//    a[*length-1]='\0';
//    *length = (int)strlen(a);
    for(int i=0;i<*length;i++){
        if(!isdigit(*(a+i))&&!isalpha(*(a+i))&&!isspace(*(a+i))){
            count++;
        }
    }
    printf("Số kí tự đặc biệt trong chuỗi là : %d\n",count);
}
