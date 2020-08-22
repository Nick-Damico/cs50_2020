#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Constants
#define LOWERCASE_OFFSET 97
#define UPPERCASE_OFFSET 65

// Declare functions for use in main.
char encrypt_char(char letter, string key);
int calc_char_offset(char letter);
int is_alpha_char(char letter);
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
        return 1;
    }

    //  Prompt user for "Plaintext: "
    //  [√] 1. User will provide Plaintext for encryption.

    string plain_text = get_string("plaintext: ");

    int str_len = strlen(plain_text);
    char encrypted_chars[str_len];

    for (int i = 0; i < str_len; i++)
    {
        char encrypted_char = encrypt_char(plain_text[i], key);
        encrypted_chars[i] = encrypted_char;
    }

    //  [] 1. For each character, determine what letter it maps to.
    //  [] 2. Preserve case.
    //  [] 3. Leave non-alphabetic characters as-is.

    //  Encipher
    //  [] 1. For each character, determine what letter it maps to.
    //  [] 2. Preserve case.
    //  [] 3. Leave non-alphabetic characters as-is.

    // Return encrypted msg.
    printf("ciphertext: ");
    for (int j = 0; j < str_len; j++)
    {
        printf("%c", encrypted_chars[j]);
    }
    printf("\n");
    return 0;
}

////////////////////
// Helper functions
////////////////////

// Encrypts letter with provided key,
// if valid character.
// Ignores non Alphabetical characters.
char encrypt_char(char letter, string key)
{
    if (is_alpha_char(letter))
    {
       return key[calc_char_offset(letter)];
    }
    else {
       return letter;
    }
}

// Return true or false if letter is a Alphabetical character.
int is_alpha_char(char letter)
{
    if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Adjust ASCII count of provided character.
// The offset adjusts the characters value to
// be inline with a 0 index array, so we can match
// charaters to the cipher (string) key provided.
// example 65 = A, this gets offset to 0.
int calc_char_offset(char letter)
{
    int match;

    if (letter >= 65 && letter <= 90)
    {
       match = letter - UPPERCASE_OFFSET;
    }
    else if (letter >= 97 && letter <= 122)
    {
        match = letter - LOWERCASE_OFFSET;
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
    int valid = 0;
    if (strlen(key) == 26)
    {
        valid = 1;
    }
    return valid;
}

int valid_arg_length(int length)
{
    return length == 2  ? 1 : 0;
}
