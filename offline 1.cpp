#include <iostream>
using namespace std;

int A[100];
int heap_size = 0;

void max_heapify(int i) {
	int l = 2 * i;
	int r = 2 * i + 1;
	int largest = i;
	if (l<=heap_size && A[l]>A[i]) largest = l;
	if (r <= heap_size && A[r] > A[largest]) largest = r;
	if (largest != i) {
		int t = A[i];
		A[i] = A[largest];
		A[largest] = t;
		max_heapify(largest);
	}
}

void build_max_heap() {
	for (int i = heap_size / 2; i >= 1; i--) max_heapify(i);
}

int heap_extract_max() {
	int max = A[1];
	A[1] = A[heap_size];
	heap_size--;
	max_heapify(1);
	return max;
}


int main() {
	int n;
	int t=0;
	int v;
	cin >> n;
	heap_size = n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	build_max_heap();
	cin >> v;
	while (v != 0) {
		int c = heap_extract_max();
		if (c <= v) {
			int b = v / c;
			cout << c << ":" << b << endl;
			t += b;
			v %= c;

		}
	}
	cout << "total:" << t << endl;

}
