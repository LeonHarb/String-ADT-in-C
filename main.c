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

string Create(char *ary, int capacity) {
    string s;
    s.capacity = capacity;
    s.element = (char *)malloc(sizeof(char) * capacity);
    strcpy(s.element, ary);
    s.length = strlen(ary);
    return s;
}

void Destroy(string str) {
    free(str.element);
    str.element = NULL;
    str.length = 0;
    str.capacity = 0;
}

char Retrieve(int i, string s) {
    if (i < 0 || i >= s.length) {
        return '\0';  // Return null character if out of bounds
    }
    return s.element[i];
}

void Print(string str) {
    printf("%s\n", str.element);
}

string Concatenate(string str1, string str2) {
    string newStr;
    newStr.capacity = str1.length + str2.length + 1;
    newStr.element = (char *)malloc(sizeof(char) * newStr.capacity);
    strcpy(newStr.element, str1.element);
    strcat(newStr.element, str2.element);
    newStr.length = strlen(newStr.element);
    return newStr;
}

void Copy(string *s1, string s2) {
    if (s1->capacity < s2.length + 1) {
        s1->element = (char *)realloc(s1->element, s2.length + 1);
        s1->capacity = s2.length + 1;
    }
    strcpy(s1->element, s2.element);
    s1->length = s2.length;
}

int Compare(string s1, string s2) {
    return strcmp(s1.element, s2.element);
}

int Length(string s) {
    return s.length;
}

int Capacity(string s) {
    return s.capacity;
}

int main() {
    char *words[] = {"defunct", "abeyance", "irrelevant", "acquiesce", "western", "zealous", "electric", "trihedral",
                     "unimodal", "vanquish", "ambient", "abbreviate", "edifice", "genre", "ferrous", "breve", "brocade"};
    int n = sizeof(words) / sizeof(words[0]);
    string strings[n];

    for (int i = 0; i < n; i++) {
        strings[i] = Create(words[i], 20);
    }

    // Command-line interface for testing each function
    int choice;
    printf("Enter your choice:\n");
    printf("1. Retrieve character from a string\n");
    printf("2. Print a string\n");
    printf("3. Concatenate two strings\n");
    printf("0. Exit\n");
    while (1) {
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int index, stringIndex;
                printf("Enter string index (0-%d): ", n - 1);
                scanf("%d", &stringIndex);
                printf("Enter index: ");
                scanf("%d", &index);
                if (stringIndex >= 0 && stringIndex < n) {
                    printf("Character at index %d: %c\n", index, Retrieve(index, strings[stringIndex]));
                } else {
                    printf("Invalid string index.\n");
                }
                break;
            }
            case 2: {
                int stringIndex;
                printf("Enter string index (0-%d): ", n - 1);
                scanf("%d", &stringIndex);
                if (stringIndex >= 0 && stringIndex < n) {
                    printf("String contents:\n");
                    Print(strings[stringIndex]);
                } else {
                    printf("Invalid string index.\n");
                }
                break;
            }
            case 3: {
                int index1, index2;
                printf("Enter index of first string to concatenate (0-%d): ", n - 1);
                scanf("%d", &index1);
                printf("Enter index of second string to concatenate (0-%d): ", n - 1);
                scanf("%d", &index2);
                if (index1 >= 0 && index1 < n && index2 >= 0 && index2 < n) {
                    string concatenated = Concatenate(strings[index1], strings[index2]);
                    printf("Concatenated string: ");
                    Print(concatenated);
                    Destroy(concatenated);
                } else {
                    printf("Invalid string index.\n");
                }
                break;
            }
            case 0: {
                printf("Exiting...\n");
                // Free memory allocated for strings
                for (int i = 0; i < n; i++) {
                    Destroy(strings[i]);
                }
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
