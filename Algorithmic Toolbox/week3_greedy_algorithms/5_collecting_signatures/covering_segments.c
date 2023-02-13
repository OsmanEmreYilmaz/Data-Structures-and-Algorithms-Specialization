#include <stdio.h>
#include <stdlib.h>

struct Segment {
    int start;
    int end;
};

int cmp(const void *a, const void *b) {
    struct Segment *s1 = (struct Segment *)a;
    struct Segment *s2 = (struct Segment *)b;
    return s1->end - s2->end;
}

int* optimal_points(int n, struct Segment segments[]) {
    int* points = (int*)malloc(n * sizeof(int));
    int cnt = 0;
    qsort(segments, n, sizeof(struct Segment), cmp);
    int max_end = segments[0].end;
    points[cnt++] = max_end;
    for (int i = 1; i < n; i++) {
        if (max_end < segments[i].start) {
            max_end = segments[i].end;
            points[cnt++] = max_end;
        }
    }
    *points = cnt;
    return points;
}

int main() {
    int n, i;
    scanf("%d", &n);
    struct Segment segments[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d", &segments[i].start, &segments[i].end);
    }
    int* points = optimal_points(n, segments);
    printf("%d\n", *points);
    for (i = 1; i <= *points; i++) {
        printf("%d ", points[i]);
    }
    free(points);
    return 0;
}
