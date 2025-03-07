#define MAX 10

int mystack[MAX];
int top=0;

void push(int n)
{
    if (top==MAX)
        printf("Full stack cannot push\n");
    else
        mystack[top++]=n;
}

int pop()
{
    if (top==0)
    {
        printf("Empty stack cannot pop\n");
        return -1;
    }

    else return mystack[--top];
}

int peek()
{
    if (top==0)
    {
        printf("Empty stack cannot pop\n");
        return -1;
    }

    else return mystack[top-1];
}

void stckprint()
{
    int i;
    printf("Printing the stack\n---------------------\n");
    for(i=0;i<top;i++)
        printf("Stack[%d]:%d\n",i,mystack[i]);
}