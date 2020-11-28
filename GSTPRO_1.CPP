
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<iomanip.h>
#include<dos.h>
			       //----------
/*fstream sfile;               //SALE CLASS
struct memo                    //----------
{
 char cpny[20],model[12];
 int sno,mtype;
 float qty,price,size;
};
class sale
{
  char bname[30],bgst[16],bph[14];
  int pcode,item,sd,sm,sy;
  float gtotal;
  memo bill[12];
 public:
  void read(int x)
  {
   struct dosdate_t d;
   _dos_getdate(&d);
   sy=d.year;
   sd=d.day;
   sm=d.month;
   pcode =x;
   int r=8;
   gotoxy(5,r+=2);cout<<"Enter Buyer's Goods and Service Tax number-: ";
   gets(bgst);
   for(int i=0;bgst[i]!='\0';i++)
   bgst[i]=toupper(bgst[i]);
   fflush(stdin);
   gotoxy(5,r+=2);cout<<"Enter buyer's name-:";
   gets(bname);
   fflush(stdin);
   gotoxy(5,r+=2);cout<<"Enter buyer's phone number-:";
   cin>>bph;
   for(i=0;bname[i]!='\0';i++)
    bname[i]=toupper(bname[i]);

   char ch='y';
   item=0;
   while(ch!='n')
   {
    clrscr();
    bill[item].sno=item+1;
    cout<<"Enter Company Name-: ";
    gets(bill[item].cpny);
    fflush(stdin);
    cout<<"\nEnter Model of cycle-: ";
    gets(bill[item].model);
    fflush(stdin);
      cout<<"\n5.Enter model type accordingly-:\n"<<"\t1 for Ladies Cycle\n"
       <<"\t2 for Gents Cycle\n"<<"\t3 for Kids Cycle\n";
    cin>>bill[item].mtype;
    cout<<"\nEnter cycle size in inches-: ";
    cin>>bill[item].size;
    cout<<"\nEnter the quantity of cycle-: ";
    cin>>bill[item].qty;
    cout<<"\nEnetr the price of cycle-: ";
    cin>>bill[item].price;
    cout<<"\nDo you want to enter more data y/n?";
    cin>>ch;
   }
  }
  void display()
  {
   int m=2;
   gotoxy(29,m++);cout<<"|-------------------|";
   gotoxy(29,m++);cout<<"|SHYAM CYCLE COMPANY|";
   gotoxy(29,m);cout<<"|-------------------|";
   gotoxy(1,m);cout<<"Ph.:9415525463";
   gotoxy(58,m++);cout<<"GST NO.:09AGLPA7142E1ZL";
   gotoxy(1,m);cout<<"Buyer :";
   cout<<bname;
   gotoxy(40,m++);cout<<"Memo No.:"<<pcode;
   gotoxy(35,m);cout<<"Buyer's Ph. :";
   cout<<bph;
   gotoxy(1,m++);cout<<"Buyer's GST :";
   cout<<bgst;
   gotoxy(1,m++);
   for(int i=0;i<80;i++)
    cout<<'-';
   gotoxy(1,m);cout<<"|  SNo  |";
   gotoxy(21,m);cout<<"COMPANY";
   gotoxy(38,m);cout<<'|';
   gotoxy(47,m);cout<<"MODEL";
   gotoxy(60,m);cout<<'|';
   gotoxy(64,m);cout<<"QTY";
   gotoxy(70,m);cout<<'|';
   gotoxy(73,m);cout<<"PRICE";
   gotoxy(80,m++);cout<<'|';
   gotoxy(1,m);
   for(i=0;i<80;i++)
    cout<<'-';
   for(;m<=24;m++)
    {
     gotoxy(1,m);cout<<'|';
     gotoxy(9,m);cout<<'|';
     gotoxy(38,m);cout<<'|';
     gotoxy(60,m);cout<<'|';
     gotoxy(70,m);cout<<'|';
     gotoxy(80,m);cout<<'|';
    }
    gotoxy(2,m--);
    for(i=0;i<78;i++)
    cout<<'-';
    gotoxy(2,--m);
    for(i=0;i<78;i++)
      cout<<'-';
    gotoxy(9,++m);cout<<"CGST= 6%";
    gotoxy(34,m);cout<<"SGST= 6%";
    gotoxy(58,m);cout<<"T O T A L :";
    gotoxy(70,m);cout<<' ';
    gotoxy(69,m);
  }
int retpcode() { return pcode;}
}cy;
void main()
{
 clrscr();
 sfile.open("Sale.dat",ios::in|ios::out|ios::binary);
 long sib,slb;
 int x,n;
 sfile.seekg(0,ios::end);
 slb=sfile.tellp();
 sib=0;
 if(slb==0)
   x=0;
 else
  {
   sfile.seekg(slb-sizeof(cy),ios::beg);
   sfile.read((char *) &cy, sizeof(cy));
     x=cy.retpcode();
  }
 char ch='y';
 while(ch!='n')
 {
  cout<<"\n 1 for read\n 2 for display\n 3 for exit";
  cin>>n;
  switch(n)
  {
   case 1:
	  sfile.seekg(0,ios::end);
	   cy.read(++x);
	   sfile.write((char *)&cy , sizeof(cy));
	  break;
   case 2:
	clrscr();
	sfile.seekg(0,ios::end);
	  slb=sfile.tellp();
	  sib=0;
	  sfile.seekg(0);
	  while(sib!=slb)
	  {
	   sfile.read((char *)&cy , sizeof(cy));
	   cy.display();
	   sib+=sizeof(cy);
	  }
	  break;
   default:exit(0);
  }
  cout<<"\nDo you want more operations?";
  cin>>ch;
 }
 sfile.close();
}*/

/*fstream gfile;                      //GST CLASS
class gst                             //---------
{
 int cno;
 char cpyname[25],cpygst[16];
 public:
 gst()
 {
  strcpy(cpyname,"N.A.");
  strcpy(cpygst,"NIL");
 }
 void read(int x)
 {
  cno=x;
  for(int i=1,c=2;i<=80;i++,c++)
  {
   gotoxy(i,1);cout<<'-';
   gotoxy(i,24);cout<<'-';
   if(c<24)
   {
    gotoxy(1,c);cout<<'|';
    gotoxy(80,c);cout<<'|';
   }
  }
   c=10;
   gotoxy(12,c+=2);cout<<"Enter company name:";
   gets(cpyname);
   fflush(stdin);
   gotoxy(12,c+=2);cout<<"Enter gst number:";
   gets(cpygst);
   fflush(stdin);
 }
 void display(int c)
 {
  gotoxy(10,c);cout<<cno<<")";
  gotoxy(14,c);
  cout<<cpyname;
  gotoxy(40,c);cout<<':';
  gotoxy(48,c++);
  cout<<cpygst;
 }
 char* retGSTNO(char CName[])
 {
  long gib,glb;
  gfile.seekg(0,ios::end);
	  lb=gfile.tellp();
	  ib=0;
	  gfile.seekg(0);
	  while(ib!=lb)
	  {
	   gfile.read((char *)&gt , sizeof(gt));
	   if(strcmpi(CName,cpyname)==0)
	    return cpygst;
	   ib+=sizeof(gt);
	  }
 }

 int retcno() { return cno;}
}gt;
void main()
{
 clrscr();
 gfile.open("GST.dat",ios::in|ios::out|ios::binary);
 long gib,lb;
 int x,n,m;
 gfile.seekg(0,ios::end);
 glb=gfile.tellp();
 gib=0;
 if(glb==0)
   x=0;
 else
  {
   gfile.seekg(glb-sizeof(gt),ios::beg);
   gfile.read((char *) &gt, sizeof(gt));
     x=gt.retcno();
  }
 char ch='y';
 while(ch!='n')
 {
  cout<<"\n 1 for read\n 2 for display\n 3 for print GST \n 4 for exit";
  cin>>n;
  switch(n)
  {
   case 1:
	  gfile.seekg(0,ios::end);
	   gt.read(++x);
	   gfile.write((char *)&gt , sizeof(gt));
	  break;
   case 2:
	clrscr();
	for(int i=1,c=2;i<=80;i++,c++)
	{
	 gotoxy(i,1);cout<<'-';
	 gotoxy(i,24);cout<<'-';
	 if(c<24)
	 {
	  gotoxy(1,c);cout<<'|';
	  gotoxy(80,c);cout<<'|';
	 }
	}
	c=2;
	gotoxy(15,c);cout<<"COMPANY NAME";
	gotoxy(50,c++);cout<<"GST NUMBER";
	gotoxy(15,c);cout<<"------------";
	gotoxy(50,c++);cout<<"----------";
	gfile.seekg(0,ios::end);
	  glb=gfile.tellp();
	  gib=0;
	  gfile.seekg(0);
	  while(gib!=glb)
	  {
	   gfile.read((char *)&gt , sizeof(gt));
	   gt.display(c++);
	   gib+=sizeof(gt);
	  }
	  break;
	  case 3:
	  char nm[25];
	  cout<<"\nEnter co name :";
	  gets(nm); fflush(stdin);
	  cout<<gt.retGSTNO(nm);
	  getch();
	  break;
   default:exit(0);
  }
  cout<<"\nDo you want more operations?";
  cin>>ch;
 }
 gfile.close();
}*/
					 //--------------
fstream pfile;                         //PURCHASE CLASS
class purchase                           //--------------
{
  char company[30],model[12];
  int pcode,mtype;
  float size,qty,rate;
 public:
  void read(int x)
  {
   pcode =x;
   for(int i=1,c=2;i<=80;i++,c++)
   {
    gotoxy(i,1);cout<<'-';
    gotoxy(i,24);cout<<'-';
    if(c<24)
     {
      gotoxy(1,c);cout<<'|';
      gotoxy(80,c);cout<<'|';
     }
   }
   gotoxy(30,4);cout<<"SHYAM CYCLE COMPANY";
   for(i=29;i<50;i++)
   {
    gotoxy(i,3);cout<<'-';
    gotoxy(i,5);cout<<'-';
   }
   c=5;i=6;
   gotoxy(i,c+=2);cout<<"ENTER COMPANY NAME :";
   gets(company);
    fflush(stdin);
   for(int t=0;company[t]!='\0';t++)
     company[t]=toupper(company[t]);
   gotoxy(i,c+=2);cout<<"ENTER MODEL OF CYCLE :";
   gets(model);
    fflush(stdin);
    for(t=0;model[t]!='\0';t++)
      model[t]=toupper(model[t]);
   gotoxy(i,c+=2);cout<<"ENTER MODEL TYPE :";
   gotoxy(i+=2,++c);cout<<"1 FOR LADIES";
   gotoxy(i,++c);cout<<"2 FOR GENTS";
   gotoxy(i,++c);cout<<"3 FOR KIDS";
   cin>>mtype;
   while(mtype!=1 && mtype!=2 && mtype!=3)
   {
    gotoxy(i-=2,c+=2);cout<<'\a'<<"Enter either 1/2/3";
    cin>>mtype;
   }
   gotoxy(i-=2,c++);cout<<"ENTER SIZE :";
   cin>>size;
   if(!(size>=13 && size<=24))
    {
     gotoxy(++i,c+=2);cout<<"Enter between 13 and 24 in integer";
     cin>>size;
    }
   gotoxy(i,c+=2);cout<<"ENTER QUANTITY :";
   cin>>qty;
   gotoxy(i,c+=2);cout<<"ENTER RATE :";
   cin>>rate;
  }
  void display(int r)
  {
   gotoxy(80,r);cout<<'|';
   gotoxy(7,r);cout<<'|';
   gotoxy(27,r);cout<<'|';
   gotoxy(43,r);cout<<'|';
   gotoxy(63,r);cout<<'|';
   gotoxy(72,r);cout<<'|';
   gotoxy(1,r++);cout<<'|';
   gotoxy(1,r);cout<<'|';
   cout<<' '<<pcode;
   gotoxy(7,r);cout<<'|';
   cout<<' '<<company;
   gotoxy(27,r);cout<<'|';
   switch(mtype)
    {
     case 1:cout<<' '<<"Ladies";
	  break;
     case 2:cout<<' '<<"Gents";
	  break;
     case 3:cout<<' '<<"Kids";
	  break;
     default:cout<<' '<<"N.A.";
	  break;
    }
   gotoxy(43,r);cout<<'|';
   cout<<' '<<model;
   gotoxy(63,r);cout<<'|';
   cout<<' '<<qty;
   gotoxy(72,r);cout<<'|';
   cout<<' '<<rate;
   gotoxy(80,r);cout<<'|';
  }
  void display(int r,char temp[])
  {
   if(strcmpi(temp,company)==0)
   {
    gotoxy(80,r);cout<<'|';
    gotoxy(7,r);cout<<'|';
    gotoxy(27,r);cout<<'|';
    gotoxy(43,r);cout<<'|';
    gotoxy(63,r);cout<<'|';
    gotoxy(72,r);cout<<'|';
    gotoxy(1,r++);cout<<'|';
    gotoxy(1,r);cout<<'|';
    cout<<' '<<pcode;
    gotoxy(7,r);cout<<'|';
    cout<<' '<<company;
    gotoxy(27,r);cout<<'|';
    switch(mtype)
    {
     case 1:cout<<' '<<"Ladies";
	  break;
     case 2:cout<<' '<<"Gents";
	  break;
     case 3:cout<<' '<<"Kids";
	  break;
     default:cout<<' '<<"N.A.";
	  break;
    }
    gotoxy(43,r);cout<<'|';
    cout<<' '<<model;
    gotoxy(63,r);cout<<'|';
    cout<<' '<<qty;
    gotoxy(72,r);cout<<'|';
    cout<<' '<<rate;
    gotoxy(80,r);cout<<'|';
   }
   else
   {
    clrscr();
    gotoxy(29,12);cout<<" | COMPANY NOT FOUND |";
    gotoxy(31,10);cout<<"___________________";
    gotoxy(30,11);cout<<"|                   |";
    gotoxy(30,13);cout<<"|___________________|";
   }
  }
 int retpcode() { return pcode;}
}cy;
void main()
{
 clrscr();
 pfile.open("Purchase.dat",ios::in|ios::out|ios::binary);
 long pib,plb;
 int x,n;
 pfile.seekg(0,ios::end);
 plb=pfile.tellp();
 pib=0;
 if(plb==0)
   x=0;
 else
  {
   pfile.seekg(plb-sizeof(cy),ios::beg);
   pfile.read((char *) &cy, sizeof(cy));
     x=cy.retpcode();
  }
 char ch='y';
 while(ch!='n')
 {
  clrscr();
  int c=3;
  gotoxy(30,c);cout<<"SHYAM CYCLE COMPANY";
  c+=7;
  gotoxy(25,c++);cout<<"PRESS 1 To READ DATA OF COMPANY";
  gotoxy(25,c++);cout<<"PRESS 2 TO DISPLAY COMPANY LIST";
  gotoxy(25,c++);cout<<"PRESS 3 TO READ ITEMS OF PURACHSE";
  gotoxy(25,c++);cout<<"PRESS 4 TO DISPLAY ITEMS";
  gotoxy(25,c++);cout<<"PRESS 5 TO MODIFY ITEMS";
  gotoxy(25,c++);cout<<"PRESS 6 TO SEARCH ITEMS";
  gotoxy(25,c++);cout<<"PRESS 7 TO ENTER SALE ITEM";
  gotoxy(25,c++);cout<<"PRESS 8 TO DISPLAY INVOICE";
  gotoxy(25,c++);cout<<"PRESS 9 TO EXIT";
  for(int i=29;i<50;i++)
  {
   c=2;
   gotoxy(i,c);cout<<'-';
   c=4;
   gotoxy(i,c);cout<<'-';
  }
  for(i=20;i<60;i++)
  {
   c=7;
   gotoxy(i,c);cout<<'-';
   if(i>20 && i<59)
   {c=8;
    gotoxy(i,c);cout<<'_';}
   c=21;
   gotoxy(i,c);cout<<'-';
   if(i>20 && i<59)
   {c=19;
    gotoxy(i,c);cout<<'_';}
  }
  gotoxy(24,23);cout<<"ENTER YOUR CHOICE:";gotoxy(42,24);cout<<"^^^";
  gotoxy(43,23);cin>>n;
 switch(n)
  {
   case 1:clrscr();
	  ch='y';
	  pfile.seekg(0,ios::end);
	  while(ch!='n')
	  {
	   cy.read(++x);
	   pfile.write((char *)&cy , sizeof(cy));
	   clrscr();
	   for(int i=1,c=2;i<=80;i++,c++)
	   {
	    gotoxy(i,1);cout<<'-';
	    gotoxy(i,24);cout<<'-';
	    if(c<24)
	    {
	     gotoxy(1,c);cout<<'|';
	     gotoxy(80,c);cout<<'|';
	    }
	   }
	   gotoxy(25,12);cout<<"Do you want to enter more data";
	   cin>>ch;
	   while(ch!='y' && ch!='Y' && ch!='n' && ch!='N')
	     {
	      gotoxy(20,13);cout<<"error!! choose either n/y. Enter Again";
	      gotoxy(38,15);cout<<"^^^";
	      gotoxy(39,14);cin>>ch;
	      ch=tolower(ch);
	     }
	  }
	  break;
   case 2:
	clrscr();
	int r=2;
	gotoxy(29,r++);cout<<"|-------------------|";
	gotoxy(29,r++);cout<<"|SHYAM CYCLE COMPANY|";
	gotoxy(29,r);cout<<"|-------------------|";
	gotoxy(1,r);cout<<"Ph.:9415525463";
	gotoxy(58,r++);cout<<"GST NO.:09AGLPA7142E1ZL";
	gotoxy(1,r++);
	for(int i=0;i<80;i++)
	  cout<<'-';
	gotoxy(1,r);cout<<"|PCODE|";
	gotoxy(14,r);cout<<"COMPANY";
	gotoxy(27,r);cout<<'|';
	gotoxy(33,r);cout<<"MTYPE";
	gotoxy(43,r);cout<<'|';
	gotoxy(51,r);cout<<"MODEL";
	gotoxy(63,r);cout<<'|';
	gotoxy(66,r);cout<<"QTY   |";
	gotoxy(74,r++);cout<<"RATE  |";
	gotoxy(1,r);
	for(i=0;i<80;i++)
	cout<<'-';
	pfile.seekg(0,ios::end);
	  plb=pfile.tellp();
	  pib=0;
	  pfile.seekg(0);
	  while(pib!=plb)
	  {
	   pfile.read((char *)&cy , sizeof(cy));
	   cy.display(r++);
	   pib+=sizeof(cy);
	  }
	  break;
   case 3:
	clrscr();
	char temp[30];
	gotoxy(3,13);cout<<"ENTER THE NAME OF THE COMPANY WHOSE ITEMS YOU WANT TO SEARCH : ";
	gets(temp); fflush(stdin);
	clrscr();
	r=2;
	gotoxy(29,r++);cout<<"|-------------------|";
	gotoxy(29,r++);cout<<"|SHYAM CYCLE COMPANY|";
	gotoxy(29,r);cout<<"|-------------------|";
	gotoxy(1,r);cout<<"Ph.:9415525463";
	gotoxy(58,r++);cout<<"GST NO.:09AGLPA7142E1ZL";
	gotoxy(1,r++);
	for(i=0;i<80;i++)
	  cout<<'-';
	gotoxy(1,r);cout<<"|PCODE|";
	gotoxy(14,r);cout<<"COMPANY";
	gotoxy(27,r);cout<<'|';
	gotoxy(33,r);cout<<"MTYPE";
	gotoxy(43,r);cout<<'|';
	gotoxy(51,r);cout<<"MODEL";
	gotoxy(63,r);cout<<'|';
	gotoxy(66,r);cout<<"QTY   |";
	gotoxy(74,r++);cout<<"RATE  |";
	gotoxy(1,r);
	for(i=0;i<80;i++)
	cout<<'-';
	pfile.seekg(0,ios::end);
	  plb=pfile.tellp();
	  pib=0;
	  pfile.seekg(0);
	  while(pib!=plb)
	  {
	   pfile.read((char *)&cy , sizeof(cy));
	   cy.display(r++,temp);
	   pib+=sizeof(cy);
	  }
	  break;
   default:exit(0);
  }
  gotoxy(3,24);cout<<"Do you want more operations?";
  cin>>ch;
  while(ch!='y' && ch!='Y' && ch!='n' && ch!='N')
  {
    gotoxy(3,24);cout<<"error!! choose either n/y. Enter Again";
    cin>>ch;
   ch=tolower(ch);
  }
 }
 pfile.close();
}				    //----------------
/*void main()                       //OPERATION CHOOSE
{                                   //----------------
 clrscr();
 gotoxy(30,4);cout<<"SHYAM CYCLE COMPANY";
 gotoxy(31,12);cout<<"PRESS 1 TO READ";
 gotoxy(31,13);cout<<"PRESS 2 TO DISPLAY";
 gotoxy(31,14);cout<<"PRESS 3 TO DELETE";
 gotoxy(31,15);cout<<"PRESS 4 TO MODIFY";
 gotoxy(31,16);cout<<"PRESS 5 TO EXIT";
 for(int i=29;i<50;i++)
 {
  gotoxy(i,3);cout<<'-';
  gotoxy(i,5);cout<<'-';
  gotoxy(i,10);cout<<'_';
  gotoxy(i,18);cout<<'_';
 }
 for(i=26;i<53;i++)
 {
  gotoxy(i,9);cout<<'-';
  gotoxy(i,20);cout<<'-';
 }
 for(i=9;i<=20;i++)
 {
  gotoxy(25,i);cout<<'|';
  gotoxy(53,i);cout<<'|';
  }
 getch();
}*/
				 //-------------
/*void main()                    //ENTRY OF SALE
{                                //-------------
 clrscr();
 char cpny[20];
 for(int i=1,c=2;i<=80;i++,c++)
 {
  gotoxy(i,1);cout<<'-';
  gotoxy(i,24);cout<<'-';
  if(c<24)
  {
   gotoxy(1,c);cout<<'|';
   gotoxy(80,c);cout<<'|';
  }
 }
 gotoxy(30,4);cout<<"SHYAM CYCLE COMPANY";
  for(i=29;i<50;i++)
 {
  gotoxy(i,3);cout<<'-';
  gotoxy(i,5);cout<<'-';
 }
 c=5;i=6;
 gotoxy(i,c+=2);cout<<"ENTER COMPANY NAME :";
 gotoxy(i,c+=2);cout<<"ENTER GST NUMBER :";
 gotoxy(i,c+=2);cout<<"ENTER MODEL NUMBER :";
 gotoxy(i,c+=2);cout<<"ENTER MODEL TYPE :";
 gotoxy(i+=2,++c);cout<<"1 FOR LADIES";
 gotoxy(i,++c);cout<<"2 FOR GENTS";
 gotoxy(i,++c);cout<<"3 FOR KIDS";
 gotoxy(i-=2,c+=2);cout<<"ENTER SIZE :";
 gotoxy(i,c+=2);cout<<"ENTER QUANTITY :";
 gotoxy(i,c+=2);cout<<"ENTER PRICE :";
 gotoxy(27,7);gets(cpny);
// getch();
 }*/
			       //----------------
/*void main()                  //COMPANY WITH GST
{                              //----------------
 clrscr();
 char cpyname[30][30],gstno[30][16];
 int x;;
 cout<<"Enter the number of company:";
 cin>>x;
 for(int i=0;i<x;i++)
  {
   cout<<"Enter company name:";
   gets(cpyname[i]);
   fflush(stdin);
   cout<<"Enter gst number:";
   gets(gstno[i]);
   fflush(stdin);
  }
 clrscr();
 int m=4;
 gotoxy(15,m);cout<<"COMPANY NAME";
 gotoxy(62,m++);cout<<"GST NUMBER";
 gotoxy(15,m);cout<<"------------";
 gotoxy(65,m++);cout<<"----------";
 for(i=0;i<x;i++)
  {
   gotoxy(4,m);
   cout<<cpyname[i];
   cout<<':';
   gotoxy(60,m++);
   cout<<gstno[i];
  }
}   */                                  //------------
/*void main()                           //DISPLAY SALE
{                                       //------------
 clrscr();
 int m=2;
 gotoxy(29,m++);cout<<"|-------------------|";
 gotoxy(29,m++);cout<<"|SHYAM CYCLE COMPANY|";
 gotoxy(29,m);cout<<"|-------------------|";
 gotoxy(1,m);cout<<"Ph.:9415525463";
 gotoxy(58,m++);cout<<"GST NO.:09AGLPA7142E1ZL";
 gotoxy(1,m++);cout<<"Buyer :";
 gotoxy(35,m);cout<<"Buyer's Ph. :";
 gotoxy(1,m++);cout<<"Buyer's GST :";
 gotoxy(1,m++);
 for(int i=0;i<80;i++)
  cout<<'-';
 gotoxy(1,m);cout<<"| PCODE |";
 gotoxy(21,m);cout<<"COMPANY";
 gotoxy(38,m);cout<<'|';
 gotoxy(47,m);cout<<"MODEL";
 gotoxy(60,m);cout<<'|';
 gotoxy(64,m);cout<<"QTY";
 gotoxy(70,m);cout<<'|';
 gotoxy(73,m);cout<<"PRICE";
 gotoxy(80,m++);cout<<'|';
 gotoxy(1,m);
 for(i=0;i<80;i++)
  cout<<'-';
 for(;m<=24;m++)
  {
   gotoxy(1,m);cout<<'|';
   gotoxy(9,m);cout<<'|';
   gotoxy(38,m);cout<<'|';
   gotoxy(60,m);cout<<'|';
   gotoxy(70,m);cout<<'|';
   gotoxy(80,m);cout<<'|';
  }
  gotoxy(2,m--);
  for(i=0;i<78;i++)
  cout<<'-';
  gotoxy(2,--m);
  for(i=0;i<78;i++)
  cout<<'-';
  gotoxy(9,++m);cout<<"CGST= 6%";
  gotoxy(34,m);cout<<"SGST= 6%";
  gotoxy(58,m);cout<<"T O T A L :";
  gotoxy(70,m);cout<<' ';
  gotoxy(69,m);
  getch();
}*/