#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 1 && heap[index] > heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index = index / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size() - 1;

        while (2 * index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = left;

            if (right <= size && heap[right] > heap[left]) {
                largest = right;
            }

            if (heap[index] < heap[largest]) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap() {
        heap.push_back(-1); // dummy value at index 0
    }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void remove() {
        if (heap.size() <= 1) return;

        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
    }

    int top() {
        return heap[1];
    }

    void print() {
        for (int i = 1; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};