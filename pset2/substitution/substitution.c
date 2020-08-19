#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Declare functions for use in main.
int valid_key(string key);

int main(int argc, string argv[])
{
    // [√] valid args.
    //  1. Make sure only 1 argument is provided.
    //  2. if more than (1) arg provided error msg.
    //     and return (1) from main.
    if (argc > 2 || argc < 2)
    {
        printf("Error: provide 1 argument with program call.\n");
        return 1;
    }
    string key = argv[1];

    if (!valid_key(key))
    {
        printf("Error: Key not valid\n");
    }
    //  Encipher
    //  [] 1. For each character, determine what letter it maps to.
    //  [] 2. Preserve case.
    //  [] 3. Leave non-alphabetic characters as-is.

    // code here
    printf("first: %i\n", argc);
    printf("second: %s\n", argv[1]);
}

// Helper functions
int valid_key(string key)
{
    //  valid Key
    //  [√] 1. Check key length.
    //  [] 2. Check for non-alphabetic characters.
    //  [] 3. Check for repeated characters (case-insensitive).
    int length = strlen(key);
    int valid = 1;
    printf("String Length: %i\n", length);

    return valid;
}
