#include <iostream>
#include <stack>
#include<string>
#include <algorithm>
using namespace std; 
typedef struct node
{  
	int data;
	node *next;
}Node, *LinkList;
//判断相减时两个数的大小关系
int judge(string a,string b)
{
    int i;
    if (a.size()<b.size()) {
        return 0;
    }
    else if (a.size()> b.size()) {
        return 1;
    }

    for (i = 0; i <a.size(); i++) {
        if (a[i] < b[i]) {
            return 0;
        }
    }
    return 1;
}
//建立链表
Node* createList(string a, int n)
{
	Node *head, *endPtr;
	head = endPtr = NULL;
	
	for(int i=n-1;i>=0;i--)
	{
		Node *temp = new Node;
		temp->data = a[i]-'0';
		temp->next = NULL;
		if(i==n-1)
		{
			head = endPtr = temp;
		}
		else
		{
			endPtr->next = temp;
			endPtr = temp;
		}
	}
 
	return head;
}
//输出结果
void PrintListReversing(LinkList pHead)
{
	stack<Node*> nodes;
	Node* pNode = pHead;
	int flag=0,num=0;
	if(pNode==NULL)
		return;
 
	while(pNode!=NULL)   
	{   num++;
		nodes.push(pNode);
		pNode = pNode->next;
	}
 
	while(!nodes.empty())   
	{   flag++;
		pNode = nodes.top();
		if(flag==1){if(pNode->data==0){ do{nodes.pop();pNode = nodes.top();flag++;}while(pNode->data==0);}}
		cout<<pNode->data;
		nodes.pop();   
		if(!((num-flag)%3)&&flag!=num)cout<<',';
	}
}
#define N 100000001
int dd[N],ds[N],qu[N];
//大数相加
Node *ListAdd(Node* L1, Node* L2)
{
	if(L1==NULL)
		return L2;
	if(L2==NULL)
		return L1;
 
	Node *ptr1 = L1, *ptr2 = L2, *ResultPtr=NULL, *TmpPtr=NULL;
	int carry = 0;
 
	Node *p_node = new Node();
	p_node->data = (L1->data+L2->data)%10;
	p_node->next = NULL;
	carry = (L1->data+L2->data)/10;
	ResultPtr = TmpPtr = p_node;
	TmpPtr->next = NULL;
	L1 = L1->next;
	L2 = L2->next;
 
	while(L1 && L2)
	{
		Node *pNode = new Node();
		TmpPtr->next = pNode;
 
		int tmp = L1->data+L2->data+carry;
		carry = tmp/10;
		pNode->data = tmp%10;
		pNode->next = NULL;
 
		TmpPtr = TmpPtr->next;
		L1 = L1->next;
		L2 = L2->next;
	}
 
	while(L1)
	{
		Node *pNode = new Node();
		TmpPtr->next = pNode;
 
		int tmp = L1->data+carry;
		carry = tmp/10;
		pNode->data = tmp%10;
		pNode->next = NULL;
 
		TmpPtr = TmpPtr->next;
		L1 = L1->next;
	}
	while(L2)
	{
		Node *pNode = new Node();
		TmpPtr->next = pNode;
 
		int tmp = L2->data+carry;
		carry = tmp/10;
		pNode->data = tmp%10;
		pNode->next = NULL;
 
		TmpPtr = TmpPtr->next;
		L2 = L2->next;
	}
 
	if(carry)
	{
		Node *pNode = new Node();
		TmpPtr->next = pNode;
 
		pNode->data = carry;
		pNode->next = NULL;
	}
 
	return ResultPtr;
}
//大数相减
Node *Listsubstract(Node* L1, Node* L2)
{
	if(L1==NULL)
		return L2;
	if(L2==NULL)
		return L1;
 
	Node *ptr1 = L1, *ptr2 = L2, *ResultPtr=NULL, *TmpPtr=NULL;
	int carry = 0;
 
	Node *p_node = new Node();
	p_node->data = (L1->data-L2->data);
	if(p_node->data<0){
		p_node->data+=10;
		carry=-1;}
	else carry=0;
	p_node->next = NULL;
	ResultPtr = TmpPtr = p_node;
	TmpPtr->next = NULL;
	L1 = L1->next;
	L2 = L2->next;
 
	while(L1 && L2)
	{
		Node *pNode = new Node();
		TmpPtr->next = pNode;
 
		int tmp = L1->data-L2->data+carry;
		if(tmp<0){tmp+=10;
		carry=-1;}
		else carry=0;
		pNode->data = tmp;
		pNode->next = NULL;
 
		TmpPtr = TmpPtr->next;
		L1 = L1->next;
		L2 = L2->next;
	}
 
	while(L1)
	{
		Node *pNode = new Node();
		TmpPtr->next = pNode;
 
		int tmp = L1->data+carry;
		if(tmp<0){tmp+=10;
		carry=-1;}
		else carry=0;
		pNode->data = tmp;
		pNode->next = NULL;
 
		TmpPtr = TmpPtr->next;
		L1 = L1->next;
	}

	return ResultPtr;
} 
//大数相乘
void multi(string a,string b,int len1,int len2)
{string product="";
int carry = 0;
		int remain = 0;
		product.resize(len1 + len2);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
 
		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				int tmp = (a[i] - '0') * (b[j] - '0') + product[i+j];
 
				carry = tmp / 10;
				remain = tmp % 10;
				product[i + j + 1] += carry;
				product[i + j] = remain;
			}
		}
 
		if (product[len1+len2-1]==0)
			product.resize(product.size() - 1);
 
 
		reverse(product.begin(), product.end());
		for (i = 0; i < product.size(); i++)
		{
			cout << char(product[i] + '0');if(!((product.size()-1-i)%3)&&i!=product.size()-1)cout<<",";
		}
		cout << endl;
}
//判断大小并进行一次减法
int sub(int* dd,int* ds,int len1,int len2)   
{
	 int i;
    if (len1<len2)  return -1;
    else if (len1==len2)
        for (i=len1-1;i>=0;i--)
        {
            if (dd[i]<ds[i])
                    return -1;
            else if (dd[i]>ds[i])
                break;
        }
    for (i=0;i<len1;i++)
    {
        dd[i]-=ds[i];
        if (dd[i]<0)
        {
            dd[i]+=10;
            dd[i+1]--;
        }
    }
    for (i=len1-1;i>=0;i--)
        if (dd[i])  break;
    return i+1;
}
//大数相除
int chu(int* dd,int* ds,int len1,int len2)
{ len1=sub(dd,ds,len1,len2);
    if (len1==-1)
    {
        printf("0\n");
        return 0;
    }
    else if (len1==0)
    {
        printf("1\n");
        return 0;
    }
    qu[0]=1;
    int times=len1-len2;
    for (int i=len1-1;i>=0;i--)             
    {
        if (i>=times)
            ds[i]=ds[i-times];
        else
            ds[i]=0;
    }
    len2=len1;
    for (int j=0;j<=times;j++)
    {
        int tmp;
        while ((tmp=sub(dd,ds+j,len1,len2-j))>=0)
        {
            len1=tmp;
            qu[times-j]++;
        }
    }
    for (i=0;i<N;i++)
    {
        if (qu[i]>9)
        {
            qu[i+1]+=qu[i]/10; 
            qu[i]%=10;
        }       
    }
    for (i=N-1;qu[i]==0&&i>=0;i--);
    while (i>=0)
	{cout<<qu[i--];if(!((i+1)%3)&&i!=-1)cout<<",";}
    cout<<endl;
}
int main()
{string a,b;
    int count=0,num=0,len1,len2;
    int c;
    cout<<"选择你要进行的操作:"<<endl;
    cout<<"1.长整数加法运算"<<endl;
    cout<<"2.长整数减法运算"<<endl;
    cout<<"3.长整数乘法运算"<<endl;
	cout<<"4.长整数除法运算"<<endl;
    cout<<"选择你需要进行的运算:"<<endl;
    cin>>c;cin.ignore();
    switch(c)
    {
        case 1:
        { 
            cout<<"请输入第一个数:"<<endl;
            cin>>a;
			len1=a.size();
            cout<<"请输入第二个数:"<<endl;
           	cin>>b;
			len2=b.size();
            Node *L1 = createList(a,len1), *L2 = createList(b,len2), *L3 = NULL;
	      L3 = ListAdd(L1,L2);
            cout<<"相加的结果是:";
			PrintListReversing(L3);
	      cout<<endl;
        }break;
        case 2:
        {
        cout<<"请输入第一个数:"<<endl;
           cin>>a;
		   len1=a.size();
            cout<<"请输入第二个数:"<<endl;
            cin>>b;
            len2=b.size();
            Node *L1 = createList(a,len1), *L2 = createList(b,len2), *L3 = NULL;
			if(judge(a,b)){
			L3 = Listsubstract(L1,L2);
			cout<<"相减的结果是:";
           	PrintListReversing(L3);
			cout<<endl;}
			else{L3 = Listsubstract(L2,L1);
            cout<<"相减的结果是:-";
           	PrintListReversing(L3);
			cout<<endl;}
        }break;
		case 3:
		{
           cout<<"请输入第一个数:"<<endl;
           cin>>a;
		   len1=a.size();
            cout<<"请输入第二个数:"<<endl;
            cin>>b;
            len2=b.size();
           cout<<"相乘的结果是:";
			multi(a,b,len1,len2);
		}break;
		case 4:
		{
			cout<<"请输入第一个数:"<<endl;
           cin>>a;
		   len1=a.size();
            cout<<"请输入第二个数:"<<endl;
            cin>>b;
            len2=b.size();
        for (int k=0,i=len1-1;i>=0;i--)
        dd[k++]=a[i]-'0';
        for (k=0,i=len2-1;i>=0;i--)
        ds[k++]=b[i]-'0';
           cout<<"相除的结果是:";
		   chu(dd,ds,len1,len2);}
        default:break;
    }


}
