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

class warden
{
private:
    std::string student_name;

public:
    int room_num = 0;
    void input()
    {
        std::cout << "Enter Student Name : ";
        std::cin.ignore();
        std::getline(std::cin, student_name);
        room_num++;
    }
    void output()
    {
        std::cout << "Name of student : " << student_name << std::endl;
        std::cout << "Room number : " << room_num << std::endl;
    }
    std::string getStudentName()
    {
        return student_name;
    }
};

class admission_office
{
private:
    std::string name;
    std::string father_name;
    std::string email;
    int phone_number;
    std::string address;

public:
    void info();
    void display_info();
    std::string getStudentName()
    {
        return name;
    }
};

void admission_office::info()
{
    std::cout << "Enter student's name : ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter student's father name : ";
    std::getline(std::cin, father_name);
    std::cout << "Enter student's E-Mail : ";
    std::getline(std::cin, email);
    std::cout << "Enter phone number : ";
    std::cin >> phone_number;
    std::cout << "Enter student's address : ";
    std::cin.ignore();
    std::getline(std::cin, address);
}

void admission_office::display_info()
{
    static int roll_number = 1; // Static to increment correctly
    std::cout << "Student's Name : " << name << std::endl;
    std::cout << "Father's Name : " << father_name << std::endl;
    std::cout << "E-Mail : " << email << std::endl;
    std::cout << "Phone Number : " << phone_number << std::endl;
    std::cout << "Address : " << address << std::endl;
    std::cout << "Roll number : " << roll_number++ << std::endl;
}

void initializeMarks(Student &s)
{
    s.Physics = 0;
    s.Biology = 0;
    s.Chemistry = 0;
    s.English = 0;
    s.Urdu = 0;
    s.Ideology = 0;
}

int getSubjectCode(const std::string &subject)
{
    if (subject == "Physics" || subject == "physics")
        return 1;
    else if (subject == "Biology" || subject == "biology")
        return 2;
    else if (subject == "Chemistry" || subject == "chemistry")
        return 3;
    else if (subject == "English" || subject == "english")
        return 4;
    else if (subject == "Urdu" || subject == "urdu")
        return 5;
    else if (subject == "Ideology" || subject == "ideology")
        return 6;
    else
        return 0;
}

void enterMarks(Student &s, std::string subject)
{
    float marks;
    std::cout << "Enter marks for " << subject << ": ";
    std::cin >> marks;

    switch (getSubjectCode(subject))
    {
    case 1:
        s.Physics = marks;
        break;
    case 2:
        s.Biology = marks;
        break;
    case 3:
        s.Chemistry = marks;
        break;
    case 4:
        s.English = marks;
        break;
    case 5:
        s.Urdu = marks;
        break;
    case 6:
        s.Ideology = marks;
        break;
    default:
        std::cout << "Invalid subject entered. Marks not updated.\n";
        break;
    }
}

void displayMarks(const Student &s)
{
    std::cout << "\nStudent Name: " << s.name << "\n";
    std::cout << "Marks:\n";
    std::cout << "Physics: " << s.Physics << "\n";
    std::cout << "Biology: " << s.Biology << "\n";
    std::cout << "Chemistry: " << s.Chemistry << "\n";
    std::cout << "English: " << s.English << "\n";
    std::cout << "Urdu: " << s.Urdu << "\n";
    std::cout << "Ideology: " << s.Ideology << "\n";
}
