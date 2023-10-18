/*
已知p指向双向循环链表中的一个结点，其结点结构为data,prior,next三个域；
写出算法change(p),交换p所指向的结点及其前驱结点的顺序。
*/
#include<stdio.h>
#define MAX 100
typedef struct DLnode{
    int data;
    struct DLnode *prior;
    struct DLnode *next;
}DLnode,*LinkList;

int InitList(LinkList &L){
    L=new DLnode;
    L->next=L;
    L->prior=L;
    return 1;
}

void TraveList(LinkList L){
    struct DLnode *p;
    p=L->next;
    while(p!=L){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int ListLength(LinkList &L){
    struct DLnode *p;
    int length=0;
    while(p){
        ++length;
        p=p->next;
    }
    return length;
}

void CreateList(LinkList &L,int &n){
    L=new DLnode;
    L->next=L;
    L->prior=L;
    struct DLnode *p;
    p=L;
    for(int i=0;i<n;i++){
        printf("请输入第%d个元素的值:",i+1);
        struct DLnode *s;
        s=new DLnode;
        scanf("%d",&s->data);
        p->next=s;
        s->next=L;
        s->prior=p;
        p=s;
    }
}

void Change(LinkList p){
    struct DLnode *q;
    q=p->prior;
    q->prior->next=p;//p的前驱的前驱之后继为p
    p->prior=q->prior;//p的前驱指向其前驱的前驱。
    q->next=p->next;//∥p的前驱的后继为p的后继。
    q->prior=p;//p与其前驱交换
    p->next->prior=q;//p的后继的前驱指向原p的前驱
    p->next=q;//p的后继指向其原来的前驱

}

int main(){
    LinkList L;
    if(InitList(L)){
        printf("初始化成功\n");
    }else{
        printf("初始化失败.\n");
    }

    printf("请输入链表元素个数:");
    int n;
    scanf("%d",&n);
    CreateList(L,n);
    TraveList(L);

    printf("请输入要交换的结点的值:");
    struct DLnode *s;
    s=new DLnode;
    scanf("%d",&s->data);
    struct DLnode *p;
    p=L->next;
    while(p!=L){
        if(p->data==s->data){
            Change(p);

            break;
        }else{
            p=p->next;
        }
    }
    TraveList(L);
}