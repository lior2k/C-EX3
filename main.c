#include <stdio.h>
#include "functions.h"
#include <string.h>
#define TXT 1024
#define WORD 30
#define TILDA 126

int main() {
    char wordArr[WORD];
    char textArr[TXT];
    for (int i = 0; i < WORD; i++) {
        wordArr[i] = 0;
    }
    for (int i = 0; i < TXT; i++) {
        textArr[i] = 0;
    }
    scanf("%s", wordArr);
    char c = 0;
    int i = 0;
    while (c != TILDA) {
        scanf("%c", &c);
        textArr[i] = c;
        i++;
    }
    int wordLength = 0;
    for (int i = 0; i < WORD; i++) {
        if (wordArr[i] == 0) {
            wordLength = i;
            break;
        }
    }
    char* word_p = wordArr;
    char* text_p = textArr;
    func1(word_p, text_p);
    func2(word_p, text_p, wordLength);
    func3(word_p, text_p, wordLength);
}
