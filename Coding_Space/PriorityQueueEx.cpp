// C++ program to demonstrate
// min heap for priority queue
#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue<int, vector<int>, greater<int> > gq)
{
	priority_queue<int, vector<int>, greater<int> > g = gq;

	while (!g.empty()) 
    {
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

void showArray(int* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// Driver Code
int main()
{
	int arr[8] = { 11, 10, 2, 4, 8, 6, 9, 5 };
	priority_queue<int, vector<int>, greater<int> > gquiz(arr, arr + 7);

	cout << "Array: " << endl << endl;
	showArray(arr, 8);

	cout << "Priority Queue : ";
	showpq(gquiz);

	return 0;
}
