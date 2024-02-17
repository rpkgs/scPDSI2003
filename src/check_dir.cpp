// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <sys/stat.h>

// #include <iostream>
// using namespace std;

// C++ program to create a directory in Linux
// #include <bits/stdc++.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <cstdlib>
// #include <filesystem>
// #include <iostream>

// #include <iostream>
// using namespace std;

/**
 * @ref
 * 1. https://www.geeksforgeeks.org/how-to-check-a-file-or-directory-exists-in-cpp/
 * 2. https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
 *
 * @return status
 * `-1`: if the directory does not exist
 * `1` : if the directory exists
 */
int dir_exists(const char *path) {
    // Structure which would store the metadata
    struct stat sb;

    // Calls the function with path as argument
    // If the file/directory exists at the path returns 0
    // If block executes if path exists
    if (stat(path, &sb) == 0) {
        printf("path exist!");
        return 1;
    } else {
        printf("path not exist!");
        return -1;
    }
}

#include <cstdlib> // Include the necessary header file for the `exit` function

void check_dir(char *path) {
  if (strlen(path) > 1) {
    if (path[strlen(path) - 1] != '/')
      strcat(path, "/");
    if (dir_exists(path) == -1) {
      // if (verbose)
      printf("Directory does not exist: %s\n", path);
      exit(1); // Use `std::exit` instead of `exit`
    }
  } else
    strcpy(path, "./");
}

int main(int argc, char **argv) {
    // Creating a directory
    char dirName[] = "a/b";

    if (mkdir(dirName) == 0) {
        printf("Directory created successfully\n");
    } else {
        printf("Failed to create directory\n");
    }
    // if (mkdir("geeksforgeeks", 0777) == -1)
    //     cerr << "Error :  " << strerror(errno) << endl;

    const char *path = "./TEST/";
    dir_exists(path);
    // printf("%d\n", dirExists(path));
    return 0;
}
