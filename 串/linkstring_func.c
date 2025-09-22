//
// Created by leslie on 2025/4/3.
//
#include "link_string.h"
#include <stdlib.h>
#include <stdio.h>
#include "seqstring.h"
//创建字符串
void strcreate(linkstring *S) {
    char ch;
    linkstrnode *p, *r;
    *S = NULL;
    r = NULL;
    while ((ch = getchar()) != '\n') {
        p = (linkstrnode *)malloc(sizeof(linkstrnode));
        p->data = ch;
        if(*S == NULL){      //新节点插入空表的情况
            *S = p;
        }else{
            r->next = p;
            r = p;
        }
    }
    if(r != NULL){
        r->next = NULL; //处理尾部指针域
    }
}


//字符串的插入操作
void strinsert(linkstring *S,linkstring T,int i){
    int K;
    linkstring p,q;
    p = *S;
    K = 1;
    while(p && K < i - 1){
        p = p->next;
        K++;
    }
    if(!p){
        printf("error\n");
    }else{
        q = T;
        while(q && q->next){
            q = q->next;
        }
        q->next = p->next;
        p->next = T;
    }
}

//字符串的删除操作
void strdelete(linkstring *S,int i,int len) {
    linkstring p, q, r;
    p = *S,q = NULL,r = NULL;
    int k = 1;
    while(p && k < i){
        q = p;
        p = p->next;
        k++;
    }
    if(!p){
        printf("error");
    }else {
        while (p && (k - i) < len) {
            p = p->next;
            k++;
        }
        if (!p) {
            printf("error");
        } else {
            if (!q) {     //删除的字串位于开头
                r = *S;
                *S = p->next;
            } else {      //删除的字符串位于中间或结尾
                r = q->next;
                q->next = p->next;
            }
            p->next = NULL;
            while (r != NULL) {
                p = r;
                r = r->next;
                free(p);
            }
        }
    }
}


//字符串的连接
//将S2接到S1后面
void strconcat(linkstring *S1,linkstring S2) {
    if (!(*S1)) {
        *S1 = S2;
        return;
    } else {
        if (S2) {
            linkstring p;
            p = *S1;
            while (p->next) {
                p = p->next;
            }
            p->next = S2;
        }
    }
}


//求字串算法
linkstring substring(linkstring S,int i,int len) {
    int k;
    linkstring p, q, r, t;
    p = S;
    k = 1;
    while (p && k < i) {
        p = p->next;
        k++;
    }
    if (!p) {
        printf("error1\n");
        return NULL;
    } else {
        r = malloc(sizeof(linkstrnode));
        r->data = p->data;
        r->next = NULL;
        k = 1;
        q = r;
        while(p->next && k < len){
            p = p->next;
            k++;
            t = malloc(sizeof (linkstrnode));
            t->data = p->data;
            q->next = t;
            q = t;
        }         //q始终指向字串的最后一个位置
        if(k < len){
            printf("error2\n");
            return NULL;
        }else{
            q->next = NULL;
            return r;
        }
    }
}
