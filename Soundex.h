#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char checker) {
    checker = toupper(c);  
        if(checker== 'B' || checker=='F' || checker=='V'){return '1';}
        if(checker== 'C' || checker=='G' || checker=='J'||checker=='K'|| checker=='Q'|| checker=='S'||checker=='X'|| checker=='Z' ){return '2';}
        if(checker== 'D' ||checker=='T' ){return '3';}
        if(checker== 'L' ){return '4';}
        if(checker== 'M' || checker=='N' ){return '5';}
        if(checker== 'R'){return '6';}
        else{return '0';} 
    }


void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
