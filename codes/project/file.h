#ifndef __FILE_H__
#define __FILE_H__

#define FILENAME   "db.dj"

#define WAR_FOPEN  "Either the file does not exist or you do not have a permission to read the file."

#define ERR_FOPEN  "Error in opening the file. You do not have permissions to access the file."
#define ERR_READ   "Error in reading from the file."
#define ERR_WRITE  "Error in writing to the file."
#define ERR_ALLOC  "Memory allocation failed."
#define ERR_FCLOSE "Error in flushing buffers or in outputting data."

void load(void);
void save(void);

#endif