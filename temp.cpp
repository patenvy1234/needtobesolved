#include <bits/stdc++.h>
//4 type of sorts are done here


using namespace std;

void selection_sort(int *array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini_index = i;
        int mini_value = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (array[j] < mini_value)
            {
                mini_value = array[j];
                mini_index = j;
            }
        }
        swap(array[mini_index], array[i]);
    }
}

void bubble_sort(int *array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void insertion_sort(int *array, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = array[i];
        while (j >= 0)
        {
            if (array[j] > temp)
            {
                array[j + 1] = array[j];
            }
            else
            {
                break;
            }

            j--;
        }
        array[j + 1] = temp;
    }
}

int partition (int *array, int s, int e)
{
    int pivot = array[s];
    int cnt=0;
    for (int j=s+1 ; j<=e ; j++)
    {
        if (array[j]<= pivot)
        {
            cnt++;
        }
    }


    int index= s+cnt;
    swap(array[index] , array[s]);

    int i=s, j=e;

    while(i<index && j>index)
    {
        while (array[i] <= array[index])
        {
            i++;
        }
        while (array[j]>array[index])
        {
            j--;
        }
        if (i<index && j>index)
        {
            swap(array[i++] , array[j--]);
        }
    }
    return index;

}

void quick_sort(int *array, int s, int e)
{
    if (s>=e)
    {
        return ;
    }

    int p = partition(array,s,e);

    quick_sort(array, s, p-1);
    quick_sort(array, p+1, e);


}

int main()
{
    int array[17] = {2, 5, 7, 4, 3, 1, 9, 8, 6, 7, 11, 4, 6, 9, 2, 1, 72};
    int n = 17;
    // selection_sort(array, n);
    // bubble_sort(array,n);
    //insertion_sort(array, n);
    quick_sort(array, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
