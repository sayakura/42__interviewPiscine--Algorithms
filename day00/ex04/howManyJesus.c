#include "header.h"
#include <string.h>
#include <stdio.h>

#define MAXCHAR 256
#define PRIME 11593

void    rabin_karp(char *str, char *pattern, unsigned int *hit)
{
    int patlen = strlen(pattern);
    int strlength = strlen(str);
    int diff = strlength - patlen;
    int pathash = 0, strhash = 0, h = 1;

    for (int i = 0; i < patlen - 1; i++)
        h = (h * MAXCHAR) % PRIME;
    for (int i = 0; i < patlen; i++)
    {
        pathash = (MAXCHAR * pathash + (int)(pattern[i])) % PRIME;
        strhash = (MAXCHAR * strhash + (int)(str[i])) % PRIME;
    }
    for (int i = 0; i <= diff; i++)
    {
        if (pathash == strhash)
            if (!strncmp(pattern, str + i, patlen))
                (*hit) += 1;
        if (i < diff) {
            //Remove leading digit, add trailing digit  
            strhash = ((MAXCHAR *(strhash - ((int)(str[i]) * h)))\
                + (int)(str[i + patlen])) % PRIME;
            if (strhash < 0)
                strhash += PRIME;
        }
    }
}

int howManyJesus(char *bible, char *jesus)
{
    unsigned int hit = 0;
    rabin_karp(bible, jesus, &hit);
    return hit;
}

/*
Input: The main text and the pattern. Another prime number of find hash location

Output: location where patterns are found

Begin
   patLen := pattern Length
   strLen := string Length
   patHash := 0 and strHash := 0, h := 1
   maxChar := total number of characters in character set

   for index i of all character in pattern, do
      h := (h*maxChar) mod prime
   done

   for all character index i of pattern, do
      patHash := (maxChar*patHash + pattern[i]) mod prime
      strHash := (maxChar*strHash + text[i]) mod prime
   done

   for i := 0 to (strLen - patLen), do
      if patHash = strHash, then
         for charIndex := 0 to patLen -1, do
            if text[i+charIndex] ≠ pattern[charIndex], then
               break the loop
         done

         if charIndex = patLen, then
            print the location i as pattern found at i position.
      if i < (strLen - patLen), then
         strHash := (maxChar*(strHash – text[i]*h)+text[i+patLen]) mod prime, then
      if strHash < 0, then
         strHash := strHash + prime
   done
End

 */