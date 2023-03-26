// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int otv = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        otv++;
      }
    }
  }
  return otv;
}
int countPairs2(int *arr, int len, int value) {
  int otv = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        otv++;
      }
    }
  }
  return otv;
}
int countPairs3(int *arr, int len, int value) {
  int otv = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len;
    while (right > left + 1) {
      int middle = (right + left) / 2;
      if (value < arr[i] + arr[middle]) {
        right = middle;
      } else if (value > arr[i] + arr[middle]) {
        left = middle;
      } else {
        otv++;
        int ciclo = middle + 1;
        while (ciclo < right && arr[i] + arr[ciclo] == value) {
          otv++;
          ciclo++;
        }
        ciclo = middle - 1;
        while (ciclo > left && arr[i] + arr[ciclo] == value) {
          otv++;
          ciclo--;
        }
        break;
      }
    }
  }
  return otv;
}
