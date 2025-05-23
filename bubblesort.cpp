
#include <iostream>
#include <string>
#include <stdio.h>
void swapintegers(int *mark, int *mark2);
void swapstrings(std::string *name, std::string *name2);
void info();
int main()
{
    std::ios::sync_with_stdio(false);
    int total = 0;
    system("cls");
    int n = 0;
    int *marks = nullptr;
    std::string *names = nullptr;

    int option = 0;

    std::string search_name;

    info();

    system("cls");
    while (true)
    {
        /* system("cls"); */
        printf("1. Enter student marks\n");
        printf("2. Search For A Student\n");
        printf("3. Exit program\n");
        printf("Choose option:");
        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            system("cls");
            total = 0;
            printf("Enter the number of students:");
            std::cin >> n;
            marks = new int[n];
            names = new std::string[n];
            std::cin.ignore();

            system("cls");

            printf("Enter the names and marks of students below:\n");

            for (int i = 0; i < n; i++)
            {
                system("cls");
                printf("Enter name of student %d: ", i + 1);
                std::getline(std::cin, names[i]);
                printf("Enter final mark of student %s: ", names[i].c_str());
                std::cin >> marks[i];
                std::cin.ignore();
            }
            system("cls");
            for (int i = 0; i < (n - 1); i++)
            {
                for (int j = 0; j < (n - i - 1); j++)
                {
                    if (marks[j] > marks[j + 1])
                    {

                        swapintegers(&marks[j], &marks[j + 1]);
                        swapstrings(&names[j], &names[j + 1]);
                    }
                }
            }

            printf("Here is the arranged list of students along with their final marks\n");
            for (int i = 0; i < n; i++)
            {
                printf("______________\nName: %s\nFinal Mark: %d% \n", names[i].c_str(), marks[i]);
                total += marks[i];
                if (marks[i] >= 90)
                {
                    printf("Grade: A\n");
                }
                else if (marks[i] >= 80)
                {
                    printf("Grade: B\n");
                }
                else if (marks[i] >= 70)
                {
                    printf("Grade: C\n");
                }
                else if (marks[i] >= 60)
                {
                    printf("Grade: D\n");
                }
                else
                {
                    printf("Grade: F\n");
                }
            }

            float average = (float)total / n;

            printf("______________________\nStatistics\n\n");

            printf("Lowest mark:      %d%\n", marks[0]);
            printf("Highest mark:     %d%\n", marks[n - 1]);
            printf("Top Student:      %s\n", names[n - 1].c_str());
            printf("Lowest Student:   %s\n", names[0].c_str());
            if (n % 2 == 0)
            {
                printf("Average Students: %s , %s \n", names[(n / 2) - 1].c_str(), names[(n / 2)].c_str());
            }
            else
            {
                printf("Average Student:  %s\n", names[n / 2].c_str());
            }
            printf("Average mark:    %.2f%\n", average);
            system("pause");
            printf("\n\n\n");
            break;
        }
        case 2:
        {
            system("cls");
            if (marks == nullptr || names == nullptr)
            {
                printf("No students found. Please enter student marks first.\n");
                break;
            }

            printf("Enter the name of the student you want to search for: ");
            std::cin.ignore();
            std::getline(std::cin, search_name);
            system("cls");
            printf("Searching for %s...\n", search_name.c_str());
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (names[i] == search_name)
                {
                    printf("Student found!\n");
                    printf("Name: %s\n", names[i].c_str());
                    printf("Final Mark: %d%\n", marks[i]);
                    if (marks[i] >= 89)
                    {
                        printf("Grade: A\n\n");
                    }
                    else if (marks[i] >= 75)
                    {
                        printf("Grade: B\n\n");
                    }
                    else if (marks[i] >= 70)
                    {
                        printf("Grade: C\n\n");
                    }
                    else if (marks[i] >= 50)
                    {
                        printf("Grade: D\n\n");
                    }
                    else
                    {
                        printf("Grade: F\n\n");
                    }
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                printf("Student not found.\n");
            }
            break;
        }
        case 3:
        {
            system("cls");

            printf("Exiting program...\n");

            return 0;
            break;
        }
        default:
        {
            system("cls");
            printf("Invalid option. Please try again.\n");

            system("pause");
        }
        }
    }

    system("pause>0");
}
void swapintegers(int *mark, int *mark2)
{
    int temp = *mark;
    *mark = *mark2;
    *mark2 = temp;
}
void swapstrings(std::string *name, std::string *name2)
{
    std::string temp = *name;
    *name = *name2;
    *name2 = temp;
}
void info()
{
    printf("Welcome to the Student Marks Program\n");
    printf("This program will sort the students based on their final marks\n");
    printf("It will also display the statistics of the students\n");
    printf("This program was created by Boitumelo Aka The Deadly Dev\n");
    system("pause");
}