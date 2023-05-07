#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<float.h>
// Definition of a point on the x-axis
struct Point {
  int x;
  int y;
};

// Function to calculate the distance between two points
float distance(struct Point p1, struct Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to compare two points based on their x-coordinates
int compareX(const void* a, const void* b) {
  struct Point* p1 = (struct Point*)a;
  struct Point* p2 = (struct Point*)b;
  return p1->x - p2->x;
}

// Function to compare two points based on their y-coordinates
int compareY(const void* a, const void* b) {
  struct Point* p1 = (struct Point*)a;
  struct Point* p2 = (struct Point*)b;
  return p1->y - p2->y;
}

// Function to find the closest pair of points on the x-axis using the divide and conquer algorithm
float closestPair(struct Point* points, int n) {
  if (n <= 3) {
    float minDist = FLT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        float dist = distance(points[i], points[j]);
        if (dist < minDist) {
          minDist = dist;
        }
      }
    }
    return minDist;
  }
  int mid = n / 2;
  struct Point midPoint = points[mid];
  float dl = closestPair(points, mid);
  float dr = closestPair(points + mid, n - mid);
  float d = fmin(dl, dr);
  struct Point strip[n];
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (abs(points[i].x - midPoint.x) < d) {
      strip[j++] = points[i];
    }
  }
  qsort(strip, j, sizeof(struct Point), compareY);
  float minDist = d;
  for (int i = 0; i < j; i++) {
    for (int k = i + 1; k < j && strip[k].y - strip[i].y < minDist; k++) {
      float dist = distance(strip[i], strip[k]);
      if (dist < minDist) {
        minDist = dist;
      }
    }
  }
  return minDist;
}

int main() {
  int n, i;
  printf("Enter the number of points: ");
  scanf("%d", &n);
  struct Point* points = (struct Point*)malloc(n * sizeof(struct Point));
  for (i = 0; i < n; i++) {
    printf("Enter the x-coordinate of point %d: ", i + 1);
    scanf("%d", &points[i].x);
    printf("Enter the y-coordinate of point %d: ", i + 1);
    scanf("%d", &points[i].y);
  }
  qsort(points, n, sizeof(struct Point), compareX);
  printf("The closest pair of points on the x-axis is %f\n", closestPair(points, n));
  free(points);
  return 0;
}
