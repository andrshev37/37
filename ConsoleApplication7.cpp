// ConsoleApplication7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;
float Sn(float eps, float x) {
	int n = 0;
	float num;
	int f=1;
	do {
		
		if (n != 0) {
			f *= 2*n+1;
			num += pow(-1, n) * pow(x, 2 * n + 1) / f;
		}
		else
		{
			num = x;
		}
		n ++;
	} while (n < eps);
	return num;
}
int Nis(int n) {
	int p = 0;
	do {
		p++;
		n /= 10;

	} while (n != 0);
	return p;
}
int Pr(int n,int p) {
	int de, outn=1;
	while (n) {

		p--;
		de = pow(10, p);
		outn *= n / de;

		n %= de;

	}
	return outn;
}
int NPr(int n, int p) {
	int de, outn=0;
	while (n) {
		
		p--;
		de = pow(10, p);
		outn += n / de;
		
		n %= de;
	}
	return outn;
}
int Rec(int n)
{
	int answer;
	if (n == 0) return(1);
	else if (n == 1) return(2);
	answer = 2* Rec(n - 1) +4* Rec(n - 2) + 1;
	cout << answer << " ";
	return(answer);
}

int main()
{
//cout << "Eps\n";
	//int eps = 100000;
	float eps = 10;
	cout << "x:";
	float x;
	int n;
	cin >> x;
	cout << endl;
	cout << Sn(eps, x)<<endl;
	cout << "n:";
	cin >> n;
	int p = Nis(n);
	if (n % 2) {
		cout<<NPr(n, p);
	}
	else {
		cout << Pr(n, p);
	}
	cout << endl<<"n: ";
	cin >> n;
	cout << Rec(n);
}
