/* An implementation of a max heap by Ekesh Kumar. */

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

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

int main()
{
int main()
{

	Heap my_heap;
	my_heap.heap_size = 5;
    my_heap.elements.push_back(1);
	my_heap.elements.push_back(2);
	my_heap.elements.push_back(3);
	my_heap.elements.push_back(4);
	my_heap.elements.push_back(5);
	my_heap.print_heap();
	my_heap.build_max_heap();
	my_heap.print_heap();
	my_heap.heapsort();
	my_heap.print_heap();
	return 0;
}
