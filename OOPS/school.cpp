#include <iostream>
#include <string>
#include "school.h"
int main()
{
    Teacher teacher;
    Principal principal;
    Student student;
    initializeMarks(student); 
    admission_office admission;
    warden w;
    int choice;
    bool isEnrolled = false;
    std::string enrolledName;

    while (true)
    {
        std::cout << "\n1. Admission Office\n";
        std::cout << "2. Hostel\n";
        std::cout << "3. University\n";
        std::cout << "4. Exit Portal\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            admission.info();
            admission.display_info();
            enrolledName = admission.getStudentName();
            student.name = enrolledName;
            isEnrolled = true;
            break;
        }
        case 2:
        {
            if (!isEnrolled)
            {
                std::cout << "Student must be enrolled first.\n";
                break;
            }
            w.input();
            if (w.getStudentName() != enrolledName)
            {
                std::cout << "Student not enrolled. Room allocation denied.\n";
                w.room_num--;
                break;
            }
            w.output();
            break;
        }
        case 3:
        {
            int choice_2;
            std::cout << "\n1. Teacher's domian\n";
            std::cout << "2. Principal's domain\n";
            std::cout << "3. Student's Result\n";
            std::cout << "4. Exit to main\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice_2;

            switch (choice_2)
            {
            case 1:
            {
                if (!isEnrolled)
                {
                    std::cout << "No student enrolled.\n";
                    break;
                }
                std::cout << "Enter Teacher's name: ";
                std::cin.ignore();
                std::getline(std::cin, teacher.name);
                std::cout << "Enter Teacher's email: ";
                std::getline(std::cin, teacher.email);
                std::cout << "Enter Teacher's phone number: ";
                std::getline(std::cin, teacher.phoneNumber);
                std::cout << "Enter Teacher's subject: ";
                std::getline(std::cin, teacher.subject);

                std::cout << "\nTeacher " << teacher.name << " is entering marks for " << teacher.subject << "...\n";
                enterMarks(student, teacher.subject);

                char updateChoice;
                do
                {
                    std::cout << "Do you want to update marks for " << teacher.subject << "? (y/n): ";
                    std::cin >> updateChoice;
                    if (updateChoice == 'y' || updateChoice == 'Y')
                        enterMarks(student, teacher.subject);
                } while (updateChoice == 'y' || updateChoice == 'Y');
                break;
            }
            case 2:
            {
                if (!isEnrolled)
                {
                    std::cout << "No student enrolled.\n";
                    break;
                }
                std::cout << "Enter Principal's name: ";
                std::cin.ignore();
                std::getline(std::cin, principal.name);
                std::cout << "Enter school name: ";
                std::getline(std::cin, principal.schoolName);

                std::string subject;
                char updateChoice;
                std::cout << "\nPrincipal " << principal.name << " is entering marks...\n";
                do
                {
                    std::cout << "Enter subject: ";
                    std::getline(std::cin, subject);
                    enterMarks(student, subject);
                    std::cout << "Update marks for " << subject << "? (y/n): ";
                    std::cin >> updateChoice;
                    std::cin.ignore();
                } while (updateChoice == 'y' || updateChoice == 'Y');
                break;
            }
            case 3:
            {
                if (!isEnrolled)
                {
                    std::cout << "No student enrolled.\n";
                    break;
                }
                std::string enteredName;
                std::cout << "Enter student's name: ";
                std::cin.ignore();
                std::getline(std::cin, enteredName);
                if (enteredName != enrolledName)
                {
                    std::cout << "Student not enrolled.\n";
                    break;
                }
                displayMarks(student);
                break;
            }
            case 4:
                break;
            default:
                std::cout << "Invalid choice.\n";
            }
            break;
        }
        case 4:
            std::cout << "Exiting Portal...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}