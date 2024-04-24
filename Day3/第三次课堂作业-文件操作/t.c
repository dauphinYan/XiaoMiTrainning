#include <stdio.h>

int main()
{
    FILE *file = fopen("text.txt", "w");

    char *name = "名字";
    fprintf(file, name);

    fclose(file);

    file = fopen("text", "r");
    char buf[1000];
    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        printf("%s", buf);
    }

    printf("\n");
    fclose(file);

    return 0;
}