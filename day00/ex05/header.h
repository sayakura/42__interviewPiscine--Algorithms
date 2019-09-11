#ifndef HEADER_H
# define HEADER_H

#include <stdbool.h> 

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_item {
  char          	*key;
  int				value;
  struct s_item 	*next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};


#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
#define ALPHABET_SIZE (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
struct trie_node 
{ 
    struct trie_node *children[ALPHABET_SIZE]; 
    bool end; 
}; 

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DICTIONNARY

size_t hash(char *input); //return hash result

struct s_dict *dictInit(int capacity); //initialize the dictionnary, given as parameter the capacity of the array.
int	dictInsert(struct s_dict *dict, char *key, int value); //add one item in the dictionnary, if FAIL return 0, otherwise 1
int	dictSearch(struct s_dict *dict, char *key); //find one element in the dictionnary, if not found, return -1

// OTHER

char *compress(char *book, struct s_dict *dict);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

char *readBookFile(void);
void readWordsFile(char ***pWords, int *pLenWords);

/*--------------------------------
  &  your own other function
  --------------------------------*/

struct trie_node  *init_trie(void);
void              insert_trie(struct trie_node *root, char *key);
bool              search_trie(struct trie_node *root, char *key);
#endif
