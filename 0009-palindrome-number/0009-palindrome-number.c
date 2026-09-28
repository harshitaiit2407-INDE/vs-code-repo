

bool isPalindrome(int x) {
    // Negative numbers are not palindromes (e.g., -121 reads as 121-)
    // Numbers ending in 0 are not palindromes, except 0 itself (e.g., 10, 130)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedNumber = 0;
    
    // Reverse the second half of the number and compare it with the first half
    while (x > reversedNumber) {
        int pop = x % 10;
        
        // Check for potential integer overflow before multiplying
        if (reversedNumber > (__INT_MAX__ - pop) / 10) {
            return false; 
        }
        
        reversedNumber = reversedNumber * 10 + pop;
        x /= 10;
    }

    // For even length: x == reversedNumber (e.g., 1221 becomes x = 12, reversed = 12)
    // For odd length: x == reversedNumber / 10 (e.g., 121 becomes x = 1, reversed = 12)
    return x == reversedNumber || x == reversedNumber / 10;

return 0;
}