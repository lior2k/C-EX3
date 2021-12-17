#include <stdio.h>
#include "functions.h"
#include <string.h>
#define TXT 1024
#define WORD 30

// int main() {
//     char inputArr[1056];
//     for (int i=0; i<1056; i++) {
//         inputArr[i] = 0;
//     }
//     fgets(inputArr,1056,stdin);
//     char wordArr[WORD];
//     for (int i=0; i<WORD; i++) {
//         wordArr[i] = 0;
//     }
//     int i = 0;
//     while (inputArr[i] != ' ') {
//         wordArr[i] = inputArr[i];
//         i++;
//     }
//     int wordLength = i;
//     char textArr[TXT];
//     for (int i=0; i<TXT; i++) {
//         textArr[i] = 0;
//     }
//     int j = 0;
//     i++;
//     while (i < TXT) {
//         if (inputArr[j] == '~') {
//             break;
//         }
//         textArr[j++] = inputArr[i++];
//     }
//     char * word_p = wordArr;
//     char * text_p = textArr;
//     func1(word_p, text_p);
//     func2(word_p, text_p, wordLength);
//     func3(word_p, text_p, wordLength);
// }

int main() {
    char wordArr[WORD];
    char textArr[TXT];
    for (int i=0; i<WORD; i++) {
        wordArr[i] = 0;
    }
    for (int i=0; i<TXT; i++) {
        textArr[i] = 0;
    }
    scanf("%s", wordArr);
    char c=0;
    int i = 0;
    while (c != 126) {
        scanf("%c", &c);
        textArr[i] = c;
        i++;
    }
    int wordLength = 0;
    for (int i=0; i<WORD; i++) {
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
