typedef struct ListNode ListNode;
struct ListNode *exchange(ListNode *temphead, ListNode *l, int k){
	ListNode *ret = (ListNode*)malloc(sizeof(ListNode));//�´�һ����
	ListNode *p = temphead;//������ʱ����
	ListNode *rear = ret;//��Ǹ�������β��
	int i = 0;//ѭ������
	ret->next = NULL;
	for(i = 0; i < k; i++){
		p = p->next;
		if(i == k - 1){
			rear->next = temphead->next;
		}//����ǲ������һ��Ԫ�أ�Ҫ���Ӻ��������
		temphead->next = ret->next;
		ret->next = temphead;
		if(i == 0){
			rear = ret->next;
		}//����ǵ�һ����㣬��rear;
		temphead = p;//����Ҫ���ӵĽ��
	}//ͷ�巨
	return ret->next;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
	ListNode *l = (ListNode*)malloc(sizeof(ListNode));//���ÿһ�η�ת�ӱ���ǰһ�����
	ListNode *p = l;//ѭ��ָ��
	ListNode *temphead = head;
	int i = 0;//ѭ������
	ListNode *templ = NULL;
	l->next = head;
	templ = l;//l����ʱ����
	while(p->next){
		for(i = 0; p->next && i < k; i++){
			p = p->next;
		}//pָ������ƶ�k��,Ϊ��һ��ͷ���
		if(i == k){
			templ->next = exchange(temphead, templ, k);
			templ = temphead;
			p = templ;
			temphead = temphead->next;
		}//����ɹ��ƶ�k��������н���
	}//���p��Ϊ��ָ�룬����д���
	return l->next;
}