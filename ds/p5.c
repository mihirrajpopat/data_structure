#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.c"

int main()
{
    int ch;
    for(;;)
    {
        printf("\n\n1)Enqueue\n2)Dequeue\n3)Display:\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: enqueue();
                   break;

            case 2: dequeue();
                   break;

            case 3: display();
                    break;
            default:
                    printf("\ninvalid");
                    break;
        }
    }
    return 0;
}
