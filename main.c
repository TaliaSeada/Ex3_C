#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT 1024
#define WORD 30
#define TRUE 1
#define FALSE 0

int toGematri(char* word){ 
    int lower = 96;
    int uper = 64;
    int res = 0;
    int i;
    for(i = 0; i < strlen(word); i++){
        char c = word[i];
        if(c > 96 && c < 123){
            res += (c - lower); // using ascii values
        }
        if(c > 64 && c < 91){
            res += (c - uper); // using ascii values
        }
    }
    return res;
}

char* atbash(char* word){
    char* w = (char*) malloc(WORD);
    if(w){
        int i;
        for(i = 0; i < strlen(word); i++){
            if(word[i] > 96 && word[i] < 123){
                w[i] = (char) (123 - word[i] + 96);
            }
            if(word[i] > 64 && word[i] < 91){
                w[i] = (char) (91 - word[i] + 64);
            }
        }
        return w;
    }
    else {
        return NULL;
    }
}

char* reverse(char* word){
    char* w = (char*) malloc(WORD);
    if(w){
        int i;
        for(i = 0; i < strlen(word); i++){ 
            w[i] = (char) word[strlen(word) - 1 - i];
        }
        return w;
    }
    else{
        return NULL;
    }
}

int isMin(char* word){
    char start = word[0];
    char end = word[strlen(word)-1];
    int res_s = 0;
    int res_e = 0;
    if(start < 91 && start > 64){
        res_s = 1;
    }
    else if(start < 123 && start > 96){
        res_s = 1;
    }
    if(end < 91 && end > 64){
        res_e = 1;
    }
    else if(end < 123 && end > 96){
        res_e = 1;
    }

    if(res_e == 1 && res_s == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isAnagram(char* word){
    char* res = strstr(word, "a");


    if(res){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    // printf("%d\n", toGematri("abc"));
    // printf("%d\n", toGematri("ABC"));

    // char w[WORD] = "ABC";
    // printf("%s\n", atbash(w));
    // printf("%s\n", w);
    // printf("%s\n", reverse(w));
    char w2[WORD] = "*akdoe"; //false - start
    char w3[WORD] = "kdoe"; //true
    char w4[WORD] = "kdoe&"; //false - end
    // printf("%d\n", isMin(w2));
    // printf("%d\n", isMin(w3));
    // printf("%d\n", isMin(w4));

    printf("%d\n", isAnagram(w2));


    return 0;
}