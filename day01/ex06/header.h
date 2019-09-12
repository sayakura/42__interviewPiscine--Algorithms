#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_city {
	char *name;
	struct s_city *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *NthLastCity(struct s_city *city, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_city *getCities(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


struct s_item {
  char          *word;
  struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};

#endif
