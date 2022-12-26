#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "parsePath.h"

/**
 * Parse an input string according to examples in test.cpp
 * 1. The caller is not responsible for freeing the char array you return.
 * 2. The returned char array must be writable (write your own test to verify your implementation). 
 * 3. Do not forget to complete the struct definition in parsePath.h.
 */

/*
 * Return a new path parser for the given string representing (hopefully)
 * a path.
 */
path_parser_t *new_path_parser(char * str)
{   
    int length = strlen(str);
    printf("1\n");
    path_parser_t* string = (path_parser_t *) malloc(sizeof(path_parser_t));
    printf("2\n");
    string->length = length;
    string->index = 0;
    
    string->og = (char *) malloc(length*sizeof(char)+1);
    printf("3\n");
    strcpy(string->og, str);
    printf("4\n");

    char *slash = "/";
    string->slash = (char *) malloc(sizeof(char)+1);
    printf("5\n");
    strcpy(string->slash, slash);
    printf("6\n");

    return string;
}

/*
 * Return the next component of the path, or NULL if no such component
 * exists.
 */
char *next_path_component(path_parser_t *path_parser)
{   
    if(path_parser == NULL){
        return NULL;
    }
    //check if at end
    if(path_parser->index >= path_parser->length){
        return NULL;
    }
    //check if beginning of path is /
    if((path_parser->index == 0) && (path_parser->og[0] == '/')){
        path_parser->index++;
        return path_parser->slash;

    }
    //skip past all '/'
    while(path_parser->og[path_parser->index] == '/'){
        path_parser->index++;
    }
    //not at a /, at end?
    if(path_parser->og[path_parser->index] == '\0'){
        return NULL;
    }
    //set ptr to beg of component
    char *beginning_of_component = &path_parser->og[path_parser->index];

    //traverse string undtil '/' or NULL
    while((path_parser->og[path_parser->index] != '/') && (path_parser->og[path_parser->index] != '\0')){
        path_parser->index++;
    }
    //terminate substring 
    path_parser->og[path_parser->index] = '\0';
    //inc index
    path_parser->index++;
    return beginning_of_component;


return NULL;





}

/*
 * Dispose of a path parser by freeing all malloc'ed memory.
 */
void free_path_parser(path_parser_t *path_parser)
{   
    free(path_parser->slash);
    free(path_parser->og);
    free(path_parser);
}
