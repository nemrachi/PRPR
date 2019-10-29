#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_RECORDS 7
#define MAX_LENGTH 51
#define MAX_LEN_REGNUM 8
#define LEN_CHAR 2

typedef struct {
    char name[MAX_LENGTH];
    char gender[LEN_CHAR];
    int birthYear;
    char registrationNum[MAX_LEN_REGNUM];
    int offenceType;
    int fine;
    int date;
} OFFENCE; //struct for offence

int countOffences(FILE *fp) {
    int _char;
    int static countLines;
    while ((_char = getc(fp)) != EOF) {
        if (_char == '\n') {
            countLines++;
        }
    } //counting lines in file
    int countOffence = countLines/(NUM_OF_RECORDS + 1); //calculate number of offences in file
    return countOffence;
}

OFFENCE ** openFile(FILE *fp, int *numOfOffences, int *opened) {
    if ((fp = fopen("priestupky.txt", "r")) == NULL) {
        printf("Error: File cannot open\n");
    } else {
        *opened = 1;
    }

    *numOfOffences = countOffences(fp);

    fseek(fp, 0, 0); //return at the start of file

    OFFENCE *person; //array for records of one person
    OFFENCE **allOffences; //array for all records of people

    if (allOffences == NULL){
        allOffences = malloc((*numOfOffences) * sizeof(OFFENCE));
    } else {
        free(allOffences);
        allOffences = malloc((*numOfOffences) * sizeof(OFFENCE));
    } //if array was created, free array and malloc memory for new one

    person = malloc(sizeof(OFFENCE));

    char line[MAX_LENGTH];
    int countLines = 0;
    int index = 0;
    char *token;

    while (fgets(line,MAX_LENGTH,fp)) { //reading lines from file
        if (countLines < NUM_OF_RECORDS) {
            if (countLines == 0) {
                token = strtok(line,"\n");
                strcpy(person->name,token);
            } else if (countLines == 1) {
                token = strtok(line,"\n");
                strcpy(person->gender,token);
            } else if (countLines == 2) {
                token = strtok(line,"\n");
                person->birthYear = atoi(token);
            } else if (countLines == 3) {
                token = strtok(line,"\n");
                strcpy(person->registrationNum,token);
            } else if (countLines == 4) {
                token = strtok(line,"\n");
                person->offenceType = atoi(token);
            } else if (countLines == 5) {
                token = strtok(line,"\n");
                person->fine = atoi(token);
            } else if (countLines == 6) {
                token = strtok(line,"\n");
                person->date = atoi(token);
            }
            countLines++;
        } else {
            allOffences[index] = person; //saves array person to array allOffences
            person = calloc(1, sizeof(OFFENCE));
            countLines = 0;
            index++;
        }
    }

    if (allOffences == NULL) {
        printf("Error: Array is empty");
        return NULL;
    }

    return allOffences;
}

void printOffences(OFFENCE **allOffences, int numOfOffences) {
    if (allOffences != NULL) {
        int index = 0;
        while(index != numOfOffences) {
            printf("meno priezvisko: %s\n", allOffences[index]->name);
            printf("pohlavie: %s\n", allOffences[index]->gender);
            printf("rok narodenia: %d\n", allOffences[index]->birthYear);
            printf("SPZ: %s\n", allOffences[index]->registrationNum);
            printf("typ priestupku: %d\n", allOffences[index]->offenceType);
            printf("vyska pokuty: %d\n", allOffences[index]->fine);
            printf("datum priestupku: %d\n\n", allOffences[index]->date);
            index++;
        }
    }
}

void removeDrivingLicense(int numOfOffences, OFFENCE **allOffences, int opened) {
    if (opened) {
        int index = 0;
        int removalDate;

        printf("Enter date in format YYYYMMDD:\n");
        scanf("%d", &removalDate);

        while (index != numOfOffences) {
            if ((allOffences[index]->date/10000) == removalDate/10000) { //compare years from register with given year
                if ((allOffences[index]->offenceType) == 0) {
                    //if  number is 0, print person with removed driving license
                    printf("meno priezvisko: %s\n", allOffences[index]->name);
                    printf("SPZ: %s\n", allOffences[index]->registrationNum);
                    printf("datum priestupku: %d\n\n", allOffences[index]->date);
                }
            }
            index++;
        }
    }
}

void reward(int numOfOffences, OFFENCE **allOffences, int opened) {
    if (opened) {
        int index = 0;
        int rewardDate;
        float bonus = 0;
        float smallBonus = 0.052;
        float bigBonus = 0.038;

        printf("Enter date in format YYYYMMDD:\n");
        scanf("%d", &rewardDate);

        while (index != numOfOffences) {
            if ((allOffences[index]->date/100) == rewardDate/100) { //compare month and year
                if ((allOffences[index]->offenceType) == 1) { //calculate reward for minor offence
                    bonus += (allOffences[index]->fine)*smallBonus;
                } else { //calculate reward for removal driving license
                    bonus += (allOffences[index]->fine)*bigBonus;
                }
            }
            index++;
        }
        printf("%.2f\n",bonus);
    }
}

int findPalindrome(char registrationNum[MAX_LEN_REGNUM]) {
    int length = 6;
    for (int index = 0; index < 3; index++) {
        if (registrationNum[index] != registrationNum[length]) {
                return 0; //if is not palindrome, return 0
        }
        length--;
    }
    return 1; //if is palindrome, return 1
}

void printPalindrome(int numOfOffences, OFFENCE **allOffences, int opened) {
    if (opened) {
        int index = 0;
        int isPalindrome;

        while (index != numOfOffences) {
            isPalindrome = findPalindrome(allOffences[index]->registrationNum);
            if (isPalindrome) { 
                printf("%s %s\n", allOffences[index]->name, allOffences[index]->registrationNum);
            }
            index++;
        }
    }
}

OFFENCE *fNewPerson() { //funkcia nacitava noveho zadaneho cloveka
    OFFENCE *newPerson = malloc(sizeof(OFFENCE));

    char line[MAX_LENGTH];

    printf("Enter name:\n");
    fgets(line, MAX_LENGTH, stdin);
    fgets(line, MAX_LENGTH, stdin);
    strtok(line, "\n");
    strcpy(newPerson->name, line);

    printf("Enter gender in format M(man) or Z(woman):\n");
    fgets(line, MAX_LENGTH, stdin);
    strtok(line, "\n");
    strcpy(newPerson->gender, line);

    printf("Enter year of birth:\n");
    fgets(line, MAX_LENGTH, stdin);
    newPerson->birthYear = atoi(line);

    printf("Enter registration number in format e.g. AA123BB:\n");
    fgets(line, MAX_LENGTH, stdin);
    strtok(line, "\n");
    strcpy(newPerson->registrationNum, line);

    printf("Enter type of offence:\n");
    printf("0 - removal of driving license\n");
    printf("1 - a fine\n");
    fgets(line, MAX_LENGTH, stdin);
    newPerson->offenceType = atoi(line);


    printf("Enter value of a fine:\n");
    fgets(line, MAX_LENGTH, stdin);
    newPerson->fine = atoi(line);

    printf("Enter date of offence in format YYYYMMDD:\n");
    fgets(line, MAX_LENGTH, stdin);
    newPerson->date = atoi(line);

    return newPerson;
}


OFFENCE **addPerson(int *numOfOffences, OFFENCE **allOffences, int opened) {
    OFFENCE *newPerson;

    int numPeople = *numOfOffences;

    if (opened) { //if array was created, add new person in alphabetical order
        allOffences = realloc(allOffences, (numPeople+1)*sizeof(OFFENCE)); //create spot for new person
        allOffences[numPeople] = fNewPerson(); //add new person at the end of array of all offences

        int index = numPeople;

        while (index >= 0 && strcmp(allOffences[index]->name,allOffences[index-1]->name) < 0) {
            newPerson = allOffences[index-1];
            allOffences[index-1]=allOffences[index];
            allOffences[index]=newPerson;
            index--;
        }

        return allOffences;


    } else {
        newPerson = fNewPerson();
        allOffences[numPeople] = newPerson;
        return allOffences;
    }
}

void closeFile(FILE *fp, int opened) {
    if (opened) {
        if (fclose(fp) == 0) {
            printf("Error: File cannot close\n");
        }
    }
}

int main()
{
    FILE *fp; //pointer to file
    char command;
    OFFENCE **allOffences; //array for all offences
    int numOfOffences = 0;
    int opened = 0; //for checking, if file was opened

    while((command = getchar())!='k') { //if k is typed, loop will end

        switch (command) {
            case 'o':
                allOffences = openFile(fp, &numOfOffences, &opened);
                //open file and make array of all offences from file
                break;

            case 'v':
                printOffences(allOffences, numOfOffences);
                //print array
                break;

            case 'x':
                removeDrivingLicense(numOfOffences, allOffences, opened);
                //removal of a driving license in certain year
                break;

            case 'r':
                reward(numOfOffences, allOffences, opened);
                //reward for policeman in certain month in certain year
                break;

            case 'p':
                printPalindrome(numOfOffences, allOffences, opened);
                //print people with registration number, if registration number is palindrome
                break;

            case 'a':
                allOffences = addPerson(&numOfOffences, allOffences, opened);
                //add new offence to array
                numOfOffences++;
                break;

            default:
                if (command != '\n') {
                    printf("Help:\n");
                    printf("\to\topens a file and make an array of all offences from a file\n");
                    printf("\tv\tprints all offences\n");
                    printf("\tx\tremoves a driving license in a certain year\n");
                    printf("\tr\tprints a reward for a policeman\n");
                    printf("\tp\tprints people with a registration number that is a palindrome\n");
                    printf("\ta\tadds new offence to an array\n");
                }
        }

    }

    closeFile(fp, opened);
    free(allOffences);

    return 0;
}