#include <stdio.h>
#include <stdlib.h>
#include "reverse.c"
char *s="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
int main()
{
    int ch;
    for(;;)
    {
        printf("\n%s1)insert at first\n2)insert at last\n3)delete at last\n4)delete at first\n5)display\n6)reverse linklist\n7)exit : ",s);
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                    insert_at_first();
                    break;
            case 2:
                    insert_at_last();
                    break;
            case 3:
                    delete_at_last();
                    break;
            case 4:
                    delete_at_first();
                    break;
            case 5:
                    display(head);
                    break;

            case 6:
                    if(isEmpty(head))
                    {
                        int k;
                        printf("\nEnter K : ");
                        scanf("%d",&k);
                        if(k<1)
                            break;
                        reverse_linklist(k);

                    }

                    break;

            case 7:
                    exit(0);
                    break;
            default:
                    printf("\ninvalid");
                    break;
        }
    }
    return 0;
}


