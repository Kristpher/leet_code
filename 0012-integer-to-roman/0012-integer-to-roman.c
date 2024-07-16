char* intToRoman(int num) {
    char* new1 = (char*)malloc(1001 * sizeof(char)); 
    char hash[1001];
    hash[1] = 'I';
    hash[5] = 'V';
    hash[10] = 'X';
    hash[50] = 'L';
    hash[100] = 'C';
    hash[500] = 'D';
    hash[1000] = 'M';
    int s = 6;
    int check = num;
    int i = 0;
    while (check != 0) {
        check = check / 10;
        i++;
    }

    i--;
    int k = 0;
    int arr[7] = {1, 5, 10, 50, 100, 500, 1000};
    while (num < arr[s]) {
        s--;
    }
    while (num != 0) {
        int exp = pow(10, i);
        if (num >= arr[s]) {
            int sum = 0;
            int dig = num / exp;
            if (dig != 9 && dig != 4) {
                sum = arr[s];
                new1[k++] = hash[arr[s]];
                while (sum != dig * exp) {
                    if (sum + arr[s] > dig * exp) {
                        sum = sum + arr[s - 1];
                        new1[k++] = hash[arr[s - 1]];

                    } else {
                        sum += arr[s];
                        new1[k++] = hash[arr[s]];
                    }
                }
            } else {
                int n = dig * exp;
                if (dig == 4) {
                    new1[k++] = hash[arr[s]];
                    new1[k++] = hash[arr[s + 1]];

                } else if (dig == 9) {
                    new1[k++] = hash[arr[s - 1]];
                    new1[k++] = hash[arr[s + 1]];
                }
            }
            num = num % exp;
            s--;
            i--;
        } else{
            s--;
           if(arr[s]<pow(10,i))
      i--;
        }
    }
    new1[k] = '\0';
    return new1;
}