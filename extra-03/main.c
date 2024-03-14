int strongPasswordChecker(char* password) {
    int count = 0, up = 0, digit = 0, low = 0, repeat = 0;
    int len = strlen(password);

    if (len < 6) {
        count = 6 - len;
    }
    else {
        if (len > 20) {
            count = len - 19;
            len = 20;
        }

        for (int i = 0; i < len; ++i) {
            if (i >= 2 && i <= len && password[i] == password[i - 1] && password[i - 1] == password[i - 2]) {
                ++repeat;
                password[i] = '*';
            }
            if (isupper(password[i]))
                low = 1;
            else if (islower(password[i]))
                up = 1;
            else if (isdigit(password[i]))
                digit = 1;
        }
    }



    if (repeat != 0 && (up == 0 || low == 0 || digit == 0))
        count += repeat;

    return count;
}


int balancedStringSplit(char* s) {
    int count = 0, balance = 0;

    for (int i = 0; i<strlen(s); i++) {
        if (s[i] == 'R')
            balance++;
        else
            balance--;


        if (balance == 0)
            count++;
    }

    return count;
}