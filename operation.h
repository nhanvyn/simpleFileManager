#ifndef OPERATION_H
#define OPERATION_H

// Function declaration
void listFiles(const char *path) ;
void createFile(const char *filename);
void deleteFile(const char *filename);
void writeFile(const char *filename, const char *content);
void readFile(const char *filename);
#endif