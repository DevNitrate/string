#include "str.h"

void throwErr(const char* msg) {
    printf("%s", msg);
    exit(1);
}

string stringInit(const char* _str) {
    size_t size = strlen(_str);
    char* data = (char*)malloc(size+1);
    if (data == NULL) {
        throwErr("Error allocating memory for data inside stringInit()");
    }

    memcpy(data, _str, size);

    data[size] = '\0';
    size++;

    string str = (string)malloc(sizeof(StringStruct));
    if (str == NULL) {
        throwErr("Error allocating memory for str inside stringInit()");
    }

    str->size = size;
    str->data = (char*)malloc(size);
    memcpy(str->data, data, size);

    free(data);

    return str;
}

void stringPush(string self, char _c) {
    self->size++;
    self->data = (char*)realloc(self->data, self->size);
    if (self->data == NULL) {
        throwErr("Error reallocating memory for self->data inside stringPush()");
    }

    self->data[self->size-2] = _c;
    self->data[self->size-1] = '\0';
}

void stringAppend(string self, const char* _str) {
    self->size += strlen(_str);
    self->data = (char*)realloc(self->data, self->size);
    if (self->data == NULL) {
        throwErr("Error reallocating memory for self->data inside stringAppend()");
    }

    strcat(self->data, _str);
}

const char* stringGet(string self) {
    return self->data;
}

char stringAt(string self, int _index) {
    if (_index >= self->size || _index < 0) {
        throwErr("Trying to access character out of bound inside stringAt()");
    }

    return self->data[_index];
}

void stringClear(string self) {
    self->size = 1;
    self->data = (char*)realloc(self->data, 1);
    if (self->data == NULL) {
        throwErr("Error reallocating memory for self->data inside stringClear()");
    }

    self->data[0] = '\0';
}

int stringCmp(string self, void* _other, int isLit) {
    if (isLit) {
        if (strcmp(self->data, (const char*)_other) != 0) {
            return 0;
        }
    } else {
        if (strcmp(self->data, ((string)_other)->data) != 0) {
            return 0;
        }
    }

    return 1;
}

size_t stringSize(string self) {
    return self->size-1;
}

int stringIsEmpty(string self) {
    if (self->size == 1) {
        return 1;
    }

    return 0;
}

void stringFree(string self) {
    if (self != NULL) {
        free(self->data);
        free(self);
    }
}

stringVec stringVecInit() {
    stringVec strVec = (stringVec)malloc(sizeof(StringVecStruct));
    if (strVec == NULL) {
        throwErr("Error allocating memory for strVec inside stringVecInit()");
    }
    strVec->size = 0;
    strVec->data = NULL;

    return strVec;
}

void stringVecPush(stringVec self, string _el) {
    self->size++;
    self->data = (string*)realloc(self->data, sizeof(string)*self->size);
    if (self->data == NULL) {
        throwErr("Error reallocating memory for self->data inside stringVecPush()");
    }
    self->data[self->size-1] = _el;
}

void stringVecPop(stringVec self) {
    self->size--;
    self->data = (string*)realloc(self->data, sizeof(string)*self->size);
}

string stringVecGet(stringVec self, int _index) {
    if (_index >= self->size || _index < 0) {
        throwErr("Trying to access character out of bound inside stringVecGet()");
    }

    return self->data[_index];
}

size_t stringVecSize(stringVec self) {
    return self->size;
}

void stringVecFree(stringVec self) {
    for (int i = 0; i < self->size; i++) {
        free(self->data[i]->data);
        free(self->data[i]);
    }

    free(self->data);
    free(self);
}
