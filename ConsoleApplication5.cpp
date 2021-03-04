// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    cout << "n: ";
    int n;

    cin >> n;
    while (n>0) {
        int i = n;
        while(i>0) {
            cout << i<<" ";
            i--;
        }
        cout << endl;
        n--;
    }
    cout << "enter 5 numbs: ";
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    n = 5;
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    int arr[n];
    int max, min;
    while (n){
        cin >> arr[n];
        n--;
    }
    max = min = arr[0];
    for (int i; i <= n; i++) {
        if (max > arr[i]){
            max = arr[i];
        }
        if (min < arr[i]) {
            min = arr[i];
        }
    }
    cout << endl;
    cout << min + max;
}

