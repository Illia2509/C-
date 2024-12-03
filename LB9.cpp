// 1.3 Завдання на лабораторну роботу
// Створити базовий абстрактний клас і породити від нього відповідний клас -
// наступник.

// 1.4 Варіанти завдань
// Виконати варіант завдання з лабораторної роботи 8, створивши шаблоный
// базовый абстрактный клас у якому реалізовані створення та операції з
// динамічним шаблоним масивом, об’явлені чисто віртуальні метод вводу виводу.
// У класі нащадку, який свторений успадкуванням до заданого типу
// (відповідної структури), винести остальні методі. Продемонструвати роботу з
// конструкторами базового та успадкованого класів.

#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
class TUniversity {
protected:
    T* arr;    
    int n;     
public:
    TUniversity() : n(0), arr(nullptr) {}
    TUniversity(int size) : n(size), arr(size > 0 ? new T[size] : nullptr) {}
    TUniversity(const TUniversity& other);
    TUniversity& operator=(const TUniversity& other);
    virtual ~TUniversity();

    void addFaculty(const T& faculty);
    void deleteFacultyByIndex(int index);
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual int totalStudents() const = 0;
};

template <typename T>
TUniversity<T>::TUniversity(const TUniversity<T>& other) {
    n = other.n;
    if (n > 0) {
        arr = new T[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = other.arr[i];
        }
    } else {
        arr = nullptr;
    }
}

template <typename T>
TUniversity<T>& TUniversity<T>::operator=(const TUniversity<T>& other) {
    if (this == &other) return *this;

    delete[] arr;
    n = other.n;
    if (n > 0) {
        arr = new T[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = other.arr[i];
        }
    } else {
        arr = nullptr;
    }
    return *this;
}

template <typename T>
TUniversity<T>::~TUniversity() {
    delete[] arr;
}

template <typename T>
void TUniversity<T>::addFaculty(const T& faculty) {
    T* newArr = new T[n + 1];
    for (int i = 0; i < n; ++i) {
        newArr[i] = arr[i];
    }
    newArr[n] = faculty;
    delete[] arr;
    arr = newArr;
    ++n;
}

template <typename T>
void TUniversity<T>::deleteFacultyByIndex(int index) {
    if (index < 0 || index >= n) return;

    T* newArr = new T[n - 1];
    int currentIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (i != index) {
            newArr[currentIndex++] = arr[i];
        }
    }
    delete[] arr;
    arr = newArr;
    --n;
}

struct Faculty {
    std::string name;
    std::string profile;
    int students;

    Faculty() : name("Дефолт"), profile("Дефолт"), students(0) {}
    Faculty(const std::string& n, const std::string& p, int s) : name(n), profile(p), students(s) {}
    friend std::ostream& operator<<(std::ostream& out, const Faculty& f);
    friend std::istream& operator>>(std::istream& in, Faculty& f);
};

std::ostream& operator<<(std::ostream& out, const Faculty& f) {
    out << std::setw(15) << f.name << std::setw(15) << f.profile << std::setw(5) << f.students;
    return out;
}

std::istream& operator>>(std::istream& in, Faculty& f) {
    std::cout << "Імя факультету: ";
    in >> f.name;
    std::cout << "Профіль факультету: ";
    in >> f.profile;
    std::cout << "Кількість студентів: ";
    in >> f.students;
    return in;
}

class University : public TUniversity<Faculty> {
public:
    University() : TUniversity() {}
    University(int size) : TUniversity(size) {}
    University(const University& other) : TUniversity(other) {}

    void input() {
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
    }

    void output() const  {
        std::cout << "Зараз факультети:\n";
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << std::endl;
        }
    }

    int totalStudents() const {
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += arr[i].students;
        }
        return total;
    }
};

int main() {
    University uni(3);
    uni.input();

    std::cout << "Загальна інформація:\n";
    uni.output();

    Faculty newFaculty("ТЕСТ", "Право", 2002);
    uni.addFaculty(newFaculty);

    std::cout << "Додавання факультету:\n";
    uni.output();

    std::cout << "Стираємо факультет:\n";
    uni.deleteFacultyByIndex(1);

    std::cout << "Тепер після стирання так:\n";
    uni.output();

    std::cout << "Студентів в універі загалом: " << uni.totalStudents() << std::endl;

    return 0;
}


