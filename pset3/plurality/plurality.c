#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATE 9

// Candidate
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX_CANDIDATE];

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
    if (candidate_count > MAX_CANDIDATE)
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATE);
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
    // Verifies that a user supplied candidate vote(name)
    // is valid, increments the vote returns true.
    // Invalid votes do not increment and return false.
    bool valid = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            valid = true;
        }
    }
    return valid;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Iterate over candidate votes counts tracking
    // the current largest count.
    // winner_indices trackes multiple candidates as
    // there is a potential for a tie.
    int winner_count = 0;
    int largest_count = 0;
    int winner_indices[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= largest_count)
        {
            largest_count = candidates[i].votes;
            winner_indices[i] = i;
            winner_count++;
        }
    }

    for (int i = 0; i < winner_count; i++)
    {
        printf("%s\n", candidates[winner_indices[i]].name);
    }
    printf("\n");
}
