#ifndef CONVERTING_H
#define CONVERTING_H

enum ConvertingType { UPPER, LOWER };
enum CodeType { ENCODE, DECODE };

int isUpperAlphabetical(const char* character);
int isLowerAlphabetical(const char* character);
int isAlphabetical(const char* character);

int isLowerRange(const char* character, char lower);
int isUpperRange(const char* character, char upper);

void convert(char* string);
void code(enum CodeType codeType, char* string, const signed char* key);

#endif //CONVERTING_H
