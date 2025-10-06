#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *element;
    int length;
    int capacity;
} string;

/* Function Prototypes */
string Create(char *ary, int capacity);
void Destroy(string str);
char Retrieve(int i, string s);
void Print(string str);
string Concatenate(string str1, string str2);
void Copy(string *s1, string s2);
int Compare(string s1, string s2);
int Length(string s);
int Capacity(string s);

#endif
