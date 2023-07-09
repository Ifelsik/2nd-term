# Большое ДЗ  
## Содержание  
[Входные данные](#входные-данные)  
[Функционал](#функционал)  
[Условия](#условия)  
<hr>

Задача написать программу – упрощенную реализацию базы данных для автоматизации работы студенческой библиотеки.  
 
## Входные данные  

База данных студенческой библиотеки состоит из нескольких файлов формата csv.  

1. `books.csv` - содержит информацию о всех книгах в университетской библиотеке. Каждая запись включает номер ISBN книги (уникальный номер), ФИО авторов, название книги, количество книг всего, количество доступных книг  

Пример:  
```
9666965348,Joel Spolsky,Joel on Software,10,5  
5845908914,Kernighan & Ritchie,The C Programming Language,13,10  
```

То есть в библиотеке всего 13 книг "Язык программирования С", и 3 из них на руках у студентов  

2. `students.csv` - содержит информацию о студентах: номер зачетной книжки, фамилия, имя, факультет, название специальности.  

Пример:
```
18U1337,Robert,Plant,ICS,Computer Science
18U228,Jimmy,Page,ICS,Data Science
```

3. `users.csv` - хранится информация о пользователях системы в формате: логин, хэш от пароля в формате SHA256, права на просмотр и редактирование информации по студентам, права на просмотр и редактирование информации по книгам.

Пример:
```
admin,362de3edb193b3f0485c733b6e00472739ebac98fc99db8bc726be6ffab69199,1,1
user1,3da494c6e59940aa2833a841c886f11cfbf3b61c4810a38f815c7e5533d1c87d,1,0
user2,53d397944805bdc878082d735eb5306692a0db2410cd9463a8b4bb135b5b9562,0,1
```

Флаги 1 и 1 у пользователя admin означают, что он имеет доступ к просмотру и редактированию информации как по книгам, так и по студентам.

4. `student_books.csv` - содержится информация о книгах, которые сейчас у студентов: ISBN книги, номер зачетки студента, дата возврата книги (DD.MM.YYYY).

Пример:
```
9666965348,18U1337,11.11.2023  
5845908914,18U228,04.05.2023
```
<a name="features"></a> 
## Функционал

### Общий  
- При запуске программы требуется ввести логин и пароль, если они указаны неверно выводится ошибка
- Если пользователь имеет доступ только к просмотру и редактированию книг выводить меню для книг  
- Если пользователь имеет доступ только просмотру и редактированию выводить меню для студентов  
- Если пользователь имеет доступ и к книгам, и к студентам – выводить меню верхнего уровня: 1 – Книги, 2 – Студенты. В меню книг и студентов добавить функцию: 0 – возврат в основное меню
Завершить работу программы (текущее состояния библиотеки сохраняется в файл)

### Книги
- Добавить новую книгу (при добавлении проверять нет ли уже такой книги по номеру ISBN)
- Удалить книгу по номеру ISBN
- Просмотр всей информации по книге (здесь и далее книга выбирается по номеру ISBN, если введен неправильный номер выводится сообщение о том, что книга не найдена)
- Вывести информацию по всем книгам в виде таблицы, записи должны быть отсортированы по номеру ISBN
- Редактировать информацию по книге
- Изменить количество книг в библиотеке по номеру ISBN (необходимо пересчитать количество доступных книг)
- Выдать книгу студенту по номеру ISBN (необходимо уменьшить количество доступных книг на 1, если количество доступных книг – 0, вывести соответствующее сообщение)
- Принять книгу от студента по номеру ISBN (необходимо увеличить количество доступных книг на 1, если количество доступных книг равно количеству книг в библиотеке, вывести соответствующее сообщение)

### Студенты
- Добавить студента (при добавлении проверять, что такого студента еще нет по номеру зачетной книжки)
- Удалить студента по номеру зачетной книжки
- Редактировать информацию по студенту
- Просмотреть информацию по студенту по номеру зачетной книжки
- Поиск по фамилии студента (пользователь вводит фамилию студента, если библиотекой пользуется один или несколько студентов-однофамильцев – выводится вся информация по ним, если студента нет – выводится соответствующее сообщение)


### Книги у студентов
- Нельзя удалить студента, у которого есть книги
- Нельзя удалить книгу, которая есть у студентов
- Нельзя изменять ISBN книг и номер зачетки студентов
- Для каждого студента (по номеру зачетки) есть возможность посмотреть информацию по всем его книгам (информация из книги и дата сдачи в библиотеку)
- Для каждой книги можно посмотреть информацию по студентам, которые ее взяли (информация о студенте и дата сдачи в библиотеку)


### Доп функционал (за доп баллы)
В пятом файле «library.log» ведется лог действий пользователей в системе в формате дата и время действия, логин пользователя, название функции из меню. Так же туда пишутся все сообщения, которые выводятся пользователю: ошибки и подтверждения успешного завершения той или иной функции

Пример:  
```
10.05.2023 21:00:12,admin,deleteBook
10.05.2023 21:00:13,admin,Book deleted sucessfully
10.05.2023 21:00:28,admin,createStudent
```

<a name="requirements"></a>
## Условия
- Можно использовать сторонние библиотеки, но только для реализации какого-нибудь атомарного функционала (структуры, алгоритмы)
- Данное ДЗ нужно будет защитить очно, нужно быть готовым ответить на любой вопрос по коду и работе программы
- Писать код красиво, разделять все на функции, файлы, называть нормально переменные, использовать дефайны и энамы, избегать повторений, делать понятные сообения об ошибках, проверять весь пользовательский ввод, не использовать кириллицу и т.д.
- За неверные ответы на вопросы и списывание кода - баллы снижаются
- Разрешается сдавать задание с неполным функционалом, за отсутствующий функционал баллы будут вычитаться, за каждый пункт примерно 0.86 баллов.
- Должно быть реализовано минимум 8 пунктов, причем по 2 пункта из каждого раздела.
- За доп функционал накидывается ещё 5 баллов.
- Дедлайн - день экзамена вашей группы. Но помните о том, что преподавателю надо ещё посмотреть ваше ДЗ и вы должны его защитить, так что делать это в ночь перед экзом плохая идея