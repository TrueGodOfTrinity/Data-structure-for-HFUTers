//
// Created by leslie on 2025/4/2.
//
#include "seqstring.h"
#include <stdio.h>
#include <stdlib.h>

//在S的第i个字符开始的位置插入字符串T（顺序字符串）
void strinsert(seqstring *S,int i,seqstring T){
    if(i < 1||i > S->length + 1||S->length + T.length > MAXSIZE - 1){
        printf("cannot insert\n");
    }else{
        int k;
        for(k = S->length - 1;k >= i - 1;i--){
            S->str[T.length + k] = S->str[k];
        }      //从第i个元素往后移动
        for(k = 0;k < T.length;k++){
            S->str[k + i - 1] = T.str[k];
        }      //赋值
        S->length = S->length + T.length;
        S->str[S->length] = '\0';
    }
}


//将字符串S中第i个字符起将长度为len的子串删除
void strdelete(seqstring *S,int i,int len){
    if(i < 1||i > S->length||i + len - 1 > S->length){
        printf("cannot delete");
    }else{
        int k;
        for(k = i + len - 1;k < S->length;k++){
            S->str[k - len] = S->str[k];
        }
        S->length = S->length - len;
        S->str[S->length] = '\0';
    }
}


//链接字符串
seqstring *strconcat(seqstring S1,seqstring S2) {
    int i;
    seqstring *r;
    if (S1.length + S2.length > MAXSIZE - 1) {
        printf("cannot concat");
        exit(1);
    } else {
        r = (seqstring *) malloc(sizeof(seqstring));
        for (i = 0; i < S1.length; i++) {
            r->str[i] = S1.str[i];
        }
        for (i = 0; i < S2.length; i++) {
            r->str[S1.length + i] = S2.str[i];
        }
        r->length = S1.length + S2.length;
        r->str[r->length] = '\0';
        }
    return r;
}


//求该字符串的子串
seqstring *substring(seqstring S,int i,int len){
    int k;
    seqstring *r;
    if(i < 1 || i > S.length || i + len - 1>S.length){
        printf("error\n");
        exit(1);
    }else{
        r = (seqstring *)malloc(sizeof(seqstring));
        for(k = 0;k < len;k++){
            r->str[k] = S.str[i + k - 1];
        }
        r->length = len;
        r->str[r->length] = '\0';
    }
    return r;
}






