#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
candidate linear_search(candidate list[]);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // 1. The name argument is the name of a candidate.
    // 2. If you match the name to a candidate in the candidates array. then return true.
    // 3. If it does not match, return false.
    bool valid = false;
    for (int i = 0; i < candidate_count; i++)
    {
       if (strcmp(candidates[i].name, name))
       {
        valid = true;
       }
    }
    return valid;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // 1. Determine the candidate with the greatest amount of votes.
    // 2. Print the winners hane on a newline.
    // 3. Ties are a possibility, If this is the case output both names on separate lines.
    return;
}

candidate linear_search(candidate list[])
{
    return candidates[0];
}
// Example of completed program usage and output.
// $ ./plurality Alice Bob
// Number of voters: 3
// Vote: Alice
// Vote: Bob
// Vote: Alice
// Alice
