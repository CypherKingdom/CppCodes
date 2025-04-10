#include <iostream>
#include <cstring>
using namespace std;

// String concatenation using pointers
void concatUsingPointers(char *s1, char *s2)
{
    s1 = s1 + strlen(s1);
    while ((*s1++ = *s2++) != '\0')
        ;
}

// String concatenation using indices
void concatUsingIndices(char *s1, char *s2)
{
    int i = 0, n = strlen(s1);
    while ((*(s1 + n + i) = *(s2 + i)) != '\0')
        i++;
}

// Find character in string using pointers
char *findCharUsingPointers(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return s;
        s++;
    }
    return NULL;
}

// Find character in string using indices
char *findCharUsingIndices(char *s, char c)
{
    int i = 0;
    while (*(s + i) != '\0')
    {
        if (*(s + i) == c)
            return (s + i);
        i++;
    }
    return NULL;
}

// Count occurrences of substring in a string
int countSubString(char *line, char *s)
{
    char *p;
    int k = 0;
    p = line;
    while (p = strstr(p, s))
    {
        k++;
        p = p + strlen(s);
    }
    return k;
}

// Demo string concatenation
void demoConcatenation()
{
    char s1[40], s2[20];
    cout << "=== String Concatenation ===" << endl;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    // Make a copy of s1 for both methods
    char s1Copy[40];
    strcpy(s1Copy, s1);

    concatUsingPointers(s1, s2);
    cout << "Concatenated using pointers: " << s1 << endl;

    concatUsingIndices(s1Copy, s2);
    cout << "Concatenated using indices: " << s1Copy << endl;
}

// Demo character finding
void demoFindChar()
{
    char s[25], c;
    cout << "\n=== Find Character in String ===" << endl;
    cout << "Enter a string: ";
    cin >> s;
    cin.ignore();
    cout << "Enter a character to find: ";
    cin.get(c);

    char *result = findCharUsingPointers(s, c);
    if (!result)
        cout << c << " is not found using pointers method" << endl;
    else
        cout << c << " is found at position " << (result - s) << " using pointers method" << endl;

    result = findCharUsingIndices(s, c);
    if (!result)
        cout << c << " is not found using indices method" << endl;
    else
        cout << c << " is found at position " << (result - s) << " using indices method" << endl;
}

// Demo substring counting
void demoCountSubstring()
{
    char line[100], s[10];
    cout << "\n=== Count Substring Occurrences ===" << endl;
    cin.ignore();
    cout << "Enter a line of text: ";
    cin.getline(line, 100);
    cout << "Enter a substring to count: ";
    cin.getline(s, 10);

    cout << "The substring \"" << s << "\" is found "
         << countSubString(line, s) << " times" << endl;
}

int main()
{
    demoConcatenation();
    demoFindChar();
    demoCountSubstring();
    return 0;
}
