#include <stdio.h>

#define SUB 10
#define MAIN 20

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int recursiveSum(int arr[], int size)
{
    if (size == 0)
        return 0;
    return arr[size - 1] + recursiveSum(arr, size - 1);
}

int main()
{
    int SubArray1[SUB] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int SubArray2[SUB] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int MainArray[MAIN];
    int mainSize = 0;

    int choice, value, pos, i, j, key, sum;

    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Reverse using another array\n");
        printf("4. Reverse without using another array\n");
        printf("5. Copy SubArray1 to MainArray\n");
        printf("6. Merge SubArray1 & SubArray2 (Descending)\n");
        printf("7. Sum (Iterative & Recursive)\n");
        printf("8. Search\n");
        printf("9. Separate Odd/Even\n");
        printf("10. Separate Positive/Negative\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &value);
            printf("1.Begin 2.End 3.Position: ");
            scanf("%d", &pos);

            if (pos == 1)
            {
                for (i = mainSize; i > 0; i--)
                    MainArray[i] = MainArray[i - 1];
                MainArray[0] = value;
                mainSize++;
            }
            else if (pos == 2)
            {
                MainArray[mainSize++] = value;
            }
            else
            {
                printf("Position: ");
                scanf("%d", &pos);
                for (i = mainSize; i > pos; i--)
                    MainArray[i] = MainArray[i - 1];
                MainArray[pos] = value;
                mainSize++;
            }
            display(MainArray, mainSize);
            break;

        case 2:
            printf("1.Begin 2.End 3.Position: ");
            scanf("%d", &pos);

            if (pos == 1)
            {
                for (i = 0; i < mainSize - 1; i++)
                    MainArray[i] = MainArray[i + 1];
                mainSize--;
            }
            else if (pos == 2)
            {
                mainSize--;
            }
            else
            {
                printf("Position: ");
                scanf("%d", &pos);
                for (i = pos; i < mainSize - 1; i++)
                    MainArray[i] = MainArray[i + 1];
                mainSize--;
            }
            display(MainArray, mainSize);
            break;

        case 3:
        {
            int temp[MAIN];
            for (i = 0; i < mainSize; i++)
                temp[i] = MainArray[mainSize - i - 1];
            for (i = 0; i < mainSize; i++)
                MainArray[i] = temp[i];
            display(MainArray, mainSize);
            break;
        }

        case 4:
            for (i = 0; i < mainSize / 2; i++)
            {
                int t = MainArray[i];
                MainArray[i] = MainArray[mainSize - i - 1];
                MainArray[mainSize - i - 1] = t;
            }
            display(MainArray, mainSize);
            break;

        case 5:
            for (i = 0; i < SUB; i++)
                MainArray[i] = SubArray1[i];
            mainSize = SUB;
            display(MainArray, mainSize);
            break;

        case 6:
        {
            i = SUB - 1;
            j = SUB - 1;
            int k = 0;
            while (i >= 0 && j >= 0)
                MainArray[k++] = (SubArray1[i] > SubArray2[j]) ? SubArray1[i--] : SubArray2[j--];
            while (i >= 0)
                MainArray[k++] = SubArray1[i--];
            while (j >= 0)
                MainArray[k++] = SubArray2[j--];
            mainSize = k;
            display(MainArray, mainSize);
            break;
        }

        case 7:
            sum = 0;
            for (i = 0; i < mainSize; i++)
                sum += MainArray[i];
            printf("Sum (Iterative): %d\n", sum);

            sum = 0;
            sum = recursiveSum(MainArray, mainSize);
            printf("Sum (Recursive): %d\n", sum);
            break;

        case 8:
            printf("Search value: ");
            scanf("%d", &key);
            for (i = 0; i < mainSize; i++)
            {
                if (MainArray[i] == key)
                {
                    printf("Found at index %d\n", i);
                    break;
                }
            }
            break;

        case 9:
            printf("Even: ");
            for (i = 0; i < mainSize; i++)
                if (MainArray[i] % 2 == 0)
                    printf("%d ", MainArray[i]);
            printf("\nOdd: ");
            for (i = 0; i < mainSize; i++)
                if (MainArray[i] % 2 != 0)
                    printf("%d ", MainArray[i]);
            printf("\n");
            break;

        case 10:
            printf("Positive: ");
            for (i = 0; i < mainSize; i++)
                if (MainArray[i] >= 0)
                    printf("%d ", MainArray[i]);
            printf("\nNegative: ");
            for (i = 0; i < mainSize; i++)
                if (MainArray[i] < 0)
                    printf("%d ", MainArray[i]);
            printf("\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
