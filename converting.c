#include <stdio.h>
#include "converting.h"

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

void convert(char* string) {

    int index = 0;
    while (string[index] != '\0') {

        if (string[index] >= 'a' && string[index] <= 'z')string[index] -= ('a' - 'A');
        else if (string[index] >= 'A' && string[index] <= 'Z') string[index] -= ('A' - 'a');

        index++;
    }

}

void code(enum CodeType codeType, char* string, signed char key) {

    convert(string);
    int index = 0;

    if (key < 0) key += 26;

    while (string[index] != '\0') {

        if (string[index] >= 'A' && string[index] <= 'Z') {

            if (codeType == ENCODE) string[index] += key;
            else string[index] -= key;

            if (string[index] > 'Z') string[index] -= 26;
            else if (string[index] < 'A') string[index] += 26;

        } else if (string[index] >= 'a' && string[index] <= 'z') {

            if (codeType == ENCODE) string[index] += key;
            else string[index] -= key;

            if (string[index] > 'z') string[index] -= 26;
            else if (string[index] < 'a') string[index] += 26;

        }

        index++;

    }


}