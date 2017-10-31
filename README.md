# Сравнение отсортированных массива, списка и развернутого списка


В данной работе приводится сравнение указанных выше структур данных.  Каждая из них имеет свои преимущества и недостатки, которые я покажу на практике, протестировав структуры.

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


### Add

`void add(T _data) // сингатура функции`

Функция принимает объект пользовательского типа данных. Так как структура данных изначально отсортирована, то применяется алгоритм бинарного поиска для определения места вставки нового элемента. [Бинарный поиск](https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D1%8B%D0%B9_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA).  
Если массив заполнен полностью, происходит расширение массива (коэффициент амортизации задается пользователем, если тот не указал - берется 1,5).  
Нужная часть массива сдвигается вправо и на позицию вставляется исходный элемент.  
Сложность в лучшем случае - О(1), в среднем - O(n).

### Erase

`bool erase(T _data) // сигнатура функции`

Функция принимает объект пользовательского типа данных. Так как структура данных изначально отсортирована, то применяется алгоритм бинарного поиска для определения места нахождения элемента. [Бинарный поиск](https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D1%8B%D0%B9_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA). 
Если такого элемента нет в массиве - функция вернет `false`. Если он есть - производится сдвиг нужной части массива и вернется `true`.  
Сложность в лучшем случае - О(1), в среднем - O(n).

### Search

`long int search(T _data) // сигнатура функции`

Применяется алгоритм бинарного поиска, если элемент нашелся в массиве, возвращается его индекс, если такого элемента нет возвращается `-1`.
Сложность - O(log2(n))

### operator []

`const T& operator[](size_t index) // сигнатура функции`

Возвращает константную ссылку на элемент массива по индексу, если индекс слишком велик, бросает исключение `std::invalid_argument("Too big to be true")`
Сложность - O(1).

### print

Функция вывода структуры данных. Данные выводятся внутри [ ] и разделены запятой. Пример - `[ 1, 2, 3, 4, 5]`






