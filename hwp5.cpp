#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Item {
  Item(int v, Item* n) { val = v; next = n; }
  int val;
  Item* next;
};

Item* concatenate(Item* head1, Item* head2, int num)
{
if(head1==NULL&&head2==NULL)
{
	Item* head3=head1;
	cout<<"head3:"<<head3<<endl;
	return head3;
}
Item* head3;
cout<<endl<<"new reccurence"<<endl;
if(head1!=NULL&&num==1)
{Item* newitem=new struct Item(head1->val, head2);
	cout<<head1<<"val:"<<head1->val<<endl;
head1=head1->next;
cout<<"inside head1"<<endl;
head3=concatenate(head1, head2, 2);
return newitem;
}
cout<<"out of head1"<<endl;
if(head2!=NULL&&num==2)
{
	cout<<"in head 2"<<endl;
Item* newitem1=new struct Item(head2->val, head1);
cout<<head2<<"val:"<<head2->val<<endl;
head2=head2->next;
head3=concatenate(head1, head2, 1);
return newitem1;
}
cout<<"out of head 2";
//head3=concatenate(head1, head2);
cout<<"going back up"<<endl;
//return head1;
} 


//void removeEvens(Item*& head);
//double findAverage(Item* head);


int main(int argc, char* argv[])
{
	if(argc<3)
    {
        cout<< "Input an input file and an output file after the program name."<<endl;
        return 1;
    }
 ifstream inputfile(argv[1]);
 ofstream outputfile(argv[2]);
 char line1[128];
 char line2[128];
 int array1[5];
 int array2[4];
 inputfile.getline (line1,128);
 inputfile.getline (line2,128);
 int length =strlen(line1);
 int j=0;
for(int i=0; i<length;i++)
{
if(line1[i]!=' ')
{
int place=line1[i] - '0';
array1[j]=place;
j++;
}
}

int k=0;
length=strlen(line2);

for(int i=0; i<length;i++)
{
if(line2[i]!=' ')
{
array2[k]=line2[i] - '0';
k++;
}
}
cout<<"J: "<<j<<"k: "<<k<<endl;

for(int i=0;i<j;i++)
{
	cout<<array1[i]<<" ";
	
}

cout<<endl;

for(int i=0;i<k;i++)
{
	cout<<array2[i]<<" ";	
}

cout <<endl;

//assigning the values to the first linked list
Item* head1;
Item* head2;

// making the first list
Item* previtem=NULL;
for(int i =0; i<j;i++)
{
Item* newitem=new struct Item(array1[j-(i+1)], previtem);
previtem=newitem;
}
head1=previtem;

// making the second list
previtem=NULL;
for(int i =0; i<k;i++)
{
Item* newitem=new struct Item(array2[k-(i+1)], previtem);
previtem=newitem;
}
head2=previtem;


//going through and printing the values
Item* placeholder;
placeholder=head1;
int count=0;
while(placeholder!=NULL)
{
	cout<<placeholder->val;
placeholder=placeholder->next;
count++;
}

placeholder=head2;
count=0;
while(placeholder!=NULL)
{
	cout<<placeholder->val;
placeholder=placeholder->next;
count++;
}

cout<<endl;

//previtem=NULL
cout<<head1->val<<endl<<endl;
Item* head3 = concatenate(head1, head2,1);
cout<<endl;
placeholder=head3;
count=0;
while(placeholder!=NULL)
{
	cout<<placeholder->val;
placeholder=placeholder->next;
count++;
}

cout<<endl;

}

