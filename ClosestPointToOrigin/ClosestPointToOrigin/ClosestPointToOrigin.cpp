#include <iostream>
#include <queue>

using namespace std;

class Comp
{
public:
	bool operator()(std::pair<int, int>_a, std::pair<int, int>_b)
	{
		const int x1 = _a.first * _a.first;
		const int y1 = _a.second * _a.second;
		const int x2 = _b.first * _b.first;
		const int y2 = _b.second * _b.second;

		return (x1 + y1) > (x2 + y2);
	}
};



void kClosestPoints(int x[], int y[],int n, int k)
{
	std::priority_queue<pair<int, int>, std::vector<pair<int, int> >, Comp > pq;
	for (size_t i = 0; i < n; i++)
		pq.push(make_pair(x[i], y[i]));

	for (int i = 0; i < k; i++) {

		// Store the top of the queue
		// in a temporary pair
		pair<int, int> p = pq.top();

		// Print the first (x)
		// and second (y) of pair
		cout << p.first << " "
			<< p.second << endl;

		// Remove top element
		// of priority queue
		pq.pop();
	}
}

int main()
{
	int x[] = { 1, -2 };


	// y coordinate of points
	int y[] = { 3, 2 };
	int K = 1;

	int n = sizeof(x) / sizeof(x[0]);

	kClosestPoints(x, y, n, K);

	return 0;
}

