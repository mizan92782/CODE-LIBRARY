int reverse(int x) {
    int num = 0;

    while (x != 0) {
        // Check for potential overflow
        if (num > INT_MAX / 10 || num < INT_MIN / 10) {
            return 0; // Overflow detected
        }
        
        num = num * 10 + x % 10;
        x /= 10;
    }

    return num;
}


//https://chat.openai.com/share/71c215c3-3d04-4976-947c-3daf938da458
//https://leetcode.com/problems/reverse-integer/submissions/1172573719/