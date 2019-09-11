#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_art **arts;

	arts = getArts(); //parsing the file and put it in an array

	/*-------------------
	launch your test here
	--------------------*/

	struct s_dict *dict = dictInit(20);
	struct s_art *found;
	#define num_of_test_case 10
	char *names[num_of_test_case];

	for (int i = 0; i < num_of_test_case; i++)
	{
		names[i] = arts[i]->name;
		if (!dictInsert(dict, arts[i]->name, arts[i]))
			printf("Fail to insert [%s] at index %d\n", arts[i]->name, i);
	}
	printf("The following arts has been inserted: \n");
	for (int i = 0; i < num_of_test_case; i++)
		printf(" - %s\n", names[i]);
	printf("Testing search function...\n");

	for (int i = 0; i < num_of_test_case; i++)
	{
		found = dictSearch(dict, names[i]);
		if (found)
			printf("[%s : %d]\n[%s : %d]\n", found->name, found->price, arts[i]->name, arts[i]->price);
	}

	found = dictSearch(dict, names[1]);
	printf("Cool feature: \n");
	printf("address before: %p\t name before: %s\t price before: %d\n", found, found->name, found->price);
	arts[1]->name = "new name";
	arts[1]->price = 12;
	dictInsert(dict, names[1], arts[1]);
	found = dictSearch(dict, names[1]);
	printf("address after: %p\t name after: %s\t price after: %d\n", found, found->name, found->price);
	return (0);
}

//don't go further :)

#define FILENAME "art.txt"

char	*readFile(void)
{
	char *fcontent = NULL;
	int size = 0;
	FILE *fp;

	if (NULL == (fp = fopen(FILENAME, "r")))
		return (NULL);
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if (NULL == (fcontent = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	fread(fcontent, 1, size, fp);
	fclose(fp);
	return (fcontent);
}

char	**split(char *str, char *delimiter){
	char **tab;
	int count;
	int a;
	int pos;
	int len_delimiter;
	int len_substring;

	len_delimiter = strlen(delimiter);
	len_substring = 0;
	count = 0;
	//first counting the number of substring
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				len_substring = 0;
				count += 1;
			}
			i += len_delimiter - 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		count += 1;
	}
	if (NULL == (tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[(a = 0)] = NULL;
	len_substring = 0;
	pos = 0;
	//then get the substring :)
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				tab[(a++)] = strndup(str + pos, len_substring);
				len_substring = 0;
			}
			i += len_delimiter - 1;
			pos = i + 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		tab[(a++)] = strndup(str + pos, len_substring);
	}
	tab[a] = NULL;
	return (tab);
}

void	getArts_leave(void){
	dprintf(STDERR_FILENO, "failed to load the file.\n");
	exit(0);
}

struct s_art *getArts_createStruct( char *line ){
	struct s_art *piece;
	char **tab;

	if (NULL == (piece = malloc(sizeof(struct s_art))))
		return (NULL);
	if (NULL == (tab = split(line, " => ")))
		return (NULL);
	if (tab[0] != NULL)
		piece->name = strdup(tab[0]);
	else
		return (NULL);
	if (tab[1] != NULL)
		piece->price = atoi(tab[1]);
	else
		return (NULL);

	for (int i = 0; tab[i] ; i++){
		free(tab[i]);
	} free(tab);

	return (piece);
}

struct s_art **getArts(void)
{
	char *file;
	struct s_art **art;
	int art_size;
	int	art_index;

	dprintf(STDOUT_FILENO, "loading the file... ");
	if (NULL == (file = readFile()))
		getArts_leave();

	//creating the array
	art_size = 0;
	for (int i = 0; file[i]; i++){
		if (file[i] == '\n')
			art_size += 1;
	}
	if (NULL == (art = malloc(sizeof(struct s_art *) * (art_size + 1))))
		getArts_leave();
	art[(art_index = 0)] = NULL;

	//filling the array
	char **tab = split(file, "\n");
	struct s_art *tmp;
	for(int i = 0; tab[i]; i++){
		tmp = getArts_createStruct(strdup(tab[i]));
		if (tmp)
			art[(art_index++)] = tmp; 
	}
	art[(art_index)] = NULL;

	for (int i = 0; tab[i] ; i++){
		free(tab[i]);
	} free(tab);

	dprintf(STDOUT_FILENO, "finish!\n");
	return (art);
}
