#include <stdio.h>
#define MAX_SIZE 100

void read_matrix(int nums[][MAX_SIZE], const int x, const int y) {
    int i, j;
    for(i=0; i<y; ++i){
        for(j=0; j<x; ++j){
            scanf("%d", &nums[i][j]);
        }
    }
}

int max(int nums[], const int n) {
    int i_max = 0;
    for(int i=0; i< n; ++i){
        if(nums[i_max] < nums[i]) {
            i_max = i;
        }
    }
    return i_max;
}

void find_peak(int nums[][MAX_SIZE], const int x, const int y, int* p_x, int* p_y) {
    int begin = 0, end = y - 1, mid;
    int nmax, imax, pred, succ;
    while(begin < end) {
        mid = (begin + end) / 2;
        imax = max(nums[mid], x);
        nmax = nums[mid][imax];
        pred = nums[mid-1][imax];
        succ = nums[mid+1][imax];
        if(nmax >= pred && nmax >= succ) {
            *p_x = imax;
            *p_y = mid;
            return;
        }
        if(pred > nmax) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    *p_x = max(nums[begin], x);
    *p_y = begin;
}

void print_result(int num, int x, int y) {
    printf("peak is %d ", num);
    printf("at (%d, %d)\n", x, y);
}

void solve(int nums[][MAX_SIZE]) {
    int x, y, peak_x, peak_y;
    scanf("%d %d", &x, &y);
    read_matrix(nums, x, y);
    find_peak(nums, x, y, &peak_x, &peak_y);
    print_result(nums[peak_y][peak_x], peak_y, peak_x);
}

int main() {
    int n, i;
    int nums[MAX_SIZE][MAX_SIZE];
    scanf("%d", &n);
    for(i=0; i<n; ++i){
        solve(nums);
    }
}

