#include <string>
#include <iostream>

// User defined data type for Student
typedef struct student
{
    std::string name;
    float Physics;
    float Biology;
    float Chemistry;
    float English;
    float Urdu;
    float Ideology;
} Student;

// User defined data type for Teacher
typedef struct teacher
{
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::string subject;
} Teacher;

// User defined data type for Principal
typedef struct principal
{
    std::string name;
    std::string schoolName;
} Principal;

// Function to initialize all marks for Student to zero
void initializeMarks(Student &s)
{
    s.Physics = 0;
    s.Biology = 0;
    s.Chemistry = 0;
    s.English = 0;
    s.Urdu = 0;
    s.Ideology = 0;
}

// Function to enter marks for a selected subject using switch statement
void enterMarks(Student &s, const std::string &subject)
{
    float marks;
    std::cout << "Enter marks for " << subject << ": \n ";
    std::cin >> marks;

    // Using switch statement to assign marks to the respective subject based on user input
    switch (subject[0]) // check the first letter of the subject
    {
        case 'P': // Physics
        case 'p':
            s.Physics = marks;
            break;
        case 'B': // Biology
        case 'b':
            s.Biology = marks;
            break;
        case 'C': // Chemistry
        case 'c':
            s.Chemistry = marks;
            break;
        case 'E': // English
        case 'e':
            s.English = marks;
            break;
        case 'U': // Urdu
        case 'u':
            s.Urdu = marks;
            break;
        case 'I': // Ideology
        case 'i':
            s.Ideology = marks;
            break;
        default:
            std::cout << "Invalid subject entered.\n";
            break;
    }
}