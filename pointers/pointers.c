#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    printf("String copy... %p\n%c\n", x, *y);

    while (*y != '\0')
    {
        *x = *y;
        printf("From while.. %s\n", x);
        x++;
        y++;
    }
    *x = '\0';
};

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == c)
        {
            printf("Here we are...%p\n", &str[i]);
            return &str[i];
        }
    }
    return 0;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    for (int i = 0; i < haystack_len; i++)
    {
        if (haystack[i] == needle[0])
        {
            for (int j = 1; j < needle_len; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
                else if (j == (needle_len - 1) && haystack[i + j] == needle[j])
                {
                    return &haystack[i];
                }
            }
        }
    }

    return 0;
}

#ifndef TESTING
int main(void)
{

    char *string = "hello, world";
    char empty[20];

    string_copy(empty, string);

    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
