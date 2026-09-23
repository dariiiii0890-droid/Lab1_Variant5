# Лабораторна робота №1 — Варіант 5

## Тема

Середовище розробки, CMake, командна робота через Git, сучасний C++.

## Варіант

**5. Обчислення визначника квадратної матриці.**

### Студент А

Розклад визначника за елементами рядка або стовпця (метод Лапласа).

У `student_a.cpp` реалізовано рекурсивне обчислення визначника через мінори.

## Структура проєкту

- `CMakeLists.txt` — налаштування CMake та C++20.
- `.gitignore` — файли, які не потрібно завантажувати в Git.
- `.gitattributes` — налаштування кодування текстових файлів.
- `shared_types.h` — спільні структури `InputData` та `Result`.
- `main.cpp` — введення матриці та запуск алгоритмів.
- `student_a.cpp` — реалізація Студента А, метод Лапласа.
- `student_b.cpp` — місце для реалізації Студента Б.

## Вимоги

- Visual Studio 2022
- Desktop development with C++
- CMake tools
- C++20

## Запуск у Visual Studio 2022

1. Розпакувати проєкт.
2. Відкрити Visual Studio 2022.
3. Обрати **File → Open → CMake...**
4. Відкрити файл `CMakeLists.txt`.
5. Дочекатися конфігурації CMake.
6. Обрати `Lab1App` як startup target.
7. Запустити через **Ctrl+F5**.

Кодування консолі налаштоване на UTF-8, тому український текст у Windows Terminal/консолі повинен відображатися нормально.

## Перевірка

Для перевірки можна ввести матрицю:

```text
1 2 3
0 4 5
1 0 6
```

Її визначник дорівнює:

```text
22
```

## Git

Після перевірки програми можна створити Git-репозиторій:

```bash
git init
git add .
git commit -m "Initialize project"
```

Потім створити репозиторій на GitHub та додати remote:

```bash
git remote add origin https://github.com/USERNAME/REPOSITORY.git
git branch -M main
git push -u origin main
```

Назву користувача та репозиторію потрібно замінити на свої.

## Гілка Студента А

Для окремої роботи Студента А:

```bash
git checkout -b feature/student-a
git add .
git commit -m "Implement Laplace determinant algorithm"
git push -u origin feature/student-a
```

Не потрібно додавати в репозиторій папки `build`, `.vs`, `Debug`, `Release` та інші згенеровані файли — вони вже внесені до `.gitignore`.
