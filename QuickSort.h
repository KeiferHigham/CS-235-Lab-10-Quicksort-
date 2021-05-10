#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include "QSInterface.h"
#include <sstream>
#include <algorithm>

using namespace std;

template<typename T>
class QuickSort : public QSInterface<T> {

private:

    T* quickSort;
    size_t sortCapacity = 0;
    size_t frontIndex = 0;
    size_t rearIndex = numItems - 1;
    size_t numItems = 0;



public:

    QuickSort() {
     quickSort = NULL;
    }

    ~QuickSort() {

        delete [] quickSort;
    }
    /** Add an element to the QuickSort array. Dynamically grow array as needed. */
    bool addElement(T element){
        if(numItems >= sortCapacity - 1) {
            Reallocate();
        }

        quickSort[numItems] = element;
        numItems = numItems + 1;
        return true;
    }

    void Reallocate() {
        size_t newCapacity = sortCapacity * 2;
        T* newQuickSort = new T[newCapacity];

        for(size_t i = 0; i < sortCapacity; ++i) {
            newQuickSort[i] = quickSort[i];

        }

        sortCapacity = newCapacity;
       // swap(quickSort,newQuickSort);
       delete [] quickSort;
       quickSort = newQuickSort;
    }

    /** Sort the elements of a QuickSort subarray using median and partition functions. */
    bool sort(size_t left, size_t right){

        if (size() == 0) {
            return false;
        }
        if (left > sortCapacity - 1 || left < 0 || right > sortCapacity - 1 || right < 0) {
            return false;
        }
        if(left >= right) {
            return false;
        }
        if(right - left > 1) {
         int pivotIndex = medianOfThree(left, right);
         int pivot = partition(left, right, pivotIndex);
         if(pivot == -1) {
             return false;
         }
         sort(left, pivot);
         sort(pivot + 1, right);
     }
        return true;

    }

    /** Sort all elements of the QuickSort array using median and partition functions. */
    bool sortAll(){

        return sort(0, size());


    }

    /** Removes all items from the QuickSort array. */
    bool clear(){
       numItems = 0;

        return true;
    }

    /** Return size of the QuickSort array. */
    size_t capacity() const{
        return sortCapacity;
    }

    /** Return number of elements in the QuickSort array. */
    size_t size() const {
        return numItems;
    }

    /** The median of three pivot selection has two parts:
    1) Calculates the middle index by averaging the given left and right indices:
       middle = (left + right)/2
    2) Then bubble-sorts the values at the left, middle, and right indices.

    After this method is called, data[left] <= data[middle] <= data[right].

    @param left - the left boundary for the subarray from which to find a pivot
    @param right - the right + 1 boundary for the subarray from which to find a pivot
    @return the index of the pivot (middle index).
    Return -1 if  1) the array is empty,
                  2) if either of the given integers is out of bounds,
                  3) or if the left index is not less than the right index.
    */
    int medianOfThree(size_t left, size_t right) {
        if (size() == 0) {
            return -1;
        }
        if (left > sortCapacity - 1 || left < 0 || right > sortCapacity - 1 || right < 0) {
            return -1;
        }
        if(left >= right) {
            return -1;
        }
        int middleIndex = (left + right) / 2;
        size_t tempVal;

        if(quickSort[middleIndex] < quickSort[left]) {
            tempVal = quickSort[middleIndex];
            quickSort[middleIndex] = quickSort[left];
            quickSort[left] = tempVal;
        }
        if(quickSort[right - 1] < quickSort[middleIndex]) {
            tempVal = quickSort[right - 1];
            quickSort[right - 1] = quickSort[middleIndex];
            quickSort[middleIndex] = tempVal;
        }
        if(quickSort[middleIndex] < quickSort[left]) {
            tempVal = quickSort[middleIndex];
            quickSort[middleIndex] = quickSort[left];
            quickSort[left] = tempVal;
        }
     return middleIndex;

    }

    /** Partitions a subarray around a pivot value selected according
    to median-of-three pivot selection. Because there are multiple ways
    to partition a list, follow the algorithm on page 611.

    The values less than or equal to the pivot should be placed to the left of the pivot;
    the values greater than the pivot should be placed to the right of the pivot.

    @param left - left index for the subarray to partition.
    @param right - right index + 1 for the subarray to partition.
    @param pivotIndex - index of the pivot in the subarray.
    @return the pivot's ending index after the partition completes:
    Return -1 if  1) the array is empty,
                  2) if any of the given indexes are out of bounds,
                  3) if the left index is not less than the right index.
    */
    int partition(size_t left, size_t right, size_t pivotIndex) {

        if (numItems == 0) {
            return -1;
        }
        if (left > sortCapacity - 1 || left < 0 || right > sortCapacity - 1 || right < 0) {
            return -1;
        }
        if(left >= right) {
            return -1;
        }
        if(pivotIndex > right - 1) {
            return -1;
        }
        if(pivotIndex < left) {
            return -1;
        }
        swap(quickSort[left], quickSort[pivotIndex]);
        size_t up = left + 1;
        size_t down = right - 1;

        do {
            while(quickSort[up] <= quickSort[left] && up != (right - 1)) {
                ++up;
            }

            while(quickSort[down] > quickSort[left] && down != left) {
                --down;
            }
            if(up < down) {
                swap(quickSort[up], quickSort[down]);
            }
        }while(up < down);

        swap(quickSort[left], quickSort[down]);

        return down;

    }

    /** @return: comma delimited string representation of the array. */
    string toString() const {
        stringstream out;

        for(size_t i = 0; i < size(); ++i) {
            out << quickSort[i] << ",";
        }


        string output = out.str();
        output.pop_back();
        return output;
    }

    void SetQuickSort(int quickSortCapacity = 0) {
       if(quickSort != NULL) {
          delete [] quickSort;
        }
        quickSort = new T[quickSortCapacity];
        sortCapacity = quickSortCapacity;
        numItems = 0;
    }










};

#endif //QUICKSORT_QUICKSORT_H
