//
// Created by misha on 16.03.2023.
//
void swap(char *array, int i, int j) {
    char temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quick_sort(char *array, int left, int right) {
    int i, last;
    if (left >= right)
        return;
    swap(array, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (array[i] < array[left])
            swap(array, ++last, i);
    }
    swap(array, left, last);
    quick_sort(array, left, last - 1);
    quick_sort(array, last + 1, right);
}

int binary_search(char x, char array[], int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (array[mid] == x) {
        return mid;
    } else if (x < array[mid]) {
        binary_search(x, array, left, mid - 1);
    } else {
        binary_search(x, array, mid + 1, right);
    }
}