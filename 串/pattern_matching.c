//
// Created by leslie on 2025/4/12.
//模式匹配算法
#include <stdio.h>
#include "seqstring.h"
#include <stdlib.h>

//朴素模式匹配
int pattern_matching(seqstring p,seqstring t){
    int i , j ,succ;     //succ为匹配成功的标志
    i = 0;
    succ = 0;             //用i扫描t
    while(i <= t.length - p.length &&(!succ)){
        j = 0;
        succ = 1;
        while((j <= p.length - 1)&&succ){
            if(p.str[j] == t.str[i + j]){
                j++;
            }else{
                succ = 0;
            }
            ++i;
        }
    }
    if(succ){
        return (i - 1);
    }else{
        return (-1);
    }
}


//朴素模式匹配算法2
int Index(seqstring p,seqstring t){
    int i,j;
    i = 1,j = 1;
    while(j <= p.length && i <= t.length){
        if(p.str[i] == t.str[j]){
            j++,i++;
        }else{
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > p.length) {
        return i - p.length;
    }else{
        return 0;
    }
}

