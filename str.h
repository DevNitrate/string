#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    char* data;
} StringStruct;

typedef StringStruct* string;

typedef struct {
    size_t size;
    string* data;
} StringVecStruct;

typedef StringVecStruct* stringVec;

string stringInit(const char* _str);
void stringPush(string self, char _c);
void stringAppend(string self, const char* _str);
const char* stringGet(string self);
char stringAt(string self, int _index);
void stringClear(string self);
int stringCmp(string self, void* _other, int isLit);
size_t stringSize(string self);
int stringIsEmpty(string self);
void stringFree(string self);

stringVec stringVecInit();
void stringVecPush(stringVec self, string _el);
void stringVecPop(stringVec self);
string stringVecGet(stringVec self, int _index);
size_t stringVecSize(stringVec self);
void stringVecFree(stringVec self);