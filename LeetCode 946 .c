bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize)
{
    int stack[pushedSize + 1], top = 0;
    for (int i = 0, j = 0; i < pushedSize; i++)
    {
        stack[top++] = pushed[i];
        while (top > 0 && stack[top - 1] == popped[j])
        {
            top--;
            j++;
        }
    }
    return top == 0;
}