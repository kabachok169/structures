# Сравнение отсортированных массива, списка и развернутого списка


В данной работе приводится сравнение указанных выше структур данных.  Каждая из них имеет свои преимущества и недостатки, которые я покажу на практике, протестировав структуры.

***

## Содержание:


* [Sorted array](#sorted-array)
* [Sorted list](#sorted-list)
* [Sorted expanded list](#sorted-expanded-list)

***

Для каждой из структур данных реализованы:   
1. Операция вставки - *add*
2. Операция удаления по значению - *erase*
3. Операция поиска по значению - *search*
4. Операция обращения по индексу - *operator[]*
5. Операция получения минимального и максимального элементов - *min/max*
6. Операция вывода на экран текущего состояния структуры - *print*

Примечание:  
Обращение по индексу, как и получение крайних элементов дают константные данные, так как иначе происходит нарушение структуры данных.  Для изменения структуры данных используются **только** операции *add* и *erase*.

***

## Sorted array


Структура данных представляет собой непрерывную, динамически расширяющуюся область памяти, которая в любом состоянии структуры заполнена отсортированными данными.  Пользователь должен **сам** задать функцию-компаратор для данных, если он не сделал этого, по умолчанию используется *std::less*.


### add

`void add(T _data) // сигнатура функции`

Функция принимает объект пользовательского типа данных. Так как структура данных изначально отсортирована, то применяется алгоритм бинарного поиска для определения места вставки нового элемента. [Бинарный поиск](https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D1%8B%D0%B9_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA).  
Если массив заполнен полностью, происходит расширение массива (коэффициент амортизации задается пользователем, если тот не указал - берется 1,5).  
Нужная часть массива сдвигается вправо и на позицию вставляется исходный элемент.  
*Сложность в лучшем случае - О(1), в среднем - O(n), в худшем - O(n)*

### erase

`bool erase(T _data) // сигнатура функции`

Функция принимает объект пользовательского типа данных. Так как структура данных изначально отсортирована, то применяется алгоритм бинарного поиска для определения места нахождения элемента. [Бинарный поиск](https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D1%8B%D0%B9_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA). 
Если такого элемента нет в массиве - функция вернет `false`. Если он есть - производится сдвиг нужной части массива и вернется `true`.  
*Сложность в лучшем случае - О(1), в среднем - O(n), в худшем - O(n)*

### search

`long int search(T _data) // сигнатура функции`

Применяется алгоритм бинарного поиска, если элемент нашелся в массиве, возвращается его индекс, если такого элемента нет возвращается `-1`.  
*Сложность в лучшем случае - O(1), в среднем - О(log2(n)), в худшем - O(log2(n))*

### operator []

`const T& operator[](size_t index) // сигнатура функции`

Возвращает константную ссылку на элемент массива по индексу, если индекс слишком велик, бросает исключение `std::invalid_argument("Too big to be true")`  
*Сложность - O(1)*.

### print

Функция вывода структуры данных. Данные выводятся внутри [ ] и разделены запятой. Пример - `[ 1, 2, 3, 4, 5]`

### Преимущества и недостатки

Основными преимуществами отсортированного массива являются:  
1. Быстрый поиск элемента в массиве
2. Чрезвычайно маленький объем дополнительной памяти
3. Быстрый доступ к элементу массива


Недостатки:
1. Необходимость иногда производить дорогостоящую операцию перевыделения памяти.
2. Возможность возникновения ситуации, когда выделился огромный объем неиспользуемой памяти.
3. Возможность ситуации, когда непрерывная область памяти становится слишком большой для хранения.

### Область применения

Массивы в целом используются практически везде. Они намного удобнее для большинства задач, чем списки в первую очедеь из-за того, что в них не используется дополнительная память и не производится переход по указателям.

Отсортированный массив можно использовать, например, для получения кода Хаффмана, так как трудоемкая операция перевыделения памяти применяется только на первом этапе работы программы, при заполнении массива, а потом с большой скоростью происходит изъятие отсортированных данных.  

***

## Sorted list

Структура данных представляет собой множество связанных между собой блоков, в каждом из которых хранится объект данных, указатель на следующий блок и указатель на предыдущий блок. Данные отсортированы в порядке следования блоков.  
Пользователь должен **сам** задать функцию-компаратор для данных, если он не сделал этого, по умолчанию используется *std::less*.  

### add

`void add(T _data) // сигнатура функции`

Функция принимает объект пользовательского типа данных. Так как структура данных изначально отсортирована, вычисляется разность между начальным блоком и элементом и конечным блоком и элементом. Производится проход по списку в прямом или обратном направлении в зависимостри от разницы, в поисках места вставки элемента. Когда место найдено конструируем новый блок и переопределяем указатели. 
*Сложность в лучшем случае - О(1), в среднем - O(n), в худшем - O(n)*

### erase

`bool erase(T _data) // сигнатура функции`

Функция принимает объект пользовательского типа данных. Так как структура данных изначально отсортирована вычисляется разность между начальным блоком и элементом и конечным блоком и элементом. Производится проход по списку в прямом или обратном направлении в зависимостри от разницы, в поисках нужного блока. Когда место найдено удаляем блок и переопределяем указатели.  
*Сложность в лучшем случае - О(1), в среднем - O(n), в худшем - O(n)*


### search

`const bool search(T _data) // сигнатура функции`

Вычисляется разность между начальным блоком и элементом и конечным блоком и элементом. Производится проход по списку в прямом или обратном направлении в зависимостри от разницы. Если элемент найден - возвращается `true`, в ином случае - `false`  
*Сложность в лучшем случае - O(1), в среднем - О(n), в худшем - O(n)*

### operator []

`const T& operator[](size_t index) // сигнатура функции`

Производится проход в прямом или обратном направлении по аналогии с предыдущими функциями. Если индекс больше длины списка бросается исключение `std::invalid_argument("Too big to be true")`  
*Сложность - O(n)*.

### print

Функция вывода структуры данных. Данные выводятся по блокам и разделены ->. Пример - `1 -> 2 -> 3 -> 4 -> 5`

### Преимущества и недостатки

Основными преимуществами отсортированного списка являются:  
1. Кусочное хранение данных
2. Быстрая операция добавления и удаления

Недостатки:
1. Большой объем дополнительной памяти - O(n).
2. Долгий поиск элементов.

### Область применения

***

## Sorted expanded list

Структура данных представляет собой множество связанных между собой блоков, в каждом из которых хранится массив данных, указатель на следующий блок и указатель на предыдущий блок. Данные отсортированы в порядке следования блоков.  
Пользователь должен **сам** задать функцию-компаратор для данных, если он не сделал этого, по умолчанию используется *std::less*.  

### add

`void add(T _data) // сигнатура функции`

Функция принимает объект пользовательского типа данных. Проходом по списку вычисляется массив, в который нужно произвести вставку. Если в массиве есть место для вставки, то производится вставка в массив по аналогии с обычным отсортированным массивом. Если же места нет, то элемент сравнивается с первым элементом массива. Если первый больше, то создается новый блок, который ставится **перед** найденным и куда помещается исходный элемент. Если меньше, то создается новый блок, который ставится **после** найденного и куда помещается последний элемент найденного массива. Далее происходит вставка в найденный массив.
*Сложность в лучшем случае - О(1), в среднем - O(n/k + log2(k)), в худшем - O(n/k + log2(k)), где k - мощность каждого массива*

### erase

`bool erase(T _data) // сигнатура функции`

Функция принимает объект пользовательского типа данных. Находится массив, в котором может содержаться элемент. производится удаление из отсортированного массива. Если элемента там нет, возвращается `false`, в ином случае возвращается `true`. Если массив стал пустым, блок удаляется.  
*Сложность в лучшем случае - О(1), в среднем - O(n/k + log2(k)), в худшем - O(n/k + log2(k))*


### search

`const bool search(T _data) // сигнатура функции`

Находится массив, в котором может содержаться элемент. производится поиск в отсортированном массиве. Если элемент найден - возвращается `true`, в ином случае - `false`  
*Сложность в лучшем случае - O(1), в среднем - О(n/k + log2(k)), в худшем - O(n/k + log2(k))*

### operator []

`const T& operator[](size_t index) // сигнатура функции`

Находится массив, содержащий этот индекс(индекс считается общим для всех массивов). Если индекс больше длины списка бросается исключение `std::invalid_argument("Too big to be true")`  
*Сложность - O(n/k)*.

### print

Функция вывода структуры данных. Композиция предыдущих. Пример - `[1, 2] -> [2] -> [3] -> [4, 5] -> [6]`

### Преимущества и недостатки
По сути это объединение первой и второй структуры. Соответственно, преимущества и недостатки будут относительно других структур.  
Преимущества:  
1. Относительно быстрое добавление и удаление.
2. Кусочное хранение данных.
3. Поиск быстрее, чем в обычном списке, но медленнее, чем в массиве.

Недостатки:  
1. Большой объем дополнительной памяти - O(n/k).  


### Область применения

## Тестирование

1. В начале мы проводим тесты на добавление в структуру. Берем разное кол-во данных - n = 100, 1000, ... , 1000000. Для каждого n генерируем данные k = 100 раз и кидаем в программу. В итоге получаем какие-то данные для добавления. Ищем мат. ожидание, дисперсию и показываем, что данные похожи на мои зависимости.
2. Для каждого n проводим определенное количество операций поиска и удаления к уже заполненным структурам. Даем не только валидные данные.
3. Делаем сравнение и вывод.











