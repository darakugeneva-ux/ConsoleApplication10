#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
// Размер массива (количество детей)
const int SIZE = 20;
// Структура даты рождения
struct Date
{
    int day;
    int month;
    int year;
};
// Структура анкеты ребёнка
struct Child
{
    char lastName[40];      // Фамилия
    char firstName[40];     // Имя
    char gender[10];        // "Boy" или "Girl"
    int height;             // Рост в см
    Date birthDate;         // Дата рождения
};
typedef Child arr[SIZE];
// ==================== Функции для работы с датами ====================
// Сравнение двух дат (возвращает true, если date1 < date2)
bool isDateLess(const Date& d1, const Date& d2)
{
    if (d1.year != d2.year) return d1.year < d2.year;
    if (d1.month != d2.month) return d1.month < d2.month;
    return d1.day < d2.day;
}
// Вычисление возраста ребёнка на заданную дату (например, на 1 сентября 2026)
int getAge(const Date& birth, int currentYear, int currentMonth, int currentDay)
{
    int age = currentYear - birth.year;
    if (currentMonth < birth.month || (currentMonth == birth.month && currentDay < birth.day))
    {
        age--;
    }
    return age;
}
// Проверка, родился ли ребёнок в заданном месяце
bool isBirthMonth(const Date& birth, int month)
{
    return birth.month == month;
}
// ==================== Функции обмена и сортировки ====================
void swapChildren(Child& a, Child& b)
{
    Child temp = a;
    a = b;
    b = temp;
}
// Сортировка пузырьком с компаратором
void bubbleSort(Child arr[], int n, bool (*compare)(const Child&, const Child&))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                swapChildren(arr[j], arr[j + 1]);
            }
        }
    }
}
// Компаратор для сортировки по дате рождения
bool compareByBirthDate(const Child& a, const Child& b)
{
    return isDateLess(a.birthDate, b.birthDate);
}
// ==================== Функции вывода ====================
// Вывод одного ребёнка
void printChild(const Child& c)
{
    cout << " | " << left << setw(15) << c.lastName
        << " | " << setw(12) << c.firstName
        << " | " << setw(8) << c.gender
        << " | " << setw(6) << c.height
        << " | " << setw(2) << c.birthDate.day << "."
        << setw(2) << c.birthDate.month << "."
        << setw(4) << c.birthDate.year << " |" << endl;
}
// Вывод шапки таблицы
void printHeader()
{
    cout << "\n ===========================================================================" << endl;
    cout << " | " << left << setw(15) << "Фамилия"
        << " | " << setw(12) << "Имя"
        << " | " << setw(8) << "Пол"
        << " | " << setw(6) << "Рост"
        << " | " << setw(12) << "Дата рождения" << " |" << endl;
    cout << " ===========================================================================" << endl;
}
// Вывод всех детей
void printAllChildren(Child children[], int n, const char* title)
{
    cout << "\n =================== " << title << " ===================" << endl;
    if (n == 0)
    {
        cout << " Нет данных!" << endl;
        return;
    }
    printHeader();
    for (int i = 0; i < n; i++)
    {
        printChild(children[i]);
    }
    cout << " ===========================================================================" << endl;
}
// Обёрточная функция для вывода отфильтрованных данных
void showFiltered(Child children[], int n, const char* filterName)
{
    cout << "\n =================== ОТФИЛЬТРОВАНО: " << filterName << " (" << n << " детей) ===================" << endl;
    if (n == 0)
    {
        cout << " Детей, соответствующих критерию, не найдено!" << endl;
    }
    else
    {
        printHeader();
        for (int i = 0; i < n; i++)
        {
            printChild(children[i]);
        }
        cout << " ===========================================================================" << endl;
    }
}
// ==================== Инициализация данных ====================
Child* initChildren()
{
    Child* children = new Child[SIZE];
    // 20 детей с разными данными (пол: "Boy" или "Girl")
    children[0] = { "Иванов", "Алексей", "Boy", 145, {15, 5, 2014} };
    children[1] = { "Петрова", "Анна", "Girl", 138, {23, 8, 2015} };
    children[2] = { "Сидоров", "Дмитрий", "Boy", 152, {7, 3, 2013} };
    children[3] = { "Кузнецова", "Екатерина", "Girl", 140, {12, 11, 2014} };
    children[4] = { "Смирнов", "Максим", "Boy", 148, {30, 1, 2012} };
    children[5] = { "Васильева", "Мария", "Girl", 135, {18, 7, 2016} };
    children[6] = { "Попов", "Илья", "Boy", 155, {9, 9, 2012} };
    children[7] = { "Соколова", "Ольга", "Girl", 142, {27, 4, 2014} };
    children[8] = { "Михайлов", "Андрей", "Boy", 150, {3, 10, 2013} };
    children[9] = { "Фёдорова", "Татьяна", "Girl", 137, {14, 2, 2015} };
    children[10] = { "Морозов", "Никита", "Boy", 160, {19, 12, 2011} };
    children[11] = { "Волкова", "Алина", "Girl", 143, {25, 6, 2013} };
    children[12] = { "Зайцев", "Кирилл", "Boy", 147, {8, 8, 2014} };
    children[13] = { "Павлова", "Виктория", "Girl", 139, {1, 3, 2016} };
    children[14] = { "Семёнов", "Егор", "Boy", 153, {22, 11, 2012} };
    children[15] = { "Егорова", "Анастасия", "Girl", 141, {5, 5, 2015} };
    children[16] = { "Андреев", "Артём", "Boy", 149, {17, 1, 2014} };
    children[17] = { "Николаева", "Дарья", "Girl", 136, {29, 9, 2016} };
    children[18] = { "Дмитриев", "Павел", "Boy", 156, {11, 4, 2012} };
    children[19] = { "Борисова", "Юлия", "Girl", 144, {2, 12, 2014} };
    return children;
}
// ==================== Задание 1: Работа с текстовым файлом ====================
// Запись данных (фамилия и пол) в текстовый файл
void writeGenderToTextFile(const char* filename)
{
    ofstream out(filename);
    if (!out.is_open())
    {
        cout << " Ошибка: не удалось создать файл " << filename << endl;
        return;
    }
    out << "Иванов Boy" << endl;
    out << "Петрова Girl" << endl;
    out << "Сидоров Boy" << endl;
    out << "Кузнецова Girl" << endl;
    out << "Смирнов Boy" << endl;
    out << "Васильева Girl" << endl;
    out << "Попов Boy" << endl;
    out << "Соколова Girl" << endl;
    out << "Михайлов Boy" << endl;
    out << "Фёдорова Girl" << endl;
    out << "Морозов Boy" << endl;
    out << "Волкова Girl" << endl;
    out << "Зайцев Boy" << endl;
    out << "Павлова Girl" << endl;
    out << "Семёнов Boy" << endl;
    out << "Егорова Girl" << endl;
    out << "Андреев Boy" << endl;
    out << "Николаева Girl" << endl;
    out << "Дмитриев Boy" << endl;
    out << "Борисова Girl" << endl;
    out.close();
    cout << " Текстовый файл создан: " << filename << endl;
}
// Чтение из текстового файла и обновление пола детей
void readAndUpdateGenderFromTextFile(Child children[], int n, const char* filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cout << " Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }
    char lastName[40];
    char gender[10];
    int found = 0;
    while (fin >> lastName >> gender)
    {
        for (int i = 0; i < n; i++)
        {
            if (strcmp(children[i].lastName, lastName) == 0)
            {
                strcpy(children[i].gender, gender);
                found++;
                break;
            }
        }
    }
    fin.close();
    cout << " Обновлено " << found << " записей из файла " << filename << endl;
}
// ==================== Задание 2: Работа с бинарным файлом ====================
// Запись всех детей в бинарный файл
void saveChildrenToBinary(const char* filename, Child children[], int n)
{
    ofstream out(filename, ios::binary | ios::out);
    if (!out)
    {
        cout << " Ошибка записи в бинарный файл!" << endl;
        return;
    }
    out.write((char*)children, sizeof(Child) * n);
    out.close();
    cout << " Данные сохранены в бинарный файл: " << filename << endl;
}
// Чтение всех детей из бинарного файла
void readChildrenFromBinary(const char* filename, Child children[], int n)
{
    ifstream in(filename, ios::binary | ios::in);
    if (!in)
    {
        cout << " Ошибка чтения из бинарного файла!" << endl;
        return;
    }
    in.read((char*)children, sizeof(Child) * n);
    in.close();
    cout << " Данные загружены из бинарного файла: " << filename << endl;
}
// 1. Вычисление среднего роста 12-летних девочек
float getAverageHeightOf12YearOldGirls(Child children[], int n, int currentYear, int currentMonth, int currentDay)
{
    int count = 0;
    int totalHeight = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(children[i].gender, "Girl") == 0)
        {
            int age = getAge(children[i].birthDate, currentYear, currentMonth, currentDay);
            if (age == 12)
            {
                totalHeight += children[i].height;
                count++;
            }
        }
    }
    if (count == 0) return 0.0f;
    return (float)totalHeight / count;
}
// 2. Перенос 3 самых младших мальчиков в отдельный массив
int getYoungestBoys(Child src[], int srcSize, Child dst[], int count)
{
    // Сначала копируем всех мальчиков
    Child* boys = new Child[srcSize];
    int boysCount = 0;
    for (int i = 0; i < srcSize; i++)
    {
        if (strcmp(src[i].gender, "Boy") == 0)
        {
            boys[boysCount++] = src[i];
        }
    }
    // Сортируем мальчиков по дате рождения (от младших к старшим)
    bubbleSort(boys, boysCount, [](const Child& a, const Child& b) {
        return isDateLess(b.birthDate, a.birthDate); // обратный порядок: младшие первые
        });
    // Берём первых count (самых младших)
    int resultCount = (boysCount < count) ? boysCount : count;
    for (int i = 0; i < resultCount; i++)
    {
        dst[i] = boys[i];
    }

    delete[] boys;
    return resultCount;
}
// 3. Сортировка всех детей по дате рождения
void sortByBirthDate(Child children[], int n)
{
    bubbleSort(children, n, compareByBirthDate);
}
// 4. Поиск ребёнка по фамилии и вывод всех данных
void findChildByLastName(Child children[], int n, const char* lastName)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(children[i].lastName, lastName) == 0)
        {
            cout << "\n =================== НАЙДЕН РЕБЁНОК: " << lastName << " ===================" << endl;
            printHeader();
            printChild(children[i]);
            cout << " ===========================================================================" << endl;
            return;
        }
    }
    cout << "\n Ребёнок с фамилией \"" << lastName << "\" не найден!" << endl;
}
// 5. Изменение данных конкретного ребёнка
void modifyChild(Child& child, const char* newFirstName, int newHeight, int newDay, int newMonth, int newYear)
{
    strcpy(child.firstName, newFirstName);
    child.height = newHeight;
    child.birthDate.day = newDay;
    child.birthDate.month = newMonth;
    child.birthDate.year = newYear;
    cout << " Данные ребёнка успешно изменены!" << endl;
}
// 6. Получение списка детей, родившихся в заданном месяце
int getChildrenByBirthMonth(Child src[], int srcSize, Child dst[], int month)
{
    int count = 0;
    for (int i = 0; i < srcSize; i++)
    {
        if (isBirthMonth(src[i].birthDate, month))
        {
            dst[count++] = src[i];
        }
    }
    return count;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    Child* children = initChildren();
    cout << "\n ================================================================" << endl;
    // 1. Вывод всех детей
    printAllChildren(children, SIZE, "ВСЕ ДЕТИ");
    // 2. Средний рост 12-летних девочек
    float avgHeight = getAverageHeightOf12YearOldGirls(children, SIZE, 2026, 9, 1);
    cout << "\n =================== РЕЗУЛЬТАТ ===================" << endl;
    if (avgHeight > 0)
        cout << " Средний рост 12-летних девочек: " << avgHeight << " см" << endl;
    else
        cout << " 12-летних девочек не найдено!" << endl;
    // 3. Перенос 3 самых младших мальчиков в отдельный массив
    Child youngestBoys[3];
    int youngestCount = getYoungestBoys(children, SIZE, youngestBoys, 3);
    showFiltered(youngestBoys, youngestCount, "3 САМЫХ МЛАДШИХ МАЛЬЧИКА");
    // 4. Сортировка по дате рождения
    sortByBirthDate(children, SIZE);
    printAllChildren(children, SIZE, "ДЕТИ, ОТСОРТИРОВАННЫЕ ПО ДАТЕ РОЖДЕНИЯ");
    // 5. Поиск ребёнка по фамилии
    findChildByLastName(children, SIZE, "Смирнов");
    findChildByLastName(children, SIZE, "Петрова");
    findChildByLastName(children, SIZE, "Несуществующий");
    // 6. Изменение данных конкретного ребёнка
    for (int i = 0; i < SIZE; i++)
    {
        if (strcmp(children[i].lastName, "Смирнов") == 0)
        {
            modifyChild(children[i], "Максим", 155, 15, 6, 2012);
            break;
        }
    }
    // Проверка изменения
    findChildByLastName(children, SIZE, "Смирнов");
    // 7. Дети, родившиеся в заданном месяце (например, май - 5)
    Child birthMonthChildren[SIZE];
    int birthMonthCount = getChildrenByBirthMonth(children, SIZE, birthMonthChildren, 5);
    showFiltered(birthMonthChildren, birthMonthCount, "ДЕТИ, РОДИВШИЕСЯ В МАЕ");
    // ==================== Задание 1: Работа с текстовым файлом ====================
    cout << "\n =================== ЗАДАНИЕ 1: ТЕКСТОВЫЙ ФАЙЛ ===================" << endl;
    // Запись в текстовый файл
    writeGenderToTextFile("children_gender.txt");
    // Чтение из текстового файла и обновление
    readAndUpdateGenderFromTextFile(children, SIZE, "children_gender.txt");
    // Вывод обновлённых данных
    printAllChildren(children, SIZE, "ОБНОВЛЁННЫЕ ДАННЫЕ (ПОЛ ИЗ ФАЙЛА)");
    // ==================== Задание 2: Работа с бинарным файлом ====================
    cout << "\n =================== ЗАДАНИЕ 2: БИНАРНЫЙ ФАЙЛ ===================" << endl;
    // Запись данных в бинарный файл
    saveChildrenToBinary("children.bin", children, SIZE);
    // Создаём новый массив для загрузки
    Child* readChildren = new Child[SIZE];
    // Чтение данных из бинарного файла
    readChildrenFromBinary("children.bin", readChildren, SIZE);
    // Проверка корректности
    printAllChildren(readChildren, SIZE, "ДАННЫЕ, ПРОЧИТАННЫЕ ИЗ БИНАРНОГО ФАЙЛА");
    // Очистка памяти
    delete[] children;
    delete[] readChildren;
    return 0;
}