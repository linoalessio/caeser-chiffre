#ifndef CONVERTING_H
#define CONVERTING_H

enum ConvertingType { UPPER, LOWER };
enum CodeType { ENCODE, DECODE };

void convert(char* string);
void code(enum CodeType codeType, char* string, signed char key);

#endif //CONVERTING_H
