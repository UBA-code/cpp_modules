#include "PmergeMe.hpp"

template <typename T>
void    insertionSort(T &arr)
{
    for (int i = 0; i < (int)arr.size(); i++)
    {
        int current = arr[i];
        int prev = i - 1;
        for (; prev >= 0 && current < arr[prev]; prev--)
            std::swap(arr[prev], arr[prev + 1]);
    }
}
template <typename T>
void    merge(T &left, T &right, T &arr)
{
    int r = 0, l = 0, i = 0;
    for (; l < (int)left.size() && r < (int)right.size();i++)
    {
        if (left[l] < right[r])
        {
            arr[i] = left[l];
            l++;
        }
        else
        {
            arr[i] = right[r];
            r++;
        }
    }
    while (l < (int)left.size())
        arr[i++] = left[l++];
    while (r < (int)right.size())
        arr[i++] = right[r++];
}

template <typename T>
void    mergeSort(T &arr)
{
    if (arr.size() <= 1)
        return ;
    T left;
    T right;
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (i < (int)arr.size() / 2)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
}

template <typename T>
T	container_sort(T o, char **av)
{
	(void)o;
	T			vec;

    for (int i = 0; av[i]; i++)
        vec.push_back(atoi(av[i]));
    if (vec.size() <= 10)
        insertionSort(vec);
	else
		mergeSort(vec);
	return (vec);
}

void    pMergeMe(char **av)
{
	timeval	start, end;

	gettimeofday(&start, 0);
	std::vector<int> vec = container_sort(std::vector<int>(), av);
	gettimeofday(&end, 0);

	// * print before
	std::cout << "Before:\t";
	for (int i = 0; av[i]; i++)
		std::cout << av[i] << " ";
	std::cout << "\n";


	// * print after
	std::cout << "After:\t";
	for (int i = 0; i < (int)vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << "\n";

	std::cout << "Time to process a range of " <<  vec.size()\
	<< " elements with std::vector\t: " << ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec) << " us\n";
	gettimeofday(&start, 0);
	std::deque<int> deq = container_sort(std::deque<int>(), av);
	gettimeofday(&end, 0);
	std::cout << "Time to process a range of " <<  deq.size() << " elements with std::deque\t: "\
	<< ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec) << " us\n";
}
