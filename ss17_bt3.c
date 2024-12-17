#include <stdio.h>
#include <string.h>
#include <ctype.h>
void input(char *a);
void reverse(char *a,int *length,char *reverseString);
void word(char *a,int *length);
void compare(char *a);
void upItem(char *a,int *length);
void addString(char *a);
int main(int argc, const char * argv[]) {
    char a[100];
    int choice;
    int length;
    char reverseString[100];
    do {
        printf("\tMENU\n");
        printf("1. Nhập vào chuỗi\n");
        printf("2. In ra chuỗi đảo ngược\n");
        printf("3. Đếm số lượng từ trong chuỗi\n");
        printf("4. Nhập vào chuỗi khác, so sánh chuỗi đó với chuỗi ban đầu\n");
        printf("5. In hoa tất cả chữ cái trong chuỗi\n");
        printf("6. Nhập vào chuỗi khác và thêm chuỗi đó vào chuỗi ban đầu\n");
        printf("7. Thoát\n");
        printf("Hãy nhập lựa chọn của bạn :");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                input(a);
                break;
            case 2:
                reverse(a,&length,reverseString);
                break;
            case 3:
                word(a,&length);
                break;
            case 4:
                compare(a);
                break;
            case 5:
                upItem(a, &length);
                break;
            case 6:
                addString(a);
                break;
                
            default:
                break;
        }
    }while (choice!=7);
}
void input(char *a){
    printf("Hãy nhập một chuỗi bất kỳ : ");
    fgets(a,100,stdin);
    a[strcspn(a, "\n")] = '\0';
}
void reverse(char *a,int *length,char *reverseString){
    
    *length = (int)strlen(a);
    for(int i =0;i<*length;i++){
        *(reverseString+i)=*(a+*length-i-1);
    }
    printf("Chuỗi đảo ngược là : %s\n",reverseString);
}
void word(char *a,int *length){
    int count = 1;
    *length = (int)strlen(a);
    for(int i = 0;i < *length;i++){
        if(*(a+i)==' '){
            count++;
        }
    }
    printf("Số từ trong chuỗi là : %d",count);
}
void compare(char *a){
    int len;
    char b [100];
    printf("Hãy nhập chuỗi để so sánh : ");
    fgets(b, 100, stdin);
    
    if(strcmp(a, b)==0){
        printf("Hai chuỗi giống nhau\n");
    }else{
        printf("Hai chuỗi khác nhau\n");
    }
}
void upItem(char *a, int *length){
    for(int i = 0;i<*length;i++){
        *(a+i)=toupper(*(a+i));
    }
}
void addString(char *a){
    char b [100];
    int len;
    printf("Hãy nhập chuỗi để thêm : ");
    fgets(b, 100, stdin);
    len=(int)strlen(b);
    b[strcspn(b, "\n")] = '\0';
    
    
    strcat(a, b);
    printf("Chuỗi sau khi thêm là %s ",a);
}
