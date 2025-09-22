//
// Created by leslie on 2025/4/3.
//

#ifndef STRING_ARRAY_MATRIX_LINKSTRING_H
#define STRING_ARRAY_MATRIX_LINKSTRING_H

typedef struct node{
    char data;
    struct node *next;
}linkstrnode;
typedef linkstrnode *linkstring;

#endif //STRING_ARRAY_MATRIX_LINKSTRING_H