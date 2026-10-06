#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char username[50];
    printf("Please provide your name: ");
    scanf("%s", username);
    printf("Hello %s\n", username);
    printf("Your name has %zu letters\n", strlen(username));
    return 0;
}
