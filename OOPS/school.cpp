#include "header file.h"

int main()
{
    Teacher teacher;
    Principal principal;
    Student student;

    // Get Teacher details
    std::cout << "Enter Teacher's name: ";
    std::getline(std::cin, teacher.name);
    std::cout << "Enter Teacher's email: ";
    std::getline(std::cin, teacher.email);
    std::cout << "Enter Teacher's phone number: ";
    std::getline(std::cin, teacher.phoneNumber);
    std::cout << "Enter Teacher's subject: ";
    std::getline(std::cin, teacher.subject);

    // Get Principal details
    std::cout << "\nEnter Principal's name: ";
    std::getline(std::cin, principal.name);
    std::cout << "Enter school name: ";
    std::getline(std::cin, principal.schoolName);

    // Get Student details
    std::cout << "\nEnter the name of the student: ";
    std::getline(std::cin, student.name);

    // Initialize all marks to zero
    initializeMarks(student);

    // Ask who is entering marks
    char role;
    std::cout << "Enter 'T' if Teacher is entering marks: \n";
    std::cout << "Enter 'P' if prsincipal is entering marks: ";
    std::cin >> role;
    std::cin.ignore(); // Ignore the newline character left by std::cin

    // Marks entry for Teacher or Principal
    if (role == 't' || role == 'T'){
        // Teacher can only enter marks for their subject
        std::cout << "\nTeacher " << teacher.name << " is entering marks for " << teacher.subject << "...\n";
        enterMarks(student, teacher.subject);

        // Ask if the teacher wants to update the marks
        char updateChoice;
        do{
            std::cout << "Do you want to update marks for " << teacher.subject << "? (y/n): ";
            std::cin >> updateChoice;
            std::cin.ignore(); // Ignore the newline character left by std::cin

            if (updateChoice != 'y' && updateChoice != 'Y' && updateChoice != 'n' && updateChoice != 'N'){
                std::cout << "Invalid input. Please enter 'y' for Yes or 'n' for No.\n";
            }
        } while (updateChoice != 'y' && updateChoice != 'Y' && updateChoice != 'n' && updateChoice != 'N');

        if (updateChoice == 'y' || updateChoice == 'Y'){
            enterMarks(student, teacher.subject);
        }
    }
    else if (role == 'p' || role == 'P'){
        // Principal can enter or edit marks for any subject
        std::string subject;
        char updateChoice;

        std::cout << "\nPrincipal " << principal.name << " is entering marks...\n";
        do{
            std::cout << "Which subject's marks do you want to enter? (Choose from: Physics, Biology, Chemistry, English, Urdu, Ideology): \n";
            std::getline(std::cin, subject);

            // Call the function to enter marks for the selected subject
            enterMarks(student, subject);

            // Ask the Principal if they want to update the marks for the same subject
            std::cout << "Do you want to update marks for " << subject << "? (y/n): ";
            std::cin >> updateChoice;
            std::cin.ignore(); // Ignore the newline character left by std::cin
        } while (updateChoice == 'y' || updateChoice == 'Y');
    }

    // Display the student's information
    std::cout << "\nStudent Name: " << student.name << "\n";
    std::cout << "Marks:\n";
    std::cout << "Physics: " << student.Physics << "\n";
    std::cout << "Biology: " << student.Biology << "\n";
    std::cout << "Chemistry: " << student.Chemistry << "\n";
    std::cout << "English: " << student.English << "\n";
    std::cout << "Urdu: " << student.Urdu << "\n";
    std::cout << "Ideology: " << student.Ideology << "\n";

    return 0;
}