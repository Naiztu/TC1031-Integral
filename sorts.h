#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>

//
// sorts.h
//
//  Created on: 01/09/2021
//      Author: Angel Rico
//

template <class T>
class Sorts{
	private:
		void copyArray(std::vector<T>&, std::vector<T>&, int, int);
		void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
		void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
		void swap(std::vector<T>&, int, int);
	public:
		Sorts(){}
		void ordenaMerge(std::vector<T> v){
			std::vector<T> aux(v.size());
			mergeSplit(v,aux, 0, v.size() - 1);}
		
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) A[i] = B[i];
}
template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i].numPrioridad < A[j].numPrioridad) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}
template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

#endif