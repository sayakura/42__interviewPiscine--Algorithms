#include "header.h"
#include <string.h>

unsigned int cnt(struct s_art **art)
{
    unsigned int len = 0;
    while (art[len])
        len++;
    return len;
}

void    swap(struct s_art **a, struct s_art **b) 
{
    struct s_art *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int     partition (struct s_art **arts, int low, int high) 
{ 
    char    *pivot = arts[high]->name;
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (strcmp(arts[j]->name, pivot) < 0)  
        { 
            i++; 
            swap(&arts[i], &arts[j]); 
        } 
    } 
    swap(&arts[i + 1], &arts[high]); 
    return (i + 1); 
} 
  
void    quickSort(struct s_art **arts, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arts, low, high); 
        quickSort(arts, low, pi - 1); 
        quickSort(arts, pi + 1, high); 
    } 
} 

void        sortArts(struct s_art **arts)
{
    int len = cnt(arts);
    quickSort(arts, 0, len - 1);
}