char * removeDuplicates(char * s){
    //����ַ�������
    int strLength = strlen(s);
    //����ջ�ռ䡣ջ�ռ䳤��ӦΪ�ַ�������+1��Ϊ�˴���ַ���������־'\0'��
    char* stack = (char*)malloc(sizeof(char) * strLength + 1);
    int stackTop = 0;

    int index = 0;
    //���������ַ���
    while(index < strLength) {
        //ȡ����ǰindex��Ӧ��ĸ��֮��index+1
        char letter = s[index++];
        //��ջ����Ԫ�أ���ջ����ĸ���ڵ�ǰ��ĸ������ĸ���ڣ�����ջ��Ԫ�ص���
        if(stackTop > 0 && letter == stack[stackTop - 1])
            stackTop--;
        //������ĸ��ջ
        else
            stack[stackTop++] = letter;
    }
    //����ַ���������־'\0'
    stack[stackTop] = '\0';
    //����ջ������Ϊ�ַ���
    return stack;
}