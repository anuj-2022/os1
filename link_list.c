#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *adr;
}*h;
int display()
{
        struct node *r;
        r=h;
        printf("Linklist is\n");
        while(r!=0)
        {
                printf("%d\t",r->data);
                r=r->adr;
        }
        printf("\n");
}
int creat(int n)
{
        int i,item;
        struct node *p,*q;
        printf("Enter the data\n");
        scanf("%d",&item);
        h=(struct node*)malloc(sizeof(struct node));
        h->data=item;
        p=h;
        for(i=1;i<n;i++)
        {
                printf("Enter the data\n");
                scanf("%d",&item);
                q=(struct node*)malloc(sizeof(struct node));
                q->data=item;
                p->adr=q;
                p=p->adr;
        }
}
int addbeg(int m)
{
        struct node *start;
        start=(struct node*)malloc(sizeof(struct node));
        start->data=m;
        start->adr=h;
        h=start;
}
int search(int l)
{
        struct node *r;
        r=h;
        int pos=1;
        while(r!=0)
        {
                if(r->data==l)
                {
                        printf("data is %d and position is %d\n",r->data,pos);
                }
                r=r->adr;
                ++pos;
        }
}
int addpos(int k)
{
        struct node *s,*t;
        s=h;
        int v,pos=1;
        printf("Enter the position\n");
        scanf("%d",&v);
        while(s!=0)
        {
                ++pos;
                if(pos==v)
                {
                        t=(struct node*)malloc(sizeof(struct node));
                        t->data=k;
                        t->adr=s->adr;
                        s->adr=t;
                }
                 s=s->adr;

        }
}
int addend(int p)
{
        struct node *w,*u;
        w=h;
        while(w->adr!=NULL)
                w=w->adr;
                u=(struct node*)malloc(sizeof(struct node));
                u->data=p;
                u->adr=NULL;
                w->adr=u;
}
void delete(int a)
{
struct node *x,*y;
int i=0;
x=h;
for(i=1;i<a;i++)
{
        y=x;
        x=x->adr;
        if(x==NULL)
        printf("less data in the list\n");
}
        y->adr=x->adr;
free(x);
printf("node is deleted\n");
}
int main()
{
        int n,m,l,k,p,z;
        printf("Enter the node\n");
        scanf("%d",&n);
        creat(n);
        display();
        printf("\nadd data at begening\n");
        scanf("%d",&m);
        addbeg(m);
        display();
        printf("\nEnter the searching data\n");
        scanf("%d",&l);
        search(l);
        display();
        printf("\nEnter the you want to add\n");
        scanf("%d",&k);
        addpos(k);
        display();
        printf("Enter the data at end\n");
        scanf("%d",&p);
        addend(p);
        display();
        printf("Enter the position you have to delete\n");
        scanf("%d",&z);
        delete(z);
        display();
        return 0;
}

