#include <string>

typedef struct worker
{
    std::string name;
    std::string phone_number;
    std::string EMail_id;
    int salary;
} wo;

union payment
{
    int Dollar;
    float pound;
    char currency_name[20]; // Or you can replace this with std::string
};

bool is_valid_name(const std::string &name)
{
    for (char c : name)
    {
        if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        {
            return true;
        }
    }
    return false; // Invalid if any character is not a letter
}
bool is_valid_choice(const std::string &choice)
{
    for (char d : choice)
    {
        if ((d >= 'A' && d <= 'Z') || (d >= 'a' && d <= 'z'))
        {
            return false;
        }
    }
    return true; // Invalid if any character is not a letter
}
