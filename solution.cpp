#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(const char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(const char* name, double gpa, char* names[], double gpas[], int& size, int capacity) 
{
    if(size >= capacity) 
    {
        throw "List full";
    }

    names[size] = new char[strlen(name) + 1];
    strcpy(names[size], name);
    gpas[size] = gpa;
    size++;

    std::cout << "Student added" << std::endl;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGPA) 
{
    *gpaPtr = newGPA;
}

// TODO: implement printStudent
void printStudent(const char* name, double& gpa) 
{
    static_cast<int>(gpa);
    std::cout << name << ": " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) 
{
    if(size <= 0) 
    {
        throw "No students";
    }

    double sum = 0.0;
    for(int i = 0; i < size; ++i) 
    {
        sum += gpas[i];
    }
    return sum / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                std::string name;
                double gpa;
                //std::cout << "Enter student name: ";
                //std::cout << "Enter student GPA: ";
                std::cin >> name >> gpa;
                try{addStudent(name.c_str(), gpa, names, gpas, size, capacity);
                }catch(const char* msg) { std::cout << msg << std::endl; }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                int studentIndex;
                double newGPA;
                //std::cout << "Enter student #: ";
                //std::cin >> studentIndex;
                //std::cout << "Enter new GPA: ";
                std::cin >> studentIndex >> newGPA;

                if(studentIndex < 0 || studentIndex >= size) 
                {
                    std::cout << "Student not found" << std::endl;
                }
                else
                {
                    updateGPA(&gpas[studentIndex], newGPA);
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic
                for(int i = 0; i < size; ++i) 
                {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try
                {
                    double avg = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << avg << std::endl;
                }
                catch(const char* msg) {std::cout << msg << std::endl;}
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for(int i = 0; i < size; ++i) 
    {
        delete[] names[i];
    };

    return 0;
}
