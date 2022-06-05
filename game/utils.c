//
// Created by Jorge on 4/22/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int lengthString(char* target){
    int count = 0;
    while(*target != '\0'){
        count++;
        target++;
    }
    return count;
}

void displayString(char* target){
    while(*target != '\0'){
        printf("%c",*target);
        target++;
    }
}

void updateString(char* target,char* value){
    printf("========updating string========\n");
    int strLen = lengthString(value);

    char *aux = NULL;
    aux = realloc(target,sizeof(char) * (strLen+1));
    if(aux != NULL){
        //setStringFromPointer(target,value);
    }
    printf("===========================\n");
}