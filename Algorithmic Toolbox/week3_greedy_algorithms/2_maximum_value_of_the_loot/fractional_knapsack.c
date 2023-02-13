#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

double get_optimal_value(int capacity, int* weights, int* values, int n) {
    
	double value = 0.0;
    int location[n];
    double d[n];
    for(int i = 0; i < n; i++) {
        location[i] = i;
        d[i] = (double) values[i] / weights[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(d[j] > d[i]) {
                double temp = d[i];
                d[i] = d[j];
                d[j] = temp;
                int temp2 = location[i];
                location[i] = location[j];
                location[j] = temp2;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(capacity == 0) {
            return value;
        }
        int a = min(capacity, weights[location[i]]);
        value += a * d[i];
        capacity -= a;
    }

    return value;
}

int main() {
    int capacity, n;
    scanf("%d%d", &capacity, &n);
    int weights[n], values[n];
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &weights[i], &values[i]);
    }
    double optimal_value = get_optimal_value(capacity, weights, values, n);
    printf("%.4f", optimal_value);
    return 0;
}
