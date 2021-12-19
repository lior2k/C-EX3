#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#define SPACE 32
#define TILDA 126

//for any letter {a,b,....,z} return ascii value -96 -> a=1, b=2, ... , z=26.
//for any capital letter same as above but -64, A=1, B=2, ... , Z=26.
//for any other character return 0.
int charToInt(char * c) {
    if (*c >= 97 && *c <= 122) {
            return (*c - 96);
        } else if (*c >= 65 && *c <= 90) {
            return (*c - 64);
        }
    return 0;
}

int reversed_value(int c) {
    return (27-c);
}

void sort(char arr[WORD]) {
  int i, j;
  char temp;
  int stringLength = strlen(arr);
  for (i = 0; i < stringLength - 1; i++) {
    for (j = i + 1; j < stringLength; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void func3(char* wordArr, char* textArr, int wordLength) {
    printf("Anagram Sequences: ");
    int isFirstTime = 1;
    char* word_p = wordArr;
    char* text_p = textArr;
    char sortedword[WORD] = {};
    int i=0; 
    while (*word_p != 0 && word_p < wordArr+WORD) {
        sortedword[i] = *word_p;
        i++;
        word_p++;
    }
    sortedword[i] = TILDA;
    sort(sortedword);
    while (text_p < textArr+1024-wordLength) {
        int counter = wordLength-1;
        int spacecounter = 0;
        int j = 1;
        char temp[WORD] = {*text_p};
        char* sequence_p = text_p+1;
        while (counter > 0) {
            if (*sequence_p == SPACE) {
                spacecounter++;
                sequence_p++;
            } else {
                 temp[j] = *sequence_p;
                j++;
                sequence_p++;
                counter--;
            } 
        }  
        i = j;
        for (; i < WORD; i++) {
            temp[i] = TILDA;
        }
        sort(temp);
        int isSequence = 1;
        for (int k = 0; k < wordLength; k++) {
            if (temp[k] != sortedword[k]) {
                isSequence = 0;
                break;
            }
        }
        char* print_p = text_p;
        if (isSequence == 1) {
            if(isFirstTime == 0) {
                printf("~");
            }
            isFirstTime = 0;
            while (print_p < text_p+wordLength+spacecounter) {
                printf("%c", *print_p);
                print_p++;
            }
        }
        text_p++;
    }
}

void func2(char* wordArr, char* textArr, int wordLength) {
    char* wordArr_p = wordArr;
    char* textArr_p = textArr;
    int isFirstTime = 1;
    printf("Atbash Sequences: ");
    int first_letter = reversed_value(charToInt(wordArr));
    int last_letter = reversed_value(charToInt(wordArr+wordLength-1));
    while (textArr_p < textArr+TXT) {
        int temp_char = charToInt(textArr_p);
        if (temp_char == first_letter) {
            char* textArr_p2 = textArr_p+1;
            int counter = 1;
            int space_counter = 0;
            while (textArr_p2 < textArr+TXT) {
                int temp_int = charToInt(textArr_p2);
                if (temp_int == 0) {
                    space_counter++;
                    textArr_p2++;
                    continue;
                }
                if (temp_int != reversed_value(charToInt(wordArr+counter))) {
                    break;
                } else {
                    textArr_p2++;
                    counter++;
                }
                if (counter == wordLength) {
                    if (!isFirstTime) {
                        printf("~");
                    }
                    isFirstTime = 0;
                    char* temp = textArr_p;
                    while (temp < textArr_p2) {
                        printf("%c", *temp);
                        temp++;
                    }
                    break;     
                }
            }
         } else if (temp_char == last_letter) {
            char* textArr_p2 = textArr_p+1;
            int counter = wordLength-2;
            int space_counter = 0;
            while (textArr_p2 < textArr+TXT) {
                int temp_int = charToInt(textArr_p2);
                if (temp_int == 0) {
                    space_counter++;
                    textArr_p2++;
                    continue;
                }
                if (temp_int != reversed_value(charToInt(wordArr_p+counter))) {
                    break;
                } else {
                    textArr_p2++;
                    counter--;
                }
                if (counter == -1) {
                    if (!isFirstTime) {
                        printf("~");
                    }
                    isFirstTime = 0;
                    char* temp = textArr_p;
                    while (temp < textArr_p2) {
                        printf("%c", *temp);
                        temp++;
                    }
                    break;
                }
            }
        }
        textArr_p++;   
    }
    printf("\n");
}

void func1(char *wordArr, char *textArr) {
    char* wordArr_p = wordArr;
    char* textArr_p = textArr;
    int isFirstTime = 1;
    printf("Gematria Sequences: ");
    int sum = 0;
    for (int i = 0; i < WORD; i++) {
        sum = sum + charToInt(wordArr_p++);
    }
    wordArr_p = wordArr;
    while(textArr_p < textArr+TXT) {
        if (charToInt(textArr_p) == sum) {
            if (isFirstTime == 0) {
                printf("~");
            }
            isFirstTime = 0;
            printf("%c", *textArr_p);
        }
        if (charToInt(textArr_p) < sum && charToInt(textArr_p) != 0) {
            int tempsum = charToInt(textArr_p);
            char* textArr_p2 = textArr_p+1;
            while (textArr_p2 < textArr+TXT) {
                tempsum = tempsum + charToInt(textArr_p2);
                if (tempsum > sum) {
                    break;
                } else if (tempsum == sum) {
                    if (isFirstTime == 0) {
                        printf("~");
                    }
                    isFirstTime = 0;
                    char* temp = textArr_p;
                    while (temp <= textArr_p2) {
                        printf("%c", *temp);
                        temp++;
                    }
                    break;
                }
                textArr_p2++;
            }
        }
        textArr_p++;
    }
    printf("\n");
}