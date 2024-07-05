#include "php.h"
#include <stdlib.h>
#include <ctype.h>

PHP_FUNCTION(soundex)
{
	char	*str;
	size_t	i, _small, str_len, code, last;
	char	soundex[4 + 1];

	static const char soundex_table[26] =
	{0,'1','2','3',	0,'1','2', 0, 0, 
        '2', '2','4','5','5',0,'1','2','6',
        '2','3',0,'1',0,'2',0,'2'};						

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(str, str_len)
	ZEND_PARSE_PARAMETERS_END();


last = -1;
	for (i = 0, _small = 0; i < str_len && _small < 4; i++) {
		
		code = toupper((int)(unsigned char)str[i]);
		if (code >= 'A' && code <= 'Z') {
			if (_small == 0) {
				
				soundex[_small++] = (char)code;
				last = soundex_table[code - 'A'];
			}
			else {
				
				code = soundex_table[code - 'A'];
				if (code != last) {
					if (code != 0) {
						soundex[_small++] = (char)code;
					}
					last = code;
				}
			}
		}
	}
	
	while (_small < 4) {
		soundex[_small++] = '0';
	}
	soundex[_small] = '\0';

	RETURN_STRINGL(soundex, _small);
}
