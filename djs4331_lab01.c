//  Name- Darshil Jigneshkumar Shah
//  ID-1002084331
//  Language Used: C 6.3.0
//  Os used:Windows

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

long long djs4331_TotalSize(const char *d) {
    long long k = 0; 
    struct dirent *entry;
    DIR *dir = opendir(d); // used to open the file location

    if (dir == NULL) {
        fprintf(stderr, "Error opening directory %s\n", d); // Print error message if path is not found
        return -1; // Return -1 to indicate error
    }

    while ((entry = readdir(dir)) != NULL) { 
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // Ignore "." and ".." entries
            char path[1024];
            struct stat statbuf;
            snprintf(path, sizeof(path), "%s/%s", d, entry->d_name); // Construct full path of the entry
            if (stat(path, &statbuf) == 0) { // Get information 
                if (S_ISREG(statbuf.st_mode)) { 
                    k += statbuf.st_size; // Add file size to total size
                } else if (S_ISDIR(statbuf.st_mode)) { 
                    k += djs4331_TotalSize(path); // Recursively calculate total size of the subfolder
                }
            }
        }
    }

    closedir(dir); // Close the path
    return k; // Return total size
}

int main() {
    char d[1024];
    if (getcwd(d, sizeof(d)) == NULL) { // Get the current working path
        perror("Error getting current directory"); // Print error message 
        return 1; // Return 1 to indicate error
    }

    long long k = djs4331_TotalSize(d); // Calculate total size of files in current directory and its subdirectories
    if (k != -1) {
        printf("Total size of all files in %s and its sub-folders: %lld bytes\n", d, k); // Print total size
    }

    return 0;
}
