#include <stdio.h>

void num_grade_to_letter() {
    unsigned int grade;
    printf("Enter numberical grade: ");
    scanf("%d", &grade);
    char letter_grade;
    if (grade <= 59) {
        letter_grade = 'F';
    }
    else if (grade >= 60 && grade <= 69) {
        letter_grade = 'D';
    }
    else if (grade >= 70 && grade <= 79) {
        letter_grade = 'C';
    }

    else if (grade >= 80 && grade <= 89) {
        letter_grade = 'B';
    }
    else if (grade >= 90 && grade <= 100) {
        letter_grade = 'A';
    }
    else {
        letter_grade = 'Z';
    }
    printf("Letter grade: %c\n", letter_grade);
}

void english_number() {
    unsigned int i, j;
    unsigned int teen = 0;
    printf("Enter a two-digit number: ");
    scanf("%ud", &i);
    j = i % 10;
    i /= 10;
    switch (i) {
        case 2:
            printf("twenty");
            break;
        case 3:
            printf("thirty");
            break;
        case 4:
            printf("forty");
            break;
        case 5:
            printf("fifty");
            break;
        case 6:
            printf("sixty");
            break;
        case 7:
            printf("seventy");
            break;
        case 8:
            printf("eighty");
            break;
        case 9:
            printf("ninety");
            break;
        default:
            teen = 1;
    };
    if (teen) {
        switch (j) {
            case 0:
                printf("ten\n");
                break;
            case 1:
                printf("eleven\n");
                break;
            case 2:
                printf("twelve\n");
                break;
            case 3:
                printf("thirteen\n");
                break;
            case 4:
                printf("fourteen\n");
                break;
            case 5:
                printf("fifteen\n");
                break;
            case 6:
                printf("sixteen\n");
                break;
            case 7:
                printf("seventeen\n");
                break;
            case 8:
                printf("eighteen\n");
                break;
            case 9:
                printf("nineteen\n");
                break;
        };
    }
    else if (!teen) {
        switch (j) {
            case 0:
                printf("\n");
                break;
            case 1:
                printf("-one\n");
                break;
            case 2:
                printf("-two\n");
                break;
            case 3:
                printf("-three\n");
                break;
            case 4:
                printf("-four\n");
                break;
            case 5:
                printf("-five\n");
                break;
            case 6:
                printf("-six\n");
                break;
            case 7:
                printf("-seven\n");
                break;
            case 8:
                printf("-eight\n");
                break;
            case 9:
                printf("-nine\n");
                break;
        }
    }
}
