#include<iostream.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>

int x, y, x1, y1;
float alfa;

void stanga(float unghi)
	{alfa+=unghi*M_PI/180;}

void dreapta(float unghi)
	{alfa-=unghi*M_PI/180;}

void C(float n, float L)
	{if(n==0)
		linerel(int(L*cos(alfa)),int(L*sin(alfa)));
	 else
		{C(n-1,L); dreapta(90);
		 C(n-1,L); stanga(90);
		}
	}

void Dragon(int n, float L, int v)
	{if(n==0)
		linerel(int(L*cos(alfa)),int(L*sin(alfa)));
	 else
		{dreapta(45*v);
		 Dragon(n-1,L,1);
		 stanga(90*v);
		 Dragon(n-1,L,-1);
		 dreapta(45*v);
		}
	}

void Koch(int n, float L)
	{if(n==0)
		linerel(int(L*cos(alfa)),int(L*sin(alfa)));
	 else
		{Koch(n-1,L/3); stanga(60);
		 Koch(n-1,L/3); dreapta(120);
		 Koch(n-1,L/3); stanga(60);
		 Koch(n-1,L/3);
		}
	}

void nucleu_Koch(int n, float L)
	{Koch(n,L); dreapta(120);
	 Koch(n,L); dreapta(120);
	 Koch(n,L); dreapta(120);
	}

void PEANO(int n, float L)
	{if(n==0)
		linerel(int(L*cos(alfa)),int(L*sin(alfa)));
	 else
		{PEANO(n-1,L/3); stanga(90);
		 PEANO(n-1,L/3); dreapta(90);
		 PEANO(n-1,L/3); dreapta(90);
		 PEANO(n-1,L/3); dreapta(90);
		 PEANO(n-1,L/3); stanga(90);
		 PEANO(n-1,L/3); stanga(90);
		 PEANO(n-1,L/3); stanga(90);
		 PEANO(n-1,L/3); dreapta(90);
                 PEANO(n-1,L/3);
		 
		}
	}

void curba_c()
	{int n, L, errorcode, i;
	 char c[25], sw;

	 do{
	 cout<<"Dimensiunea desenului ";
	 cin>>L;

	 cout<<"Factorul de scara ";
	 cin>>n;

	 cout<<"Cum doriti sa colorez desenul?\n";
	 cout<<"- albastru\n- galben\n- rosu\n- verde\n";
	 gets(c);

	  if(strcmp(c,"albastru")==0)
	    i=1;
	   else
	    if(strcmp(c,"verde")==0)
	     i=2;
	    else
	     if(strcmp(c,"rosu")==0)
	      i=4;
	     else
	      if(strcmp(c,"galben")==0)
	       i=14;
	      else
	       i=15;

	 cleardevice();
	 gotoxy(10,2);
	 cout<<"Curba C a lui Levy de dimensiune "<<L<<" si factor de scara "<<n<<" este:";
	 moveto(100,300);
	 setcolor(i);
	 C(n,L);
	 gotoxy(20,25);
	 cout<<"Doriti sa realizati un nou desen? (D/N) ";
	 cin>>sw;
	 cleardevice();
         gotoxy(1,1);
	 }
	 while(sw=='D' || sw=='d');
	 
	}

void dragon()
	{int n, L, i;
	 char x[25], sw;

	 do{
	 cout<<"Varsta dragonului este ";
	 cin>>n;

	 cout<<"Factorul de scara este ";
	 cin>>L;

	 cout<<"Cum doriti sa-l colorati?\n";
         cout<<"- albastru\n- galben\n- rosu\n- verde\n";
	 gets(x);

	  if(strcmp(x,"albastru")==0)
	    i=1;
	   else
	    if(strcmp(x,"verde")==0)
	     i=2;
	    else
	     if(strcmp(x,"rosu")==0)
	      i=4;
	     else
	      if(strcmp(x,"galben")==0)
	       i=14;
	      else
               i=15;

	 cleardevice();

	 moveto(200,250);
	 setcolor(15);
	 gotoxy(12,2);

	 cout<<"Dragonul cu varsta de "<<n<<" ani la un factor de scara "<<L<<" este:";
	 setcolor(i);

	 Dragon(n,L/sqrt(2),1);
	 gotoxy(15,25);
	 cout<<"Doriti sa dati nastere unui nou dragon? (D/N) ";
	 cin>>sw;
	 cleardevice();
         gotoxy(1,1);
	 }while(sw=='D' || sw=='d');

	}

void koch()
	{int n, L, i;
	 char c[25], sw;

	 cleardevice();

	 do{
	 cout<<"Nivelul ";
	 cin>>L;

	 cout<<"Dimensiunea laturi ";
	 cin>>n;

	 cout<<"Cum doriti sa colorez desenul?\n";
	 cout<<"- albastru\n- galben\n- rosu\n- verde\n";
	 gets(c);

	  if(strcmp(c,"albastru")==0)
	    i=1;
	   else
	    if(strcmp(c,"verde")==0)
	     i=2;
	    else
	     if(strcmp(c,"rosu")==0)
	      i=4;
	     else
	      if(strcmp(c,"galben")==0)
	       i=14;
	      else
	       i=15;

	 cleardevice();

	 gotoxy(17,2);
	 cout<<"Fulgul de nea de nivel "<<L<<" si latura "<<n<<" este:";

	 moveto(170,300);
	 setcolor(i);
	 nucleu_Koch(n,L);

	 gotoxy(15,25);
	 cout<<"Doriti sa realizati un nou desen? (D/N) ";
	 cin>>sw;
	 cleardevice();
         gotoxy(1,1);
	 }while(sw=='d' || sw=='D');
	 
	}

void peano()
	{int n, L, i;
	 char c[25], sw;

	 cleardevice();


	 do{
	 cout<<"Nivel ";
	 cin>>n;

	 cout<<"Dimensiune ";
	 cin>>L;

	 cout<<"Cum doriti sa colorez desenul?\n";
	 cout<<"- albastru\n- galben\n- rosu\n- verde\n ";
	 gets(c);

	  if(strcmp(c,"albastru")==0)
	    i=1;
	   else
	    if(strcmp(c,"verde")==0)
	     i=2;
	    else
	     if(strcmp(c,"rosu")==0)
	      i=4;
	     else
	      if(strcmp(c,"galben")==0)
	       i=14;
	      else
	       i=15;

	 cleardevice();

	 gotoxy(15,2);
	 cout<<"Curba lui Peano de nivel "<<n<<" si dimensiune "<<L<<" este:";

	 setcolor(i);
	 moveto(200,200);
	 PEANO(n,L);
	 gotoxy(15,25);
	 cout<<"Doriti sa realizati un nou desen? (D/N) ";
	 cin>>sw;
	 cleardevice();
         gotoxy(1,1);
	 }while(sw=='D' || sw=='d');
	 
	}

void functie_gr2()
{  int prev_x, prev_y, a, b, c;
   float end_x, end_y, x, y, x_varf, y_varf, x_varf1, y_varf1, x1, x2, xp, yp, delta;
   char sw, sw2;
   
  do{

  prev_x=0; prev_y=0;
  end_x=639; end_y=479;
  x=10; y=10;

  gotoxy(20,2);
  cout<<"Functia de gradul al II-lea\n\n";
  cout<<"a="; cin>>a;
  cout<<"b="; cin>>b;
  cout<<"c="; cin>>c; cout<<"\n";

  delta=b*b-4*a*c;
  x_varf=((-b)/2*a);
  y_varf=((-delta)/4*a);

  x_varf1=x_varf*30;
  y_varf1=y_varf*30;

  xp=((-b)/2*a);
  yp=((-delta)/4*a);

  if(delta>=0)
	{x1=(-b+sqrt(delta))/2*a;
	 x2=(-b-sqrt(delta))/2*a;}

  cout<<"Functia introdusa este f(x) = "<<a<<"x^2 + "<<b<<"x + "<<c<<"\n\n";

  if(delta==0)
		cout<<"Ecuatia are o singura solutie reala x = "<<x1;
	else
		if(delta>0)
			cout<<"Ecuatia are doua solutii reale distincte x1 = "<<x1<<" si x2 = "<<x2;
		else
			  if(delta<0)
				  cout<<"Ecuatia nu are solutii reale";

  cout<<"\nVarful parabolei are coordonatele V("<<(-b/2*a)<<","<<(-delta/4*a)<<")";


  cout<<"\n\n         Tabelul de variatie este";

  gotoxy(3,15);
  cout<<"x";
  gotoxy(1,17);
  cout<<"f(x)";

  if(delta==0)
	{
	 gotoxy(20,15);
	 cout<<xp;
	 gotoxy(30,15);
	 cout<<x1;

	 if(a<0)
		{gotoxy(8,17);
		 cout<<"- - - - - -   - - - - - - - - - - -";}
	 else
		{gotoxy(8,17);
		 cout<<"+ + + + + +   + + + + + + + + + + +";}

	 gotoxy(20,17);
	 cout<<yp;
	 gotoxy(30,17);
	 cout<<"0";
	 }

  if(delta>0)
	{if((x1<x2)){
	 gotoxy(15,15);
	 cout<<x1;
	 gotoxy(25,15);
	 cout<<xp;
	 gotoxy(35,15);
	 cout<<x2;

	 if(a>0)
		{gotoxy(8,17);
		 cout<<"+ + +  - - - - - - - - - -   + + +";}
	 else
		{gotoxy(8,17);
		 cout<<"- - -  + + + + + + + + + +   - - -";}

	 gotoxy(15,17);
	 cout<<"0";
	 gotoxy(25,17);
	 cout<<yp;
	 gotoxy(35,17);
	 cout<<"0";}

	 if(x1>x2){
	 gotoxy(15,15);
	 cout<<x2;
	 gotoxy(25,15);
	 cout<<xp;
	 gotoxy(35,15);
	 cout<<x1;

	 if(a>0)
		{gotoxy(8,17);
		 cout<<"+ + +  - - - - - - - - - -   + + +";}
	 else
		{gotoxy(8,17);
		 cout<<"- - - - - - -  + + + + + +   - - -";}

	 gotoxy(15,17);
	 cout<<"0";
	 gotoxy(25,17);
	 cout<<yp;
	 gotoxy(35,17);
	 cout<<"0";}

	 }


  if(delta<0)
     {gotoxy(23,15);
      cout<<xp;

      if(a>=0)
	      {gotoxy(8,17);
	       cout<<" + + + + + + +   + + + + + + + +";}
      else
	      {gotoxy(8,17);
	       cout<<" - - - - - - -    - - - - - - -";}

      gotoxy(23,17);
      cout<<yp;}

  line(1,245,350,245);
  line(40,220,40,280);

  gotoxy(1,20);

  cout<<"Doriti sa afiesez graficul functiei introduse? (D/N) ";
  cin>>sw;

  if(sw=='D' || sw=='d'){

  cleardevice();
  gotoxy(1,1);
  cout<<"Graficul functiei\nf(x) = "<<a<<"x^2 + "<<b<<"x + "<<c;


  delay(2000);
  if((end_y/2+y_varf1)<=end_x)
	line(x,end_y/2+(y_varf1),end_x,end_y/2+(y_varf1));

  if((end_x/2-x_varf1)<=end_y)
	line(end_x/2-(x_varf1),y,end_x/2-(x_varf1),end_y);



if (a>0) {
for (x=-1*(int)(end_x/2); x<(int)(end_x/2); x+=.001)
{
// valori parabola
y = .03*(x*x);


//putpixel((int)(end_x-x) - (int)(end_x/2.0), (int)(end_y-y) - (int)(end_y/2.0), WHITE);
line((int)(end_x-x) - (int)(end_x/2.0), (int)(end_y-y) - (int)(end_y/2.0), prev_x, prev_y);

//cand folosim line() trebuie sa retinem valorile anterioare x,y
prev_x = (int)(end_x - x) - (int)(end_x/2.0);
prev_y = (int)(end_y - y) - (int)(end_y/2.0);
}
}
else if (a<0) {
for (x=-1*(int)(end_x/2); x<(int)(end_x/2); x+=.001)
{y = .03*(x*x);
putpixel((int)(end_x+x) - (int)(end_x/2.0), (int)(end_y+y) - (int)(end_y/2.0), WHITE);
}}
  }


gotoxy(1,25);
cout<<"Doriti sa introduceti\no alta functie? (D/N) ";
cin>>sw2;
cleardevice();
}while(sw2=='d' || sw2=='D');

	
}

void joc()
{ int zar_1, zar_2, zar_3, zar_4, zar_5, nr_petale, petale, k, scor_total=0;
  char cuv, inceput;


  setbkcolor(BLUE);

  gotoxy(27,2);
  cout<<"Doriti sa incepeti jocul? (D/N) ";
  cin>>inceput;

  if(inceput=='d' || inceput=='D')
	{
	while(inceput=='d' || inceput=='D')
	{nr_petale=0;

	  rectangle(20,40,123,143);
	  rectangle(143,40,246,143);
	  rectangle(266,40,369,143);
	  rectangle(389,40,492,143);
	  rectangle(512,40,615,143);

	  gotoxy(20,11);
	  cout<<"Indicatii:";
	  gotoxy(20,12);
	  cout<<"- numele jocului ARE legatura cu rezolvarea lui;";
	  gotoxy(20,13);
	  cout<<"- rezultatul poate fi 0 sau un numar par;";
	  gotoxy(20,14);
	  cout<<"- puteti afla rezultatul corect atunci cand doriti.";

  /* initial,ize random seed: */
  srand (time(NULL));

  /* generate random number between 1 and 6: */
  zar_1 = rand() % 6 + 1;
  if(zar_1%2!=0)
	  nr_petale+=zar_1-1;

  zar_2 = rand() % 6 + 1;
  if(zar_2%2!=0)
	  nr_petale+=zar_2-1;

  zar_3 = rand() % 6 + 1;
  if(zar_3%2!=0)
	  nr_petale+=zar_3-1;

  zar_4 = rand() % 6 + 1;
  if(zar_4%2!=0)
	  nr_petale+=zar_4-1;

  zar_5 = rand() % 6 + 1;
  if(zar_5%2!=0)
	  nr_petale+=zar_5-1;

  switch (zar_1)
	{
	case 1: {// - Zarul 1 - Valoarea 1 - //
			circle(70,90,7);
			floodfill(70,90,WHITE);
			} break;

	case 2: {// - Zarul 1 - Valoarea 2 - //
			circle(40,123,7);
			floodfill(40,123,WHITE);
			circle(103,60,7);
			floodfill(103,60,WHITE);
			} break;

	case 3: {// - Zarul 1 - Valoarea 3 - //
			circle(40,123,7);
			floodfill(40,123,WHITE);
			circle(70,90,7);
			floodfill(70,90,WHITE);
			circle(103,60,7);
			floodfill(103,60,WHITE);
			} break;

	case 4: {// - Zarul 1 - Valoarea 4 - //
			circle(40,123,7);
			floodfill(40,123,WHITE);
			circle(40,60,7);
			floodfill(40,60,WHITE);
			circle(103,60,7);
			floodfill(103,60,WHITE);
			circle(103,123,7);
			floodfill(103,123,WHITE);
			} break;

	case 5: {// - Zarul 1 - Valoarea 5 - //
			circle(40,123,7);
			floodfill(40,123,WHITE);
			circle(40,60,7);
			floodfill(40,60,WHITE);
			circle(70,90,7);
			floodfill(70,90,WHITE);
			circle(103,60,7);
			floodfill(103,60,WHITE);
			circle(103,123,7);
			floodfill(103,123,WHITE);
			} break;

	case 6: {// - Zarul 1 - Valoarea 6 - //
			circle(40,60,7);
			floodfill(40,60,WHITE);
			circle(103,123,7);
			floodfill(103,123,WHITE);
			circle(103,60,7);
			floodfill(103,60,WHITE);
			circle(40,123,7);
			floodfill(40,123,WHITE);
			circle(103,90,7);
			floodfill(103,90,WHITE);
			circle(40,90,7);
			floodfill(40,90,WHITE);
			} break;
	}

   switch (zar_2)
	{
	case 1: {// - Zarul 2 - Valoarea 1 - //
			circle(193,90,7);
			floodfill(193,90,WHITE);
			} break;

	case 2: {// - Zarul 2 - Valoarea 2 - //
			circle(163,123,7);
			floodfill(163,123,WHITE);
			circle(226,60,7);
			floodfill(226,60,WHITE);
			} break;

	case 3: {// - Zarul 2 - Valoarea 3 - //
			circle(163,123,7);
			floodfill(163,123,WHITE);
			circle(193,90,7);
			floodfill(193,90,WHITE);
			circle(226,60,7);
			floodfill(226,60,WHITE);
			} break;

	case 4: {// - Zarul 2 - Valoarea 4 - //
			circle(163,123,7);
			floodfill(163,123,WHITE);
			circle(226,60,7);
			floodfill(226,60,WHITE);
			circle(226,123,7);
			floodfill(226,123,WHITE);
			circle(163,60,7);
			floodfill(163,60,WHITE);
			} break;

	case 5: {// - Zarul 2 - Valoarea 5 - //
			circle(163,123,7);
			floodfill(163,123,WHITE);
			circle(226,60,7);
			floodfill(226,60,WHITE);
			circle(193,90,7);
			floodfill(193,90,WHITE);
			circle(226,123,7);
			floodfill(226,123,WHITE);
			circle(163,60,7);
			floodfill(163,60,WHITE);
			} break;

	case 6: {// - Zarul 2 - Valoarea 6 - //
			circle(163,123,7);
			floodfill(163,123,WHITE);
			circle(226,60,7);
			floodfill(226,60,WHITE);
			circle(163,90,7);
			floodfill(163,90,WHITE);
			circle(226,90,7);
			floodfill(226,90,WHITE);
			circle(226,123,7);
			floodfill(226,123,WHITE);
			circle(163,60,7);
			floodfill(163,60,WHITE);
			} break;
	}

    switch (zar_3)
	{
	case 1: {// - Zarul 3 - Valoarea 1 - //
			circle(316,90,7);
			floodfill(316,90,WHITE);
			} break;

	case 2: {// - Zarul 3 - Valoarea 2 - //
			circle(286,123,7);
			floodfill(286,123,WHITE);
			circle(349,60,7);
			floodfill(349,60,WHITE);
			} break;

	case 3: {// - Zarul 3 - Valoarea 3 - //
			circle(286,123,7);
			floodfill(286,123,WHITE);
			circle(316,90,7);
			floodfill(316,90,WHITE);
			circle(349,60,7);
			floodfill(349,60,WHITE);
			} break;

	case 4: {// - Zarul 3 - Valoarea 4 - //
			circle(286,123,7);
			floodfill(286,123,WHITE);
			circle(286,60,7);
			floodfill(286,60,WHITE);
			circle(349,60,7);
			floodfill(349,60,WHITE);
			circle(349,123,7);
			floodfill(349,123,WHITE);
			} break;

	case 5: {// - Zarul 3 - Valoarea 5 - //
			circle(286,123,7);
			floodfill(286,123,WHITE);
			circle(286,60,7);
			floodfill(286,60,WHITE);
			circle(316,90,7);
			floodfill(316,90,WHITE);
			circle(349,60,7);
			floodfill(349,60,WHITE);
			circle(349,123,7);
			floodfill(349,123,WHITE);
			} break;

	case 6: {// - Zarul 3 - Valoarea 6 - //
			circle(286,123,7);
			floodfill(286,123,WHITE);
			circle(286,60,7);
			floodfill(286,60,WHITE);
			circle(286,90,7);
			floodfill(286,90,WHITE);
			circle(349,60,7);
			floodfill(349,60,WHITE);
			circle(349,123,7);
			floodfill(349,123,WHITE);
			circle(349,90,7);
			floodfill(349,90,WHITE);
			} break;
	}

	 switch (zar_4)
	{
	case 1: {// - Zarul 4 - Valoarea 1 - //
			circle(439,90,7);
			floodfill(439,90,WHITE);
			} break;

	case 2: {// - Zarul 4 - Valoarea 2 - //
			circle(409,123,7);
			floodfill(409,123,WHITE);
			circle(472,60,7);
			floodfill(472,60,WHITE);
			} break;

	case 3: {// - Zarul 4 - Valoarea 3 - //
			circle(409,123,7);
			floodfill(409,123,WHITE);
			circle(439,90,7);
			floodfill(439,90,WHITE);
			circle(472,60,7);
			floodfill(472,60,WHITE);
			} break;

	case 4: {// - Zarul 4 - Valoarea 4 - //
			circle(409,123,7);
			floodfill(409,123,WHITE);
			circle(409,60,7);
			floodfill(409,60,WHITE);
			circle(472,60,7);
			floodfill(472,60,WHITE);
			circle(472,123,7);
			floodfill(472,123,WHITE);
			} break;

	case 5: {// - Zarul 4 - Valoarea 5 - //
			circle(409,123,7);
			floodfill(409,123,WHITE);
			circle(409,60,7);
			floodfill(409,60,WHITE);
			circle(439,90,7);
			floodfill(439,90,WHITE);
			circle(472,60,7);
			floodfill(472,60,WHITE);
			circle(472,123,7);
			floodfill(472,123,WHITE);
			} break;

	case 6: {// - Zarul 4 - Valoarea 6 - //
			circle(409,123,7);
			floodfill(409,123,WHITE);
			circle(409,60,7);
			floodfill(409,60,WHITE);
			circle(409,90,7);
			floodfill(409,90,WHITE);
			circle(472,60,7);
			floodfill(472,60,WHITE);
			circle(472,123,7);
			floodfill(472,123,WHITE);
			circle(472,90,7);
			floodfill(472,90,WHITE);
			} break;
	}

	 switch (zar_5)
	{
	case 1: {// - Zarul 5 - Valoarea 1 - //
			circle(562,90,7);
			floodfill(562,90,WHITE);
			} break;

	case 2: {// - Zarul 5 - Valoarea 2 - //
			circle(532,123,7);
			floodfill(532,123,WHITE);
			circle(595,60,7);
			floodfill(595,60,WHITE);
			} break;

	case 3: {// - Zarul 5 - Valoarea 3 - //
			circle(532,123,7);
			floodfill(532,123,WHITE);
			circle(562,90,7);
			floodfill(562,90,WHITE);
			circle(595,60,7);
			floodfill(595,60,WHITE);
			} break;

	case 4: {// - Zarul 5 - Valoarea 4 - //
			circle(532,123,7);
			floodfill(532,123,WHITE);
			circle(532,60,7);
			floodfill(532,60,WHITE);
			circle(595,60,7);
			floodfill(595,60,WHITE);
			circle(595,123,7);
			floodfill(595,123,WHITE);
			} break;

	case 5: {// - Zarul 5 - Valoarea 5 - //
			circle(532,123,7);
			floodfill(532,123,WHITE);
			circle(532,60,7);
			floodfill(532,60,WHITE);
			circle(562,90,7);
			floodfill(562,90,WHITE);
			circle(595,60,7);
			floodfill(595,60,WHITE);
			circle(595,123,7);
			floodfill(595,123,WHITE);
			} break;

	case 6: {// - Zarul 5 - Valoarea 6 - //
			circle(532,123,7);
			floodfill(532,123,WHITE);
			circle(532,90,7);
			floodfill(532,90,WHITE);
			circle(532,60,7);
			floodfill(532,60,WHITE);
			circle(595,60,7);
			floodfill(595,60,WHITE);
			circle(595,90,7);
			floodfill(595,90,WHITE);
			circle(595,123,7);
			floodfill(595,123,WHITE);
			} break;
	 }
	gotoxy(1,15);
	cout<<"\nCat de multe petale sunt in jurul trandafirului?";
	cout<<"\nDoriti sa afisez rezultatul pentru a va orienta? (D/N) ";
	cin>>cuv;

	if(cuv=='d' || cuv=='D')
		k=0;
	else
		k=1;

	if(k==0)
		cout<<"\nNumarul petalelor este "<<nr_petale;
		
        
	if(k){
		cout<<"\nIntoduceti numarul de petale din jurul trandafirului\nNumar petale=";
		cin>>petale;

		if(petale==nr_petale)
			{cout<<"\nCORECT! Numarul petalelor este "<<nr_petale;
			 scor_total++;}
		else
			{cout<<"\nGRESIT! Numarul petalelor este "<<nr_petale;
                         scor_total--;}
		}

	cout<<"\nDoriti sa continuati jocul (D/N)? ";
	cin>>inceput;
	cleardevice();
	gotoxy(30,2);
	cout<<"Petalele Trandafirului";
  }

  }
  else
	 cout<<"\n        INSPIRATIE! "<<'\2';


}


void main(){

int i, errorcode, optiune;

 int gdriver = DETECT, gmode;

	 initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");
	 errorcode=graphresult();

	 while(errorcode)
	{cout<<"Eroare la placa grafica. Verificati fisierele BGI";
	 getch();
	 exit(1);
	}


  char ATESTAT[]="ATESTAT INFORMATICA", AUTOR[]="ISPAS ADRIAN, XII-B", OPTIUNE[]="Optiunea dvs: ",
  OPT1[]="1. Curba lui Koch", OPT2[]="2. Curba lui Peano", OPT3[]="3. Curba C", OPT4[]="4. Curba dragonului", OPT5[]="5. Functia de gradul II", OPT6[]="6. Joc", OPT7[]="7. Inchide aplicatia";


  do{
	setbkcolor(RED);
	rectangle(0,1,getmaxx(),getmaxy());
	setfillstyle(SOLID_FILL,0);
	bar(165,115,494,344);
	setfillstyle(SOLID_FILL,BLUE);
	bar(150,100,479,329);
	rectangle(149,99,480,330);


	outtextxy(235, 110, ATESTAT);
	outtextxy(325, 315, AUTOR);
	outtextxy(165, 140, OPT1);
	outtextxy(165, 160, OPT2);
	outtextxy(165, 180, OPT3);
	outtextxy(165, 200, OPT4);
	outtextxy(165, 220, OPT5);
	outtextxy(165, 240, OPT6);
	outtextxy(165, 260, OPT7);
	outtextxy(165, 292, OPTIUNE);

	gotoxy(35,19);
	cin>>optiune;

switch(optiune){

case 1: {cleardevice();
	 gotoxy(1,1);
	 setbkcolor(BLACK);
	 koch();
	 i=1;
	 setcolor(WHITE);
	 break;}

case 2: {cleardevice();
	 gotoxy(1,1);
	 setbkcolor(BLACK);
	 peano();
	 i=1;
	 setcolor(WHITE);
	 break;}

case 3: {cleardevice();
	 gotoxy(1,1);
	 setbkcolor(BLACK);
	 curba_c();
	 i=1;
	 setcolor(WHITE);
	 break;}

case 4: {cleardevice();
	 gotoxy(1,1);
	 setbkcolor(BLACK);
	 dragon();
	 i=1;
	 setcolor(WHITE);
	 break;}

case 5: {cleardevice();
	 gotoxy(1,1);
	 setbkcolor(BLACK);
	 functie_gr2();
	 i=1;
	 setcolor(WHITE);
	 break;}

case 6: {cleardevice();
	 gotoxy(1,1);
	 setbkcolor(BLACK);
	 joc();
	 i=1;
	 setcolor(WHITE);
	 cleardevice();
	 break;}

case 7: {i=0; exit(1);}

break;

}

}while(i==1);

getch();

}

