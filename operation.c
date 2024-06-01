#include "operation.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void listFiles(const char *path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("Failed to open path");
        return;
    } 
    for (struct dirent* entry = readdir(dir); entry != NULL; entry=readdir(dir)){
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}


void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Failed to create file");
        return;
    }
    fclose(fp); 
}


void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' has been deleted successfully.\n", filename);
    } else {
        perror("Error deleting the file");
    }
}


void writeFile(const char *filename, const char *content) {
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        perror("Failed to create file");
        return;
    }

    fwrite(content, sizeof(char), strlen(content) + 1, fp);
    fclose(fp);
}


void readFile(const char *filename) {
    // find the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return; 
    }
    // find the size of file
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // create a buffer with same file size 
    char* buffer = (char*) malloc (fileSize+1); 
    fread(buffer, sizeof(char), fileSize, fp);
    printf("File contents:\n%s", buffer);
    printf("\n");
    fclose(fp);
    free(buffer);
}

