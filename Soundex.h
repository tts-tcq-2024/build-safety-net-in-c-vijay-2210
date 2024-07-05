#include        <string.h> 
#include        <ctype.h> 
char *soundex(const char *in)
{
   static  int code[] =
      {  0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2 };
      
   static  char key[5];
   register        char ch;
   register        int last;
   register        int count;
   
   strcpy(key, "Z000");
  
   while (*in != '\0'  &&  !isalpha(*in))
      ++in;
   if (*in == '\0')
      return key;

   key[0] = toupper(*in);
   last = code[key[0] - 'A'];
   ++in;
   for (count = 1;  count < 4  &&  *in != '\0';  ++in) {
      if (isalpha(*in)) {
         ch = tolower(*in);
         if (last != code[ch - 'a']) {
            last = code[ch - 'a'];
            if (last != 0)
               key[count++] = '0' + last;
         }
      }
   }
   return key;
}
#ifdef  TESTPROG

#include    <stdio.h>   
int main()
{
   char    instring[80];
   while (fgets(instring, sizeof instring, stdin) != NULL)
      printf("%s\n", soundex(instring));
   return 0;
}
#endif  TESTPROG
