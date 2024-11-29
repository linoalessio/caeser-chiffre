#include <stdio.h>
#include "converting.h"

#include <ctype.h>

/*
 * MIT License
 *
 * Copyright (c) lino, 28.11.2024
 * Copyright (c) contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

int isUpperAlphabetical(const char* character) {
    return (*character >= 'A' && *character <= 'Z') ? 1 : 0;
}

int isLowerAlphabetical(const char* character) {
    return (*character >= 'a' && *character <= 'z') ? 1 : 0;
}

int isAlphabetical(const char* character) {
    return isUpperAlphabetical(character) || isLowerAlphabetical(character);
}

int isLowerRange(const char* character, const char lower) {
    return (*character < lower) ? 1 : 0;
}

int isUpperRange(const char* character, const char upper) {
    return (*character > upper) ? 1 : 0;
}

void convert(char* string) {

    for (int index = 0; string[index] != '\0'; index++) {

        if (isLowerAlphabetical(&string[index])) string[index] -= ('a' - 'A');
        else if (isUpperAlphabetical(&string[index])) string[index] -= ('A' - 'a');

    }

}

void code(const enum CodeType codeType, char* string, const signed char* key) {

    convert(string);
    if (key < 0) key += 26;

    for (int index = 0; string[index] != '\0'; index++) {

        if (isUpperAlphabetical(&string[index])) {

            string[index] = codeType == ENCODE ? string[index] + *key : string[index] - *key;

            if (isUpperRange(&string[index], 'Z')) string[index] -= 26;
            if (isLowerRange(&string[index], 'A')) string[index] += 26;

        } else if (isLowerAlphabetical(&string[index])) {

            string[index] = codeType == ENCODE ? string[index] + *key : string[index] - *key;

            if (isUpperRange(&string[index], 'z')) string[index] -= 26;
            if (isLowerRange(&string[index], 'a')) string[index] += 26;

        }

    }

}