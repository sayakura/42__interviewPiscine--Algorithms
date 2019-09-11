#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include "header.h"
#include <ctype.h>

struct trie_node *word_tree;
#define is_word(c) (!isspace(c))

// #define MAXCHAR 256
// #define PRIME 11593

// void    rabin_karp(char *str, char *pattern)
// {
//     int patlen = strlen(pattern);
//     int strlength = strlen(str);
//     int diff = strlength - patlen;
//     int pathash = 0, strhash = 0, h = 1;

//     for (int i = 0; i < patlen - 1; i++)
//         h = (h * MAXCHAR) % PRIME;
//     for (int i = 0; i < patlen; i++)
//     {
//         pathash = (MAXCHAR * pathash + (int)(pattern[i])) % PRIME;
//         strhash = (MAXCHAR * strhash + (int)(str[i])) % PRIME;
//     }
//     for (int i = 0; i <= diff; i++)
//     {
//         if (pathash == strhash)
//             if (!strncmp(pattern, str + i, patlen))
//             {

//             }
//         if (i < diff) {
//             //Remove leading digit, add trailing digit  
//             strhash = ((MAXCHAR *(strhash - ((int)(str[i]) * h)))\
//                 + (int)(str[i + patlen])) % PRIME;
//             if (strhash < 0)
//                 strhash += PRIME;
//         }
//     }
// }


char *itoa_base(int value, int base)
{
    static  char rep[] = "0123456789abcdef";
    static  char buf[50];
    char    *ptr;
    int     num;

    ptr = &buf[49];
    *ptr = '\0';
    num = value;
    if (value < 0 && base == 10)
        value *= -1;
    if (value == 0)
        *--ptr = rep[value % base];
    while (value != 0)
    {
        *--ptr = rep[value % base];
        value /= base;
    }
    if (num < 0 && base == 10)
        *--ptr = '-';
    return (ptr);
}

int  next_word_len(char *ptr)
{
    int     len = 0;
    while(is_word(ptr[len]))
        len++;
    return len;
}

char *compress(char *book, struct s_dict *dict)
{
    bool        malloced;
    int         index = 0;
    int         len = strlen(book);
    int         dst_index = 0;
    int         word_len = 0;
    int         offset = 0;
    char        buff[101];
    char        *buff_ptr;
    char        *temp;
    char        *dst = malloc(len + 1);

    while (isspace(book[index]))
        dst[dst_index++] = book[index++];
    while (book[index])
    {
        malloced ^= malloced;
        word_len = next_word_len(book + index);
        if (word_len < 100)
            buff_ptr = buff;
        else {
            buff_ptr = malloc(word_len);
            malloced = true;
        }
        memcpy(buff_ptr, book + index, word_len);
        buff_ptr[word_len] = '\0';
        if (search_trie(word_tree, buff_ptr)) {
            dst[dst_index++] = '@';
            dst[dst_index++] = '^';
            temp = itoa_base(dictSearch(dict, buff_ptr) + 1, 10);
            while (temp[offset])
                dst[dst_index++] = temp[offset++];
            offset ^= offset;
        } else {
            memcpy(dst + dst_index, buff_ptr, word_len);
            dst_index += word_len;
        }
        if (malloced)
            free(buff_ptr);
        index += word_len;
        while (isspace(book[index]))
            dst[dst_index++] = book[index++];
    }
    dst[dst_index] = '\0';
    return dst;
}