#include "PmergeMe.hpp"

template <typename T>
void insertionSort(T &arr)
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
void merge(T &left, T &right, T &arr)
{
	int r = 0, l = 0, i = 0;
	for (; l < (int)left.size() && r < (int)right.size(); i++)
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
void mergeSort(T &arr)
{
	if (arr.size() <= 10)
	{
		insertionSort(arr);
		return ;
	}
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
T container_sort(char **av)
{
	T vec;

	for (int i = 0; av[i]; i++)
		vec.push_back(atoi(av[i]));
	mergeSort(vec);
	return (vec);
}

void pMergeMe(char **av, int container)
{
	std::clock_t start, end;
	int		i;
	if (container == VECTOR)
	{

		start = clock();
		parse(av);
		std::vector<int> vec = container_sort<std::vector<int> >(av);
		end = clock();

		// * print before
		std::cout << "Before:\t";
		for (i = 0; av[i] && i < 10; i++)
			std::cout << av[i] << " ";
		if (av[i] && i == 10)
			std::cout << "[...]";
		std::cout << "\n";

		// * print after
		std::cout << "After:\t";
		for (int i = 0; i < (int)vec.size() && i < 10; i++)
			std::cout << vec[i] << " ";
		if (vec.size() > 10)
			std::cout << "[...]";
		std::cout << "\n";
		double time = ((((double)(end) / CLOCKS_PER_SEC) - ((double)(start) / CLOCKS_PER_SEC)) * 1000000);
		std::cout << std::fixed << std::setprecision(2) << "Time to process a range of " << vec.size()
					<< " elements with std::vector:\t" << std::setprecision(2) << time << " us\n";
	}

	else if (container == DEQUE)
	{
		// ? test 2
		start = clock();
		parse(av);
		std::deque<int> deq = container_sort<std::deque<int> >(av);
		end = clock();
		double time = ((((double)(end) / CLOCKS_PER_SEC) - ((double)(start) / CLOCKS_PER_SEC)) * 1000000);
		std::cout << std::fixed << std::setprecision(2) << "Time to process a range of " << deq.size()
					<< " elements with std::deque:\t" << time << " us\n";
	}
}
