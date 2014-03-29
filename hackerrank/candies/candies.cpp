// Author: Krzysztof Bochenek
// Email:  krzychusan@gmail.com
// --------------------------------
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <string>
#include <iostream>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

int child_rating[100000];
int candies_needed_left[100000];
int candies_needed_right[100000];

int main() {
    int size;

    scanf("%d", &size);
    for (int i=0; i<size; ++i) {
        scanf("%d", &child_rating[i]);
        candies_needed_left[i] = 1;
        candies_needed_right[i] = 1;
    }

    for (int i=1; i<size; ++i) {
        if (child_rating[i-1] < child_rating[i])
            candies_needed_left[i] = candies_needed_left[i-1] + 1;
    }

    for (int i=size-2; i>=0; --i) {
        if (child_rating[i] > child_rating[i+1])
            candies_needed_right[i] = candies_needed_right[i+1] + 1;
    }

    int total_needed_candies = 0;
    for (int i=0; i<size; ++i)
        total_needed_candies += std::max(candies_needed_left[i], candies_needed_right[i]);

    printf("%d\n", total_needed_candies);

    return 0;
};
