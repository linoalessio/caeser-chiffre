#include <stdio.h>
#include <string.h>
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

/**
 * @param size returns the size of provided arguments.
 * @param arguments represents the entered arguments into the console.
 *
 * Method main([...]) declares the system start.
 * The system tries to read this method to launch a new project.
 * Allowed datatypes: Void (against the c naming conventions) and Integer (always returns a 0)
 */
int main(void) {

    signed char key;
    unsigned int codeType;

    const unsigned int length = 1000;
    char sentence[length + 1];

    printf("\nPlease enter a sentence: ");
    scanf("%[^\n]c", sentence);

    sentence[length + 1] = '\0';

    if (strlen(sentence) > length + 1) {
        printf("\nThe process was terminated since the sentence' length is too long!");
        return 1;
    }

    printf("\nEnter the key and should your sentence be decoded or encoded? (1. ENCODE, 2. DECODE): ");
    scanf("%d %d", &key, &codeType);

    if (key < -25 || key > 25) {
        printf("\nThe process was terminated since the key is out of range!");
        return 1;
    }

    if (codeType < 1 || codeType > 2) {
        printf("\nThe process was terminated due to the wrong decode/encode type!");
        return 1;
    }

    const enum CodeType coding = codeType == 1 ? ENCODE : DECODE;
    code(coding, sentence, &key);

    if (coding == ENCODE) {
        printf("\nEncoded sentence: %s\n", sentence);
        return 0;
    }

    printf("\nDecoded sentence: %s\n", sentence);

    return 0;
}