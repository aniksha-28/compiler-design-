#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch, filename[50];
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    // Get file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read file character by character
    while ((ch = fgetc(fp)) != EOF) {

        // Count characters
        characters++;

        // Count lines
        if (ch == '\n')
            lines++;

        // Count words
        if (isspace(ch)) {
            inWord = 0;
        }
        else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    // If file is not empty, count last line
    if (characters > 0)
        lines++;

    fclose(fp);

    // Display result
    printf("\nFile Analysis:\n");
    printf("Number of Characters = %d\n", characters);
    printf("Number of Words      = %d\n", words);
    printf("Number of Lines      = %d\n", lines);

    return 0;
}
