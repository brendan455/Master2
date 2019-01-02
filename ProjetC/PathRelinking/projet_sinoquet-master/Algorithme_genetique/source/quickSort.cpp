#include<stdio.h>
#include <vector>
#include "quickSort.hpp"


void swap(double* a, double* b) {
  double t = *a;
  *a = *b;
  *b = t;
}

int partition (vector<vector<double>>& population_tab, int low, int high){
    double pivot = population_tab[high][3];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (population_tab[j][3] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&population_tab[i][3], &population_tab[j][3]);
            swap(&population_tab[i][2], &population_tab[j][2]);
            swap(&population_tab[i][1], &population_tab[j][1]);
            swap(&population_tab[i][0], &population_tab[j][0]);
            swap(&population_tab[i][4], &population_tab[j][4]);
        }
    }
    swap(&population_tab[i + 1][3], &population_tab[high][3]);
    swap(&population_tab[i + 1][2], &population_tab[high][2]);
    swap(&population_tab[i + 1][1], &population_tab[high][1]);
    swap(&population_tab[i + 1][0], &population_tab[high][0]);
    swap(&population_tab[i + 1][4], &population_tab[high][4]);
    return (i + 1);
}

void quickSort(vector<vector<double>>& population_tab, int low, int high){
    if (low < high)
    {
        int pi = partition(population_tab, low, high);
        quickSort(population_tab, low, pi - 1);
        quickSort(population_tab, pi + 1, high);
    }
}
