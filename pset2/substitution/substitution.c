#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Constants
#define MAX_STR_LEN 26
#define LOWER_OFFSET 97
#define LOWER_MIN 97
#define LOWER_MAX 122
#define UPPER_OFFSET 65
#define UPPER_MIN 65
#define UPPER_MAX 90

// Declare Functions
int calc_char_offset(char letter);
char encrypt_char(char letter, string key);
int is_lower(char letter);
int is_upper(char letter);
int is_alpha_char(char letter);
char normalize_char(char letter);
void print_array(char text[], int length);
int valid_key(string key);
int valid_arg_length(int length);

int main(int argc, string argv[])
{
    // [√] validate args.
    if (!valid_arg_length(argc))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // [√] normalize key
    // Easier to handle and validate once
    // normalized to all upper case letters.
    string key = argv[1];
    char normalized_key[MAX_STR_LEN];
    for (int i = 0; i < MAX_STR_LEN; i++)
    {
        normalized_key[i] = normalize_char(key[i]);
    }

    //  [√] Validate Key
    if (!valid_key(normalized_key))
    {
        printf("Key must contain %i characters.\n", MAX_STR_LEN);
        return 1;
    }

    // [√] Prompt user for phrase.
    string plain_text = get_string("plaintext: ");
    int str_len = strlen(plain_text);
    // [√] Encrypt user provided phrase.
    char encrypted_chars[str_len];
    for (int i = 0; i < str_len; i++)
    {
        encrypted_chars[i] = encrypt_char(plain_text[i], normalized_key);
    }

    // [√] Print encrypted phrase.
    printf("\n");
    printf("ciphertext: ");
    print_array(encrypted_chars, str_len);
    printf("\n");
    return 0;
}

////////////////////
// Helper functions
////////////////////

// Adjust ASCII count of provided character.
// The offset adjusts the characters value to
// be inline with a 0 index array, so we can match
// charaters to the cipher (string) key provided.
// example 65 = A, this gets offset to 0.
int calc_char_offset(char letter)
{
    if (is_upper(letter))
    {
        return letter - UPPER_OFFSET;
    }
    else if (is_lower(letter))
    {
        return letter - LOWER_OFFSET;
    }
    else
    {
        return 0;
    }
}

// Returns the encryption key value for
// the supplied letter if it is a valid
// alphabetical character.
char encrypt_char(char letter, string key)
{
    // TODO: Add handling of upper and lower chars.
    // 1. Guard clause against invalid chars return 0;
    if (!is_alpha_char(letter))
    {
        return letter;
    }

    // From this point on all are valid alpha chars.
    char encrypted_char = key[calc_char_offset(letter)];
    if (is_lower(letter))
    {
        return encrypted_char + 32;
    }
    else
    {
        return encrypted_char;
    }
}

// Return true or false if letter is a Alphabetical character.
int is_alpha_char(char letter)
{
    return is_upper(letter) || is_lower(letter) ? 1 : 0;
}
//  Determines if letter is an ASCII upper character.
int is_upper(char letter)
{
    return letter >= UPPER_MIN && letter <= UPPER_MAX ? 1 : 0;
}

//  Determines if letter is an ASCII lower character.
int is_lower(char letter)
{
    return letter >= LOWER_MIN && letter <= LOWER_MAX ? 1 : 0;
}

// Normalize alphabetical character to upper.
char normalize_char(char letter)
{
    if (is_lower(letter))
    {
        return letter - 32;
    }
    else
    {
        return letter;
    }
}

//  Just a helper function to print out
//  contents of an array on single line.
void print_array(char text[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", text[i]);
    }
}

//  Make sure only 1 argument is provided.
int valid_arg_length(int length)
{
    return length == 2  ? 1 : 0;
}

//  Validate Key
//  Works best with a normalized key.
int valid_key(string key)
{
    //  [√] 1. Check key length.
    int valid = 1;
    int key_len = strlen(key);
    if (key_len != MAX_STR_LEN)
    {
        valid = 0;
    }
    for (int i = 0; i < key_len; i++)
    {
        //  [√] 2. Check for non-alphabetic characters.
        if (!is_lower(key[i]) && !is_upper(key[i]))
        {
            valid = 0;
        }
        //  [√] 3. Check for repeated characters (case-insensitive).
        for (int j = 0; j < key_len; j++)
        {
            if (j != i)
            {
                if (key[j] == key[i])
                {
                    valid = 0;
                }
            }
        }
    }
    return valid;
}
