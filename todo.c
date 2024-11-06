#include <stdio.h>
#include <stdlib.h>
#define MAX_FILENAME 256
#define MAX_CONTENT 1024

void newfile(void);
void readfile(void);
void appendfile(void);
void clear_input_buffer(void);

int main()
{
    int choosing;
    
    while (1) {
        puts("\n=== TO DO LIST MANAGER ===\n");
        printf("1) Create a new file\n");
        printf("2) Read a file\n");
        printf("3) Append to file\n");
        printf("4) Exit\n");
        printf("\nChoice: ");
        
        if (scanf("%d", &choosing) != 1) {
            clear_input_buffer();
            puts("Invalid input! Please enter a number.");
            continue;
        }
        clear_input_buffer();
        
        switch (choosing) {
            case 1: newfile(); break;
            case 2: readfile(); break;
            case 3: appendfile(); break;
            case 4: return 0;
            default: puts("Invalid choice! Please select 1-4.");
        }
    }
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void newfile(void)
{
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];
    FILE *file;
    
    printf("Enter filename: ");
    if (fgets(filename, MAX_FILENAME, stdin) == NULL) return;
    filename[strcspn(filename, "\n")] = 0;
    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create file '%s'\n", filename);
        return;
    }
    
    printf("Enter content (press Ctrl+D or Ctrl+Z to finish):\n");
    while (fgets(content, MAX_CONTENT, stdin) != NULL) {
        fprintf(file, "%s", content);
    }
    
    fclose(file);
    printf("\nFile saved successfully!\n");
}

void readfile(void)
{
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];
    FILE *file;
    
    printf("Enter filename to read: ");
    if (fgets(filename, MAX_FILENAME, stdin) == NULL) return;
    filename[strcspn(filename, "\n")] = 0;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    
    printf("\nFile contents:\n=============\n");
    while (fgets(content, MAX_CONTENT, file) != NULL) {
        printf("%s", content);
    }
    printf("=============\n");
    
    fclose(file);
}

void appendfile(void)
{
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];
    FILE *file;
    
    printf("Enter filename to append: ");
    if (fgets(filename, MAX_FILENAME, stdin) == NULL) return;
    filename[strcspn(filename, "\n")] = 0;
    
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    
    printf("Enter content to append (press Ctrl+D or Ctrl+Z to finish):\n");
    while (fgets(content, MAX_CONTENT, stdin) != NULL) {
        fprintf(file, "%s", content);
    }
    
    fclose(file);
    printf("\nContent appended successfully!\n");
}
