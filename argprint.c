
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ch[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+-";
char pch[64], tmp_chtstr[2], retVal[5000];

char * chToStr(char a){
    char* y;
    y = tmp_chtstr;
    y[0] = a;
    y[1] = '\0';
    return(y);
}

int test(int argc, char *argv[] ){
    for(int i = 1; i < argc; i++){
        printf("Argumen %d : %s\n", i, argv[i]);
    }
    return(0);
}

char * strBase(int L){
    pch[0] = '\0';
    if(L > strlen(ch)){
        exit(234);
    }
    for(int i = 0; i < L; i++){
        strcat(pch, chToStr(ch[i]));
    }
    return(pch);
}

char * baseConvert(char * angka, char * fr, char * to){
    long int h;
    char * avail = strBase(strtoi(fr));
    int to = (int) strtol(to);
    // cek karakter dalam lingkup fr
    for(int i = 0; i < strlen(angka); i++){
        if(strchr(avail, angka[i]) != NULL ){
            exit(2);
        }
    }
    
    
    return(0);
}


int main(int argc, char *argv[]){
    printf("%s\n", strBase(10));
    return(0);
}
