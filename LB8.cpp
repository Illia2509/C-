

#include <iostream>
#include <string>

// Розробити клас, що представляє університет. Університет характеризується
// назвою, вулицею, номером будинку, списком факультетів і ректором. Ректор
// характеризується ім'ям, прізвищем і вченим ступенем. Факультет
// характеризується назвою, профілем і числом студентів.

class Faculty 
{
    private:
        std::string name;
        std::string profile;
        int number_of_students;

    public:
        Faculty& operator+(int students); // 8. перевантажену арифметичну операцію

        std::string getName() const { return name; };
        int getNumberOfStudents() const { return number_of_students; }

        bool operator==(const Faculty& obj) const { // 9. перевантажену логічну операцію
            int s1 = this->number_of_students;
            int s2 = obj.number_of_students;
            return (s1 == s2);
        }

        operator double() const {
            return static_cast<double>(number_of_students);
        }

        Faculty(); //1. конструктор за замовченням
        void print() const;
        ~Faculty(); //2. деструктор
        Faculty(std::string na, std::string p, int n); // 3. конструктори з параметрами
        Faculty(const Faculty&obj); // 4. конструктор копіювання
        
};

Faculty::Faculty() : name("Computer"), profile("IT"), number_of_students(5000) {
    std::cout << "1. конструктор за замовченням\n";
}

void Faculty::print() const
{
    std::cout << "Faculty name: " << name << std::endl;
    std::cout << "Faculty profile: " << profile << std::endl;
    std::cout << "Number of students: " << number_of_students << std::endl;
};

Faculty::~Faculty()
{
    std::cout << "2. деструктор\n";
}

Faculty::Faculty(std::string na, std::string p, int n) : name(na), profile(p), number_of_students(n)
{
    std::cout << "3. конструктори з параметрами\n";
};

Faculty::Faculty(const Faculty& obj): name(obj.name), profile(obj.profile), number_of_students(obj.number_of_students)
{
    std::cout << "4. конструктор копіювання \n";
}

Faculty& Faculty::operator+(int students)
{
    number_of_students += students; 
    return *this;
}
class Rector 
{
    private: 
        std::string first_name, second_name, academic_degree;

    public:
    Rector(); // 1. конструктор за замовченням
    void print() const;
    void printFullName() const;
    ~Rector(); //2. деструктор

};

Rector::Rector() : first_name("Степан"), second_name("Петрушевич"), academic_degree("Історик")
{
    std::cout << "1. конструктор за замовченням\n";
}

void Rector::print() const
{
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Second name: " << second_name << std::endl;
    std::cout << "Academic degree: " << academic_degree << std::endl;
}

void Rector::printFullName() const // 2. дізнатися ім'я, прізвище і вчений ступінь ректора
{
    std::cout << first_name << " " << second_name << " " << academic_degree << std::endl;
}

Rector::~Rector()
{
    std::cout << "2. деструктор\n";
}

class University
{
    private:    
        std::string name;
        std::string street;
        int number;
        Faculty faculties[2];
        Rector rector;
    public:

        operator double() const {
            double numberOfStudents = 0;
            for (int i = 0; i < 2; i++) {
                numberOfStudents += faculties[i].getNumberOfStudents();
            }
            return numberOfStudents;
        }

        std::string getName() const { return name; }
        std::string getStreet() const { return street; }
        int getNumber() const { return number; }
        Rector getRector() const { return rector; }
        Faculty getFaculty(int i) const { return faculties[i]; }

        void setName(const std::string& n) { name = n; }
        void setStreet(const std::string& s) { street = s; }
        void setNumber(int num) { number = num; }
        void setRector(const Rector& r) { rector = r; }
        void setFaculty(int i, const Faculty& f) { faculties[i] = f; }

        University(); //1. конструктор за замовченням
        void print() const;
        void printAdress() const;
        void printNumberOfSttudentOnFuculty() const;
        ~University(); //2. деструктор
        University(std::string n, std::string s, int na, Rector r); // 3. конструктори з параметрами
        University(const University&obj); // 4. конструктор копіювання
        University& operator=(const University& obj); // 5. перевантажену операцію присвоювання
};

University::University() : name("IT Steap University"), street("Zamarstunivska"), number(83), rector()
{
    for (int i = 0; i < 2; ++i) {
        faculties[i] = Faculty();
    }
    std::cout << "1. конструктор за замовченням\n";
}

void University::printNumberOfSttudentOnFuculty() const //3. дізнатися число студентів даного факультету
{
    for(int i = 0; i < 2; i++){
        if (faculties[i].getName() == "Computer"){
            std::cout << "Кількість студентів на цьому факультеті: " << faculties[i].getNumberOfStudents() << std::endl;
        };
    };
    std::cout << "Faculty name: " << name << std::endl;
};

void University::print() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Street: " << street << std::endl;
    std::cout << "Number: " << number << std::endl;
    rector.print();
    for (int i = 0; i < 2; ++i) {
        faculties[i].print();
    }
}

void University::printAdress() const // 1. дізнатися повну адресу університету
{
    std::cout << street << " " << number << std::endl;

}

University::~University()
{
    std::cout << "2. деструктор\n";
}

University::University(std::string n, std::string s, int na, Rector r) : name(n), street(s), number(na), rector(r)
{
    std::cout << "3. конструктори з параметрами\n";
};

University::University(const University& obj): name(obj.name), street(obj.street), number(obj.number), rector(obj.rector)
{
    std::cout << "4. конструктор копіювання \n";
}

University&  University::operator=(const University& obj)
{
    if (this == &obj)
        return *this;

    name = obj.name;
    street = obj.street;
    number = obj.number;
    rector = obj.rector;
    for (int i = 0; i < 2; ++i) {
        faculties[i] = obj.faculties[i];  
    }

    return *this; 
}

std::ostream& operator<<(std::ostream& out, const University& obj)
{
    out << "Name: " << obj.getName() << std::endl;
    out << "Street: " << obj.getStreet() << std::endl;
    out << "Number: " << obj.getNumber() << std::endl;
    out << "Rector: " << std::endl; 
    obj.getRector().print();
    out << "Faculties: " << std::endl;
    for (int i = 0; i < 2; ++i) {
        obj.getFaculty(i).print();
    }
    return out;
};

std::istream& operator>>(std::istream& in, University& obj)
{
std::string name, street;
    int number;
    
    std::cout << "Enter University Name: ";
    in >> name;
    obj.setName(name);
    
    std::cout << "Enter University Street: ";
    in >> street;
    obj.setStreet(street);
    
    std::cout << "Enter University Number: ";
    in >> number;
    obj.setNumber(number);

    Rector rector;

    return in;
}

int main(){
    std::cout << "Створення університету за замовчуванням \n";
    University uni;  
    uni.print();     

    std::cout << "Створення ректора\n";
    Rector rector;

    std::cout << "Створення університету з параметрами \n";
    University uni2("Politech University", "Lviv street", 123, rector);  
    uni2.print();  

    std::cout << "\n Використання операції присвоєння\n";
    University uni1;
    uni1 = uni2;    
    uni1.print();

    std::cout << "\nВикористання операції виведення в потік\n";
    std::cout << uni2 << std::endl;

    std::cout << "\nВикористання операції введення в потік\n";
    std::cin >> uni1;  
    uni1.print(); 

    int numberOfFaculty;
    int numberOfStudents;

    std::cout << "\nДодавання студентів на факультети\n";
    std::cin >> numberOfFaculty; 
    std::cout << "В який факультет додати студентів (0 або 1)? ";
    if (numberOfFaculty < 0 || numberOfFaculty >= 2) {
        std::cout << "Невірний номер факультету!" << std::endl;
        return 1; 
    }

    std::cout << "Скільки студентів додавати? ";
    std::cin >> numberOfStudents;
    uni1.getFaculty(numberOfFaculty) + numberOfStudents; 
    uni1.getFaculty(numberOfFaculty) + numberOfStudents; 
    uni1.print();

    Faculty faculty1("Mathematics", "aaa", 5000);
    Faculty faculty3("Physics", "bbb", 3000);

    std::cout << "Порівняння факультетів\n";
    if (faculty1 == faculty3) {
        std::cout << "Факультет 1 і факультет 2 мають однакову кількість студентів.\n";
    } else {
        std::cout << "Факультет 1 і факультет 2 мають різну кількість студентів.\n";
    }

    std::cout << "Середнє значення студентів у факультеті 1: " << static_cast<double>(faculty1) << std::endl;


    std::cout << "\nЗавершення роботи програми\n";



    std::cout << "1. дізнатися повну адресу університету\n";
    std::cout << "Повна адреса університету: \n"; 
    uni.printAdress();

    std::cout << "2. дізнатися ім'я, прізвище і вчений ступінь ректора \n";
    std::cout << "Ім'я, прізвище і вчений ступінь ректора: \n";
    rector.printFullName();

    std::cout << "3. дізнатися число студентів даного факультету \n";
    std::cout << "Число студентів даного факультету: \n";
    uni.printNumberOfSttudentOnFuculty();

    std::cout << "4. відкрити новий факультет\n";
    Faculty facultiPravo("Pravo", "Shoc", 211);

    std::cout << "5. закрити факультет\n";
    Faculty* facultiDoctor = new Faculty("Likar", "Shoc`", 211);
    delete facultiDoctor;

    std::cout << "6. знайти середнє число студентів за всіма факультетами\n";
    double totalStudents = static_cast<double>(uni);

    return 0;
}