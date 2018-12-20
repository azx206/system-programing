#include <stdio.h>
#include<string.h>
struct p {
    struct p *prev, *next;
    char name[30];
};
typedef struct p Node;
typedef Node* link;
int main()
{
    char temp[30], tmp;
    int i,cnt=0,cnt1=0;
	int al,pre=0;
    Node a[100]={0};
    char *p;
    char nu[3][10];
	link n;
	link head;
	while(1){
		printf("1.append 2.insert 3.delete 4.exit ");
		scanf("%d",&al);
		if(al==1){
			scanf("%s",temp);
			strcpy(a[cnt].name,temp);
			cnt++;
			if(cnt==1) head=&a[0];
			if(cnt!=1){
				a[cnt-1].prev=&a[pre];
				a[pre].next=&a[cnt-1];
				pre=cnt-1;
			}
		}
		if(al==2){
			scanf("%c", &tmp);
			gets(temp);
			p=strtok(temp," ");
			cnt1=0;
			while(p){
				strcpy(nu[cnt1],p);
				cnt1++;
				p=strtok(NULL," ");
			}
			strcpy(a[cnt].name,nu[1]);
			cnt++;
			n=head;
			while(1){
				if(strcmp(nu[0],n->name)==0){
					a[cnt-1].prev=n;
					a[cnt-1].next=n->next;
					n->next=&a[cnt-1];
					break;
				}
				if(!n->next) break;
				n=n->next;			
			}
		}
		if(al==3){
			scanf("%c", &tmp);
			gets(temp);
			p=strtok(temp," ");
			cnt1=0;
			while(p){
				strcpy(nu[cnt1],p);
				cnt1++;
				p=strtok(NULL," ");
			}
			n=head;
			while(1){
				if(strcmp(nu[0],n->name)==0){
					if(!n->prev) head=n->next;
					else n->prev->next=n->next;
					cnt--;
					break;               	 
				}
				if(!n->next) break;
				n=n->next;	
			}
		}
		if(al==4) break;
		n=head;
		while(1){
			printf("%s ",n->name);
			if(!n->next) break;
			n=n->next;			
		}
		printf("\n");
	}
    return 0;
}
