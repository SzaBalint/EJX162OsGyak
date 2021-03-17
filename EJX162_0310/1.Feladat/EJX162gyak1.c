#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    system("pause");
    //"Press any key to continue...


    if(system(NULL))
        printf("Command processor exists.\n");
    //ez teljesül
    else
        printf("Command processor doesn't exist.\n");

    system("stop");
    //'stop' is not recognized as an internal or external command, operable program or batch file.

    return 0;
}
