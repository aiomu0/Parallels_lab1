#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// 25. Реализуйте функцию, которая подсчитывает сумму всех средних баллов студентов
void display_allgpa(const std::vector<Student>& database) {
    double gpa_summary = 0.0;
    for (const Student& student : database) {
        gpa_summary += student.gpa;
    }
    std::cout << "Суммарный средний балл всех студентов равен " << gpa_summary << "\n";
}

// Тест для функции addStudent
TEST(StudentDatabase, AddStudentTest) {
    std::vector<Student> database;

    // Подготовка тестовых данных
    std::string input = "Бимбобик\n1\nСлеинг\n2.5\n";
    std::stringstream input_stream(input);

    // Сохраняет старый буфер std::cin и перенаправляет на тестовый ввод
    std::streambuf* old_cin = std::cin.rdbuf();
    std::cin.rdbuf(input_stream.rdbuf());

    // Вызывает функцию addStudent
    addStudent(database);

    // Восстанавливает std::cin
    std::cin.rdbuf(old_cin);

    // Проверяет результат
    EXPECT_EQ(database.size(), 1);
    EXPECT_EQ(database[0].name, "Бимбобик");
    EXPECT_EQ(database[0].age, 1);
    EXPECT_EQ(database[0].major, "Слеинг");
    EXPECT_NEAR(database[0].gpa, 2.5, 1e-6);
}


void runInteractiveMode() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести сумму всех средних баллов студентов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                display_allgpa(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main(int argc, char **argv) {
    // Если есть аргументы командной строки, запускает тесты
    if (argc > 1) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    } else {
        // Иначе запускает интерактивное меню
        runInteractiveMode();
        return 0;
    }
}
