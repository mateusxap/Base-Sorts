#include <stdio.h>
#include <time.h>
#define MAX  1000000

int bubble_sort(int arr[], int size);
int linear_sort(int arr[], int size);
int insertion_sort(int arr[], int size);
int bin_search(int elem, int arr[], int size);
int barrier_search(int elem, int arr[], int size);
int linear_search(int elem, int arr[], int size);
int bubble_sort2(int arr[], int size);

int arr[MAX], arrCopy[MAX];

int main() {
    setlocale(0, "");
    srand();
    clock_t start, end;
    double timeOfLinearS = -1, timeOfBubbleS = -1, timeOfInsertionS = -1, timeOfBubbleS2 = -1;
    int answer, flagInput = 0, flagSort = 0, size, element, elementSearch, indexElementS, countOpLinearS = 0, countOpBubbleS = 0, countOpInsertionS = 0, countOpBubbleS2 = 0;
    do //меню
    {
        printf("1. Ввод массива\n");
        printf("2. Линейная сортировка\n");
        printf("3. Сортировка пузырьком\n");
        printf("4. Сортировка вставкой\n");
        printf("5. Бинарный поиск\n");
        printf("6. Линейный поиск\n");
        printf("7. Поиск с барьером\n");
        printf("8. Сравнение сортировок\n");
        printf("9. Сортировка пузырьком из интернета\n");
        printf("10. Вывод массива\n");

        printf("\"0\" - символ выхода из меню\n");
        scanf_s("%d", &answer); // при числах 1.5 ошибка

        switch (answer)
        {
        case 1: //input massive
            timeOfLinearS = timeOfBubbleS = timeOfInsertionS = timeOfBubbleS2 = -1;
            flagInput = flagSort = countOpLinearS = countOpBubbleS = countOpInsertionS = countOpBubbleS2 = 0;
            do
            {
                printf("Введите размер массива: ");
                scanf_s("%d", &size);
            } while (size < 0);

            if (size <= 20)
            {
                for (int i = 0; i < size; i++)
                {
                    printf("Введите %d-й элемент: ", i + 1);
                    scanf_s("%d", &element);
                    arr[i] = element;
                    arrCopy[i] = arr[i];

                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    arr[i] = rand();
                    arrCopy[i] = arr[i];
                }
            }
            printf("\n\n");
            flagInput = 1;
            system("cls");
            break;

        case 2: //линейная
            system("cls");
            if (flagInput == 1)
            {
                for (int i = 0; i < size; i++)
                    arr[i] = arrCopy[i];
                start = clock();
                countOpLinearS = linear_sort(arr, size);
                end = clock();
                timeOfLinearS = ((double)end - start) / ((double)CLOCKS_PER_SEC);
                flagSort = 1;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");
            break;


        case 3: //bubble
            system("cls");
            if (flagInput == 1)
            {
                for (int i = 0; i < size; i++)
                    arr[i] = arrCopy[i];
                start = clock();
                countOpBubbleS = bubble_sort(arr, size);
                end = clock();
                timeOfBubbleS = ((double)end - start) / ((double)CLOCKS_PER_SEC);
                flagSort = 1;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");
            break;


        case 4: //insertion
            system("cls");
            if (flagInput == 1)
            {
                for (int i = 0; i < size; i++)
                    arr[i] = arrCopy[i];
                start = clock();
                countOpInsertionS = insertion_sort(arr, size);
                end = clock();
                timeOfInsertionS = ((double)end - start) / ((double)CLOCKS_PER_SEC);
                flagSort = 1;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");
            break;


        case 5:// bin
            system("cls");
            if (flagSort == 1)
            {
                printf("Введите искомый элемент: ");
                scanf_s("%d", &elementSearch);
                indexElementS = bin_search(elementSearch, arr, size);
                if (indexElementS > -1)
                    printf("Элемент в массиве, его индекс: %d\n\n", indexElementS);
                else
                    printf("Элемента нет в массиве\n\n");
            }
            else
                printf("Для бинарного поиска нужна сортировка\n\n");
            break;


        case 6: //linear search
            system("cls");
            if (flagInput == 1)
            {
                printf("Введите искомый элемент: ");
                scanf_s("%d", &elementSearch);
                indexElementS = linear_search(elementSearch, arr, size);
                if (indexElementS > -1)
                    printf("Элемент в массиве, его индекс: %d\n\n", indexElementS);
                else
                    printf("Элемента нет в массиве\n\n");
                break;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");




        case 7: // barrier
            system("cls");
            if (flagInput == 1)
            {
                printf("Введите искомый элемент: ");
                scanf_s("%d", &elementSearch);
                indexElementS = barrier_search(elementSearch, arr, size);
                if (indexElementS > -1)
                    printf("Элемент в массиве, его индекс: %d\n\n", indexElementS);
                else
                    printf("Элемента нет в массиве\n\n");
                break;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");



        case 8://comparison
            system("cls");
            if (flagInput == 1)
            {
                printf("                              Время                      Количесвто операций\n");
                if (timeOfLinearS == -1)
                    printf("Линейная сортиовка            Время не засекалось        %d\n", countOpLinearS);
                else
                    printf("Линейная сортиовка            %lfc                       %d\n", timeOfLinearS, countOpLinearS);
                if (timeOfBubbleS == -1)
                    printf("Сортировка пузырьком          Время не засекалось        %d\n", countOpBubbleS);
                else
                    printf("Сортировка пузырьком          %lfc                       %d\n", timeOfBubbleS, countOpBubbleS);
                if (timeOfInsertionS == -1)
                    printf("Сортировка вставкой           Время не засекалось        %d\n", countOpInsertionS);
                else
                    printf("Сортировка вставкой           %lfc                       %d\n", timeOfInsertionS, countOpInsertionS);
                if (timeOfBubbleS2 == -1)
                    printf("Сортировка пузырьком 2        Время не засекалось        %d\n", countOpBubbleS2);
                else
                    printf("Сортировка пузырьком 2        %lfc                       %d\n", timeOfBubbleS2, countOpBubbleS2);
                printf("\n\n");
                break;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");

        case 9:
            system("cls");
            if (flagInput == 1)
            {
                start = clock();
                countOpBubbleS2 = bubble_sort2(arr, size);
                end = clock();
                timeOfBubbleS2 = ((double)end - start) / ((double)CLOCKS_PER_SEC);
                flagSort = 1;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");
            break;

        case 10:
            system("cls");
            if (flagInput == 1)
            {
                //comparison
                for (int i = 0; i < size; i++)
                    printf("%d  ", arr[i]);
                printf("\n\n");
                break;
            }
            else
                printf("Сначала нужно выполнить заполнение массива\n\n");

        default:
            printf("Нет такого пункта\n");
            break;
        }

    } while (answer != 0);



    return 0;
}



int bubble_sort(int arr[], int size) {
    int temp, countOfPerm = 0, countOfOp = 0, k = 0;
    countOfOp += 3;
    do
    {
        countOfPerm = 0;
        countOfOp += 1;
        for (int j = 0; j < size - k - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                countOfPerm++;
                countOfOp += 6;
            }
            countOfOp += 1;
        }
        k++;
        countOfOp += 1;
    } while (countOfPerm > 0);
    return countOfOp;
}


int linear_sort(int arr[], int size) {
    int indexMin, start = 1, temp, countOfOp = 0;
    countOfOp += 2;
    for (start; start < size; start++) //заводим цикл с того места, где стоит неотсортированный элемент
    {
        indexMin = start - 1;
        countOfOp += 2;
        for (int startt = start; startt < size; startt++)
        {
            if (arr[indexMin] > arr[startt])
            {
                indexMin = startt;
                countOfOp += 1;
            }
            countOfOp += 1;
        }
        temp = arr[start - 1];//предыдущий элемент
        arr[start - 1] = arr[indexMin];
        arr[indexMin] = temp; //меняем местами элементы
        countOfOp += 7;
    }
    return countOfOp;
}


int insertion_sort(int arr[], int size) {
    int temp, indexFirstRem = 1, i, k, countOfOp = 0; //индекс первого элемента из остатка, т.е. граница между итогом и остатком
    countOfOp += 2;
    while (indexFirstRem + 1 <= size) //работает, пока индекс первого элемента из остатка не совпадет с последним элементом массива
    {
        i = indexFirstRem;
        k = i + 1;
        temp = arr[indexFirstRem];
        countOfOp += 4;

        for (i; i > 0; i--)
        {
            if (temp < arr[i - 1])
            {
                arr[i] = arr[i - 1];
                k = i;
                countOfOp += 3;
            }
            countOfOp += 1;
        }
        arr[k - 1] = temp;
        indexFirstRem++;
        countOfOp += 2;
    }
    return countOfOp;
}

int bin_search(int elem, int arr[], int size) {
    int min = 0, mid, max = size - 1;
    while (min <= max)
    {
        mid = (max + min) / 2;
        if (elem > arr[mid])
            min = mid + 1;
        else if (elem < arr[mid])
            max = mid - 1;
        else if (elem == arr[mid])
            return mid;

    }
    return -1;
}

int barrier_search(int elem, int arr[], int size) {
    int i = 0, res = -1; double tmp;
    tmp = arr[size - 1];
    arr[size - 1] = elem;
    while (arr[i] != elem)
        i++;
    arr[size - 1] = tmp;
    if ((i < size - 1) || (tmp == elem))
        res = i;
    return res;
}

int linear_search(int elem, int arr[], int size) {
    int i = 0, index = -1;
    for (i; i < size; i++)
    {
        if (elem == arr[i])
        {
            index = i;
            break;
        }
    }
    return index;
}
int bubble_sort2(int arr[], int size)
{
    int temp, countOfOp = 0;
    countOfOp += 1;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                countOfOp += 5;
            }
            countOfOp += 1;
        }
        countOfOp += 1;
    }
    return countOfOp;
}
