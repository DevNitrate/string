# Documentation

This is the documentation for all the functions inside this string library.

**NOTE:** null termination is handled automatically across every function.

## string stringInit(const char* _str);

stringInit() returns a string that contains the value of ***_str***

Example:
```c
string str = stringInit("abc");
```
>the string stored inside ***str*** is ``abc``

## void stringPush(string self, char _c);

stringPush() appends the character ***_c*** to the string ***self***

Example:
```c
string str = stringInit("abc");
stringPush(str, 'd');
```
>the string stored inside ***str*** is now ``abcd``

## void stringAppend(string self, const char* _str);

stringAppend() appends the C string ***_str*** to the string ***self***

Example:
```c
string str = stringInit("abc");
stringAppend(str, "def");
```
>the string stored inside ***str*** is now ``abcdef``

## const char* stringGet(string self);

stringGet() returns a C string equivalent to string inside ***self***

Example:
```c
string str = stringInit("abc");
const char* cStr = stringGet(str);
printf("%s", cStr);
```
>Output: ``abc``

## char stringAt(string self, int _index);

stringAt() returns the character stored in ***self*** at index ***_index***

Example:
```c
string str = stringInit("abc");
char c = stringAt(str, 0);
```
>the variable ***c*** now contains the character ``'a'```

## void stringClear(string self);

stringClear() clears the string so only the null terminator remains.

Example:
```c
string str = stringInit("abc");
stringClear(str);
```
>The string ***str*** is now empty

## int stringCmp(string self, void* _other, int isLit);

stringCmp() compares ***self*** and ***_other***, if both are equal the function returns 1 otherwise it returns 0. If ***isLit*** is 0 ***_other*** will be interpreted as a ``string`` otherwise it is interpreted as a ``const char*``.

Example:
```c
string str1 = stringInit("abc");
string str2 = stringInit("abc");

int isEqual = stringCmp(str1, str2, 0);
```
>The variable ***isEqual*** is now equal to 1 because both strings are equal
```c
string str1 = stringInit("abc");
string str2 = stringInit("abcd");

int isEqual = stringCmp(str1, str2, 0);
```
>The variable ***isEqual*** is now equal to 0 because both strings are not equal
```c
string str1 = stringInit("abc");

int isEqual = stringCmp(str1, "abc", 1);
```
>Here the second argument is interpreted as a ``const char*`` because the ***isLit*** flag if not 0

## size_t stringSize(string self);

stringSize() returns the number of characters inside ***self*** not including the null terminator

Example:
```c
string str = stringInit("abc");
size_t size = stringSize(str);
```
>***size*** is equal to 3

## int stringIsEmpty(string self);

stringIsEmpty() returns 1 if the string doesn't contain any character (excluding the null terminator) and 0 if it isn't

Example:
```c
string str = stringInit("abc");
int isEmpty = stringIsEmpty(str);
```
>The value of ***isEmpty*** is 0 because ***str*** contains ``abc``
```c
string str = stringInit("");
int isEmpty = stringIsEmpty(str);
```
>The value of ***isEmpty*** is 1 because ***str*** doesn't contain anything

## int stringIsNum(string self);

stringIsNum() returns 1 if the string is numerical and 0 if it isn't

Example:
```c
string str = stringInit("123");
int isNum = stringIsNum(str);
```
>The value of ***isNum*** is 1 because ``123`` is a number
```c
string str = stringInit("abc");
int isNum = stringIsNum(str);
```
>The value of ***isNum*** is 0 because ``abc`` isn't a number
```c
string str = stringInit("123a");
int isNum = stringIsNum(str);
```
>The value of ***isNum*** is 0 because the strings still contains one non numerical character

## string stringFromInt(int _val);

stringFromInt() creates a string that contains the integer stored inside ***_val***

Example:
```c
string str = stringFromInt(123);
```
>***str*** now contains ``123``

## string stringCopy(string _src);

stringCopy() creates a copy of ***_src*** because the ``string`` type is a pointer

## void stringFree(string self);

stringFree() frees the allocated memory for 
***self***

# string vector functions

this section is dedicated to the string vector functions

## stringVec stringVecInit();

stringVecInit() creates the string vector and return type ``stringVec``

## void stringVecPush(stringVec self, string _el);

stringVecPush() pushes the string ***_el*** to ***self***

Example:
```c
stringVec vec = stringVecInit();
string str = stringInit("abc");
stringVecPush(vec, str);
```
>vec[0] now contains a copy of ***str***

## void stringVecPop(stringVec self);

stringVecPop() deletes the last element inside ***self***

Example:
```c
stringVec vec = stringVecInit();
string str = stringInit("abc");
stringVecPush(vec, str);
stringVecPop(vec);
```
>vec[0] does not contain anything

## string stringVecGet(stringVec self, int _index);

stringVecGet() returns the string at index ***_index*** inside ***self***

Example:
```c
stringVec vec = stringVecInit();
string str = stringInit("abc");
stringVecPush(vec, str);

string get = stringCopy(stringVecGet(vec, 0));
```
>the string ***get*** now contains a copy of vec[0] (``abc``)

## size_t stringVecSize(stringVec self);

stringVecSize() returns the number of elements inside ***self***

Example:
```c
stringVec vec = stringVecInit();
string str = stringInit("abc");
stringVecPush(vec, str);
stringVecPush(vec, str);

size_t size = stringVecSize(vec);
```
>The value in ***size*** is 2

## void stringVecFree(string self);

stringVecFree() frees the allocated memory for 
***self***