/* An implementation of a Priority Queue by Ekesh Kumar. */

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

/* We will implement our Priority Queue with a Heap. */
typedef struct Heap
{
	vector<int> elements;
	int heap_size;

	/* A simple printing loop. Runs in O(n)*/
	void print_heap()
	{
		for (size_t i = 0; i != elements.size(); i++)
		{
			printf("%d ", elements.at(i));
		}
		printf("\n");
	}

	/* parent() returns the parent of the parameter node provided.
	   Bitwise operation gives more efficiency. Runtime: O(1) */
	int parent(int i)
	{
		return (i <= 0 ? -1 : floor((i - 1) >> 1));
	}

	/* left() returns the left child of a node. O(1). */
	int left(int i)
	{
		return (i < 0 ? -1 : ((i << 1) + 1));
	}

	/* right() returns the right child of a node. O(1). */
	int right(int i)
	{
		return (i < 0 ? -1 : ((i << 1) + 2));
	}

	/* heapify() assumes left(i) and right(i) are complete
	   binary trees, but heap(i) might be smaller than its
	   children, thus violating the max-heap property. This
	   function floats heap(i) downward to maintain the property.
	   Runtime: O(n log n) */
	void max_heapify(int i)
	{
		int l = left(i), r = right(i), largest = -1;

		if (l < heap_size && elements.at(l) > elements.at(i))
		{
			largest = l;
		}
		else
		{
			largest = i;
		}

		if (r < heap_size && elements.at(r) > elements.at(largest))
		{
			largest = r;
		}

		if (largest != i)
		{
			swap(elements.at(i), elements.at(largest));
			max_heapify(largest);
		}
	}

	/* build_max_heap() takes the vector elements, and turns it
	   into a max heap. This is done in O(n) time. */
	void build_max_heap()
	{
		/* In a complete binary tree, the leaf nodes are
		   at the indices floor(n/2), ..., n. So, this method
		   is optimized by skipping over non-leaf nodes. */
		for (int i = floor(elements.size() / 2) - 1; i >= 0; i--)
		{
			max_heapify(i);
		}
	}

	/* An O(n log n) sorting algorithm. Note that elements won't be a 
	   heap after calling this function. */
	void heapsort() {
		build_max_heap();
		for (int i = elements.size() - 1; i >= 1; i--) {
			swap(elements.at(0), elements.at(i));
			heap_size -= 1;
			max_heapify(0);
		}
	}

} Heap;

typedef struct PriorityQueue
{
	Heap heap; 
	
	/* Returns the maximum of the Priority Queue in O(1). */
	int get_max() {
		return heap.elements.at(0);
	}

	/* Returns and removes the maximum of the Priority Queue in O(log n) */
	int extract_max() {
		if (heap.elements.size() <= 0) {
			throw "Heap Underflow";
		} 
		int max = heap.elements.at(0);

	}
	
} PriorityQueue;

int main()
{

	PriorityQueue q;
}
