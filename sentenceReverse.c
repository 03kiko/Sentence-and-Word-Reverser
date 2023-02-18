#include <stdio.h>
#include <string.h>


void wordReverser(int count, char** words);
void setenceReverser( int count, char** words);
void bothReverser(int count, char** words);

int main(){
    char answer;
    do
    {
        printf("Please choose one of the following functionalites:\n(1)-Sentence Reverser;\n(2)-WordReverser;\n(3)-Both\nA:");
        scanf(" %c", &answer);
        if (answer != '1' && answer != '2' && answer != '3')
        {
            printf("\nInvalid Input, please select an option (1, 2 or 3)\n");
        }
        getchar(); // Clear buffer
    } while (answer != '1' && answer != '2' && answer != '3');
    
    
    char sentence[101];
    
    printf("Enter a sentence (limited to a max of 100 characters): ");
    fgets(sentence, 101, stdin); // scanf only reads untill finds the first whitspace; 101 to allow for '\0' character

    // Remove "\n" from the last word
    int index = strcspn(sentence, "\n"); // find the index of "\n"
    sentence[index] = '\0';

    // Split into words
    char* words[101];
    char* word = strtok(sentence, " ");
    int count = 0;
    while (word != NULL && count < 101)
    {
        words[count] = word;
        count++;        
        word = strtok(NULL," ");
        /* Subsequent calls must specify NULL as the first argument,
        which tells the function to continue tokenizing the string you passed in first*/
    }
    if (answer == '1')
    {
        setenceReverser(count, words);
    } else if (answer == '2')
    {
        wordReverser(count, words);
    } else { // answer == '3'
     bothReverser(count, words);
    }
    
    return 0;
}

void setenceReverser(int count, char** words){
    
    // Print the setence in reverse order
    printf("Reversed setence: ");
    for (int i = count - 1; i>=0; i--){ // count -1 to not count with the null
        printf("%s ", words[i]);
    }
    printf("\n");
}

void wordReverser(int count, char** words){
    // Reverse the order of the letters
    for (int i = 0; i < count; i++){
        int wordLen = strlen(words[i]);
        for (int j = 0; j < wordLen/2; j++)
        {
            char temporary = words[i][j];
            words[i][j] = words[i][wordLen - j - 1]; 
            words[i][wordLen - j - 1] = temporary;
            // Swaps the first and last letters, then the second and second-last letter and so on
        }
    }
    
    printf("Reversed words: ");
    for (int i = 0; i < count; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");
}

void bothReverser(int count, char** words){
    // Calls both of functions
    setenceReverser(count, words);
    wordReverser(count, words);

    // The words already have been reversed in "wordReverser" function so we just
    // need to print them in reverse order:
    
    // Reverse  sentence order
    printf("Reversed words and sentence: ");
    for (int i = count - 1; i>=0; i--){ // count -1 to not count with the null
        printf("%s ", words[i]);
    }
    printf("\n");
}