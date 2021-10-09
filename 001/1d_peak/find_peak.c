#include <stdio.h>
#define MAX_SIZE 1000

void read_nums(int nums[], int* n) {
    scanf("%d", n);
    for(int i=0; i<(*n); ++i){
       scanf("%i", &nums[i]);
    }
}

int find_peak(const int nums[], const int n) {
    int begin = 0, end = n - 1, mid;
    int pred, succ;

    while(begin < end){
        mid = begin + (end - begin + 1)/2;
        pred = mid - 1;
        succ = mid + 1;
        if(nums[mid] >= nums[pred] && nums[mid] >= nums[succ]) {
            return mid;
        }
        if(nums[mid] < nums[pred]) {
            end = pred;
        } else {
            begin = succ;
        }
    }

    return begin;
}

void solve() {
    int nums[MAX_SIZE] = {0}, n, peak;
    int x;
    scanf("%d", &x);
    for (int i=0; i < x; ++i) {
        read_nums(nums, &n);
        peak = find_peak(nums, n);
        printf("peak is %d at %d\n", nums[peak], peak);
    }
}

int main() {
    solve();
}

