bool isalpha(unsigned char c) {
    if ((c >= 'a' && c <= 'z') or (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

unsigned char tolower(unsigned char c) {
    if (c >= 'A' and c <= 'Z')
        return c - 'A' + 'a';
    return c;
}
