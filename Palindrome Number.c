bool isPalindrome(int x) {
    // Negative numbers or numbers ending with 0 (except 0 itself) are not palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // For even length numbers: x == reversedHalf
    // For odd length numbers: x == reversedHalf / 10
    return (x == reversedHalf || x == reversedHalf / 10);
}

