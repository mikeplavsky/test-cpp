#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>
 
template <class T>
 void quicksort(T first, T last)
 {

    if(first == last) {
        return;
    }

    auto pivot = *first;

    auto before_pivot = std::partition(
        first, 
        last, 
        [pivot](const auto& em){return em < pivot;});

    auto after_pivot = std::partition(
        before_pivot, 
        last, 
        [pivot](const auto& em){return em == pivot;});

    quicksort(first, before_pivot);
    quicksort(after_pivot, last);

 }
 
int main()
{
    std::forward_list fl = {
        1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};

    quicksort(std::begin(fl), std::end(fl));

    std::cout << "Sorted using quicksort:\n    ";
    for(int fi : fl) std::cout << fi << ' ';

    std::cout << '\n';
}
