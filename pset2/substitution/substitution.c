#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Constants
#define MAX_LENGTH 10

// Declare functions for use in main.
string encrypt_text(string plain_text, string key);
int calc_letter_offset(char letter);
int valid_key(string key);
int valid_arg_length(int length);

int main(int argc, string argv[])
{
    // [√] valid args.
    //  1. Make sure only 1 argument is provided.
    //  2. if more than (1) arg provided error msg.
    //     and return (1) from main.
    if (!valid_arg_length(argc))
    {
        printf("Error: provide 1 argument with program call.\n");
        return 1;
    }
    string key = argv[1];

    if (!valid_key(key))
    {
        printf("Key must contain 26 characters.\n");
    }

    //  Prompt user for "Plaintext: "
    //  [√] 1. User will provide Plaintext for encryption.
    string plain_text = get_string("Plaintext: ");

    //  Encipher
    string encrypted_text = encrypt_text(plain_text, key);
    //  [] 1. For each character, determine what letter it maps to.
    //  [] 2. Preserve case.
    //  [] 3. Leave non-alphabetic characters as-is.

    //  Encipher
    //  [] 1. For each character, determine what letter it maps to.
    //  [] 2. Preserve case.
    //  [] 3. Leave non-alphabetic characters as-is.

    // code here
    printf("first: %i\n", argc);
    printf("second: %s\n", argv[1]);
}

// Helper functions
string encrypt_text(string plain_text, string key)
{
   printf("\n");
   // Example: hello, world => jrssb, ybwsp
   // 1. iterate over plain_text.
   // 2. use key to convert plaint_text letters.
   for (int i = 0, length = strlen(plain_text); i < length; i++)
   {
       // 1. find difference(n) between letter and key.
       // h (104)
       int letter_offset = calc_letter_offset(plain_text[i]);
       printf("Character offset: %i\n", letter_offset);
   }
   return plain_text;
}

int calc_letter_offset(char letter)
{
    int match;
    int lower_offset = 65;
    int upper_offset = 97;

    if (letter >= 65 && letter <= 90)
    {
       match = letter - lower_offset;
    }
    else if (letter >= 97 && letter <= 122)
    {
        match = letter - upper_offset;
    }
    else
    {
        match = 0;
    }

    return match;
}

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

int valid_arg_length(int length)
{
    return length == 2  ? 1 : 0;
}
