#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    c = toupper(c);
  //  switch (c) {  
        if(c== 'B' || C=='F' || c=='V'){return '1';}
        if(c== 'C' || C=='G' || c=='J'||c=='K'|| c=='Q'|| c=='S'||c=='X'|| c=='Z' ){return '2';}
        if(c== 'D' || C=='T' ){return '3';}
        if(c== 'L' ){return '4';}
        if(c== 'M' || C=='N' ){return '5';}
        if(c== 'R'){return '6';}
      //  case 'B': case 'F': case 'P': case 'V': return '1';
      //  case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
     //   case 'D': case 'T': return '3';
     //   case 'L': return '4';
     //   case 'M': case 'N': return '5';
     //   case 'R': return '6';
       // default: return '0'; // For A, E, I, O, U, H, W, Y
    else{return '0';} // For A, E, I, O, U, H, W, Y}
    }
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
