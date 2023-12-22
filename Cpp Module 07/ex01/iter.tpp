#ifndef ITER_TPP
# define ITER_TPP

# include <iostream>

template <typename T, typename F>
void iter(T *array, int len, F f) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

#endif