#include<stdio.h>
#include<string.h>
struct date{
	int day;
	int month;
	int year;
};
struct cpu
{
	char mdl[100];
	char clock[100];
	int generation;
};
struct lptp{
	char model[100];
	char category[100];
	char series[100];
	cpu spec;
	date release;
	char gpu[100];
	char storage[100];
	char memory[100];
	char screen[100];
	float price;
	char ioport[100];
	char keyboard[100];
	char communication[100];
	char status;
	char os[100];
};
void allRecord(lptp []); 				//LINE #328
void sortByDate(lptp []); 				//LINE #353
void sortByPrice(lptp []);				//LINE #415
void findByModel(lptp []);				//LINE #452
void searchByMinAmount(lptp []);		//LINE #511
void searchByMaxAmount(lptp []);		//LINE #592
void selectSeries(lptp []);				//LINE #670
void selectCategory(lptp []);			//LINE #920
void searchByCPUModel(lptp []);			//LINE #1094
void searchByCPUGeneration(lptp []);	//LINE #1148
void availableModels(lptp []);			//LINE #1200
void selectGPUModel(lptp []);			//LINE #1231
void sortBySeries(lptp []);				//LINE #1524
int main()
{
	printf("Welcome to ASUS Laptop Management Software\n\n");
	lb:
	int choice,check;
	lptp asus[20]={{"PRO 15 UX580GE","PORTABLE","ZENBOOK","i7-8750h","4.80GHz",8,10,01,2018,"NVIDIA GTX 1050TI","1TB SSD","16GB DDR4","15.6 inch TOUCHSCREEN UHD",224000,"2x TYPE C with THUNDERBOLT support,2x USB 3.1,1x HDMI,1x COMBO AUDIO JACK","CHICKLET","WIFI 5,BT 5.0",'A',"WINDOWS 10 HOME"},
	{"UX510UX","PORTABLE","ZENBOOK","i5-6200u","2.80GHz",6,18,6,2017,"NVIDIA GTX 950M","500GB HDD","8GB SDRAM","15.6 inch UHD",168000,"2x USB 3.0, 2x USB 2.0, 1x HDMI, 1x COMBO AUDIO JACK","CHICKLET","WIFI 4,BT 4.1",'N',"WINDOWS 10 HOME"},
	{"14 UX434FLC","PORTABLE","ZENBOOK","i7-10510u","4.90GHz",10,10,12,2019,"NVIDIA MX250","1TB SSD","16GB LPDDR3 RAM","14.0 inch FHD",265000,"2x TYPE C with THUNDERBOLT support, 2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","WIFI 6,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"15 X510UA","PORTABLE","VIVOBOOK","i7-7500u","3.50GHz",7,6,11,2018,"INTEGRATED","1TB HDD + 256GB SSD","8GB SDRAM","15.6 inch FHD",86000,"3x USB 2.0, 1x USB 3.0, 1x HDMI, 1x COMBO AUDIO JACK","CHICKLET","WIFI 5,BT 4.2",'N',"WINDOWS 10 HOME"},
	{"14 U405UA","PORTABLE","VIVOBOOK","i7-7500u","3.50GHz",7,18,11,2018,"INTEGRATED","512GB SSD","8GB DDR4 RAM","14.0 inch FHD",89000,"1x RJ45 LAN Jack, 3x USB 2.0, 1x USB 3.0, 1x HDMI, 1x COMBO AUDIO JACK","CHICKLET","WIFI 5,BT 4.2",'A',"WINDOWS 10 HOME"},
	{"X507UA","EVERYDAY COMPUTING","ASUS LAPTOP SERIES","i7-8550u","4.0GHz",8,2,3,2019,"INTEGRATED","1TB HDD + 128GB SSD","8GB SDRAM","15.6 inch FHD",93000,"1x RJ45 LAN Jack, 2x USB 2.0, 1x USB 3.0, 1x HDMI, 1x COMBO AUDIO JACK","CHICKLET","WIFI 5,BT 4.2",'A',"WINDOWS 10 PRO"},
	{"X407UA","EVERYDAY COMPUTING","ASUS LAPTOP SERIES","i7-8550u","4.0GHz",8,26,2,2019,"INTEGRATED","1TB HDD","8GB SDRAM","14.0 inch FHD",90000,"1x RJ45 LAN Jack, 2x USB 2.0, 1x USB 3.0, 1x HDMI, 1x COMBO AUDIO JACK","CHICKLET","WIFI 5,BT 4.2",'A',"WINDOWS 10 HOME"},
	{"PRO P3540FA","BUSINESS USE","COMMERCIAL SERIES","i7-8565u","4.60GHz",8,17,3,2019,"INTEGRATED","1TB HDD + 256GB SSD","16GB SDRAM","15.6 inch FHD",80000,"1x RJ45 LAN Jack, 2x USB 2.0, 2x USB 3.0, 1x HDMI, 1x COMBO AUDIO JACK","CHICKLET","WIFI 5,BT 4.1",'A',"WINDOWS 10 PRO"},
	{"PRO P2440UA","BUSINESS USE","COMMERCIAL SERIES","i7-7500u","3.50GHz",8,11,11,2018,"INTEGRATED","1TB HDD + 128GB SSD","8GB SDRAM","14.0 inch FHD",71000,"1x RJ45 LAN Jack, 2x USB 2.0, 2x USB 3.0, 1x HDMI, 1x COMBO AUDIO JACK","CHICKLET","WIFI 5,BT 4.1",'A',"WINDOWS 10 PRO"},
	{"EXPERTBOOK P5440FF","BUSINESS USE","COMMERCIAL SERIES","i7-8565u","4.60GHz",8,24,3,2019,"NVIDIA MX130","1TB HDD + 128GB SSD","8GB DDR4 RAM","14.0 inch FHD",110000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack, 2x USB 2.0, 2x USB 3.0, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","WIFI 5,BT 4.2",'A',"WINDOWS 10 PRO"},
	{"14 C425TA","CHROME OS","CHROMEBOOK SERIES","i5-8200y","3.90GHz",8,22,3,2018,"INTEGRATED","128GB eMMC","4GB onboard RAM","14.0 inch FHD",42000,"1x TYPE C 3.0 (THUNDERBOLT), 1x Micro SD card slot, 2x USB 3.0","ILLUMINATED CHICKLET","WIFI 5,BT 5.0",'A',"CHROME"},
	{"FLIP C433TA","CHROME OS","CHROMEBOOK SERIES","i5-8200y","3.90GHz",8,20,3,2018,"INTEGRATED","128GB eMMC","4GB LPDDR3 RAM","14.0 inch FHD",40000,"1x TYPE C 3.0 (THUNDERBOLT), 1x Micro SD card slot, 2x USB 3.0","ILLUMINATED CHICKLET","WIFI 5,BT 4.0",'A',"CHROME"},
	{"G703","HIGH END","ROG (REPUBLIC OF GAMERS)","i9-9750h","4.50GHz",9,25,5,2019,"NVIDIA RTX 2080","1TB SSHD + 256GB SSD","64GB DDR4 RAM","17.3 inch UHD",610000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,1x USB 3.0,3x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"GX501","HIGH END","ROG (REPUBLIC OF GAMERS)","i7-8750h","4.10GHz",8,14,3,2019,"NVIDIA RTX 2070","1TB HDD + 512GB SSD","64GB DDR4 RAM","15.6 inch FHD",505000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,2x USB 3.0,2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"GL702VS","HIGH END","ROG (REPUBLIC OF GAMERS)","i7-8750h","4.10GHz",8,13,1,2019,"NVIDIA GTX 1070","1TB HDD + 512GB SSD","32GB DDR4 RAM","17.3 inch FHD",365000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,2x USB 3.0,2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"STRIX SCAR 2","HIGH END","ROG (REPUBLIC OF GAMERS)","i7-8750h","4.10GHz",8,6,3,2019,"NVIDIA RTX 2070","1TB SSHD + 512GB SSD","64GB DDR4 RAM","17.3 inch UHD",575000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,2x USB 3.0,2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"FX505GT","HIGH END","TUF (THE ULTIMATE FORCE)","i7-9750h","4.50GHz",9,2,3,2019,"NVIDIA GTX 1070","512GB SSD","32GB DDR4 RAM","15.6 inch FHD",390000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,2x USB 3.0,2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"FX505DV","HIGH END","TUF (THE ULTIMATE FORCE)","i9-9750h","4.50GHz",9,8,5,2019,"NVIDIA GTX 1080","1TB SSD","64GB DDR4 RAM","17.3 inch UHD",460000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,2x USB 3.0,2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"FX505DY","HIGH END","TUF (THE ULTIMATE FORCE)","i7-8750h","4.10GHz",8,29,2,2019,"NVIDIA GTX 1080","1TB SSHD + 256GB SSD","32GB DDR4 RAM","15.6 inch FHD",419000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,2x USB 3.0,2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"},
	{"FX705DX","HIGH END","TUF (THE ULTIMATE FORCE)","i7-8750h","4.10GHz",8,22,4,2019,"NVIDIA GTX 1070","512GB SSHD + 512GB SSD","32GB DDR4 RAM","15.6 inch FHD",402000,"1x TYPE C 3.0 (THUNDERBOLT), 1x RJ45 LAN Jack,2x USB 3.0,2x USB 3.1, 1x HDMI, 1x COMBO AUDIO JACK","BACKLIT ILLUMINATED CHICKLET","Gigabit WIFI,BT 5.0",'A',"WINDOWS 10 PRO"}
	};
	
	printf("Enter Your Choice\n");
	printf("1 : All Record\n");
	printf("2 : Sort By Release Date\n");
	printf("3 : Sort By Price\n");
	printf("4 : Find By Laptop Model\n");
	printf("5 : Search By Entering Minimum Amount\n");
	printf("6 : Search By Entering Maximum Amount\n");
	printf("7 : Category\n");
	printf("8 : Series\n");
	printf("9 : Choose CPU Model\n");
	printf("10: Choose CPU Generation\n");
	printf("11: Select GPU\n");
	printf("12: Available Models\n");
	printf("13: Sort By Series\n");
	fflush(stdin);
	choice=choice*0;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: 
		allRecord(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		a:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto a;
		}
			break;
		
		case 2:
		sortByDate(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		b:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto b;
		}
			break;
		case 3:
		sortByPrice(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		c:
			check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto c;
		}
			break;
			
		case 4:
		findByModel(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		d:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto d;
		}
			break;		
		
		case 5:
		searchByMinAmount(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		e:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto e;
		}
			break;
			
		case 6:
		searchByMaxAmount(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		f:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto f;
		}
			break;	
		
		case 7:
		selectCategory(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		g:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto g;
		}
			break;
		
		case 8:
		selectSeries(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		h:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto h;
		}
			break;
		
		case 9:
		searchByCPUModel(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		i:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto i;
		}
			break;
		
		case 10:
		searchByCPUGeneration(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		j:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto j;
		}
			break;	
		
		case 11:
		selectGPUModel(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		k:
			check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto k;
		}
			break;
		
		case 12:
		availableModels(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		l:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto l;
		}
			break;
		
		case 13:
		sortBySeries(asus);
		printf("\n\nif you want to go to main menu press 1 else press 2\n");
		m:
		check=check*0;
		fflush(stdin);
		scanf("%d",&check);
		if(check==1)
		{
			goto lb;
		}
		else if(check!=2)
		{
			printf("Please enter valid number\n");
			goto m;
		}
			break;
			
		default:
			printf("\n\n\nPlease enter valid number\n\n\n");
			goto lb;
	}
}
void allRecord(lptp a[])
{
	
	for(int i=0;i<=19;i++)
	{
		printf("Laptop No. %d\n",i+1);
		printf("Model:\t%s\n",a[i].model);
		printf("Category:  %s\n",a[i].category);
		printf("Series:\t%s\n",a[i].series);
		printf("CPU Model:  %s\n",a[i].spec.mdl);
		printf("CPU Clock:  %s\n",a[i].spec.clock);
		printf("CPU Generation:  %d\n",a[i].spec.generation);
		printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
		printf("GPU:\t%s\n",a[i].gpu);
		printf("Storage:\t%s\n",a[i].storage);
		printf("Memory:\t%s\n",a[i].memory);
		printf("Screen Info:  %s\n",a[i].screen);
		printf("Price:\tRs %.2f\n",a[i].price);
		printf("I/O Ports:  %s\n",a[i].ioport);
		printf("Keyboard Info:  %s\n",a[i].keyboard);
		printf("Communication:  %s\n",a[i].communication);
		printf("Status:\t%c\n",a[i].status);
		printf("Operating System:  %s\n\n\n",a[i].os);
	}
}
void sortByDate(lptp a[])
{
	lptp swap[20];
	for(int k=0;k<=18;k++)
{
	for(int i=0;i<=18;i++)
	{
		if(a[i].release.day<a[i+1].release.day)
		{
		  swap[i]=a[i];
		  a[i]=a[i+1];
		  a[i+1]=swap[i];	
		}
	}
}

	for(int k=0;k<=18;k++)
{
	for(int i=0;i<=18;i++)
	{
		if(a[i].release.month<a[i+1].release.month)
		{
		  swap[i]=a[i];
		  a[i]=a[i+1];
		  a[i+1]=swap[i];	
		}
	}
}
	for(int k=0;k<=18;k++)
{
	for(int i=0;i<=18;i++)
	{
		if(a[i].release.year<a[i+1].release.year)
		{
		  swap[i]=a[i];
		  a[i]=a[i+1];
		  a[i+1]=swap[i];	
		}
	}
}   
for(int i=0;i<=19;i++)
	{
		printf("Laptop No. %d\n",i+1);
		printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
		printf("Model:\t%s\n",a[i].model);
		printf("Category:  %s\n",a[i].category);
		printf("Series:\t%s\n",a[i].series);
		printf("CPU Model:  %s\n",a[i].spec.mdl);
		printf("CPU Clock:  %s\n",a[i].spec.clock);
		printf("CPU Generation:  %d\n",a[i].spec.generation);
		printf("GPU:\t%s\n",a[i].gpu);
		printf("Storage:\t%s\n",a[i].storage);
		printf("Memory:\t%s\n",a[i].memory);
		printf("Screen Info:  %s\n",a[i].screen);
		printf("Price:\tRs %.2f\n",a[i].price);
		printf("I/O Ports:  %s\n",a[i].ioport);
		printf("Keyboard Info:  %s\n",a[i].keyboard);
		printf("Communication:  %s\n",a[i].communication);
		printf("Status:\t%c\n",a[i].status);
		printf("Operating System:  %s\n\n\n",a[i].os);
	}
}
void sortByPrice(lptp a[])
{
	lptp swap[20];
	for(int k=0;k<=18;k++)
{
	for(int i=0;i<=18;i++)
	{
		if(a[i].price>a[i+1].price)
		{
		  swap[i]=a[i];
		  a[i]=a[i+1];
		  a[i+1]=swap[i];	
		}
	}
}
for(int i=0;i<=19;i++)
	{
		printf("Laptop No. %d\n",i+1);
		printf("Price:\tRs %.2f\n",a[i].price);
		printf("Model:\t%s\n",a[i].model);
		printf("Category:  %s\n",a[i].category);
		printf("Series:\t%s\n",a[i].series);
		printf("CPU Model:  %s\n",a[i].spec.mdl);
		printf("CPU Clock:  %s\n",a[i].spec.clock);
		printf("CPU Generation:  %d\n",a[i].spec.generation);
		printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
		printf("GPU:\t%s\n",a[i].gpu);
		printf("Storage:\t%s\n",a[i].storage);
		printf("Memory:\t%s\n",a[i].memory);
		printf("Screen Info:  %s\n",a[i].screen);
		printf("I/O Ports:  %s\n",a[i].ioport);
		printf("Keyboard Info:  %s\n",a[i].keyboard);
		printf("Communication:  %s\n",a[i].communication);
		printf("Status:\t%c\n",a[i].status);
		printf("Operating System:  %s\n\n\n",a[i].os);
	}
}
void findByModel(lptp a[])
{
	lb:
	printf("enter model\nuse only capital letters\n");
	char mdl1[50];
	int check;
	int check1;
	fflush(stdin);
	gets(mdl1);
	for(int i=0;i<=19;i++)
	{
		check=strcmp(mdl1,a[i].model);
		if(check==0)
	{
		printf("model found\nif you want to see full specs press 1\n");
		scanf("%d",&check1);
		if(check1==1)
		{
		printf("Model:\t%s\n",a[i].model);
		printf("Category:  %s\n",a[i].category);
		printf("Series:\t%s\n",a[i].series);
		printf("CPU Model:  %s\n",a[i].spec.mdl);
		printf("CPU Clock:  %s\n",a[i].spec.clock);
		printf("CPU Generation:  %d\n",a[i].spec.generation);
		printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
		printf("GPU:\t%s\n",a[i].gpu);
		printf("Storage:\t%s\n",a[i].storage);
		printf("Memory:\t%s\n",a[i].memory);
		printf("Screen Info:  %s\n",a[i].screen);
		printf("Price:\tRs %.2f\n",a[i].price);
		printf("I/O Ports:  %s\n",a[i].ioport);
		printf("Keyboard Info:  %s\n",a[i].keyboard);
		printf("Communication:  %s\n",a[i].communication);
		printf("Status:\t%c\n",a[i].status);
		printf("Operating System:  %s\n\n\n",a[i].os);
		}
		break;
	}
	}
	if(check!=0)
	{
		printf("model not found\n");
	}
	lc:
		int check2;
	printf("if you want to search another model press 1 else press 2\n");
	fflush(stdin);
	check2=check2*0;
	scanf("%d",&check2);
	if(check2==1)
	{
		goto lb;
	}
	if(check2!=2)
	{
		printf("Please enter valid number\n");
		goto lc;
	}
}
void searchByMinAmount(lptp a[])
{
	lb:
	lptp swap[20];
	float minamnt;
	minamnt=minamnt*0;
	lptp b[20];
	int count=0;
	printf("Enter minimum amount greater than 0\n");
	scanf("%f",&minamnt);
	fflush(stdin);
	if(minamnt<1){
		printf("Please Enter Valid amount\n");
		goto lb;
	}
	for(int i=0;i<=19;i++)
	{
		if(a[i].price>=minamnt)
		{
		b[count]=a[i];
		count++;
		}
	}
	if(count==0)
	{
		printf("no laptop found with price greater than %.2f\n",minamnt);
	}
	if(count>0)
	{
	for(int k=0;k<=count-2;k++)
{
	for(int i=0;i<=count-2;i++)
	{
		if(b[i].price>b[i+1].price)
		{
		  swap[i]=b[i];
		  b[i]=b[i+1];
		  b[i+1]=swap[i];	
		}
	}	
	}
	for(int i=0;i<=count-1;i++)
	{
		printf("Laptop No. %d\n",i+1);
		printf("Price:\tRs %.2f\n",b[i].price);
		printf("Model:\t%s\n",b[i].model);
		printf("Category:  %s\n",b[i].category);
		printf("Series:\t%s\n",b[i].series);
		printf("CPU Model:  %s\n",b[i].spec.mdl);
		printf("CPU Clock:  %s\n",b[i].spec.clock);
		printf("CPU Generation:  %d\n",b[i].spec.generation);
		printf("Release Date:  %d-%d-%d\n",b[i].release.day,b[i].release.month,b[i].release.year);
		printf("GPU:\t%s\n",b[i].gpu);
		printf("Storage:\t%s\n",b[i].storage);
		printf("Memory:\t%s\n",b[i].memory);
		printf("Screen Info:  %s\n",b[i].screen);
		printf("I/O Ports:  %s\n",b[i].ioport);
		printf("Keyboard Info:  %s\n",b[i].keyboard);
		printf("Communication:  %s\n",b[i].communication);
		printf("Status:\t%c\n",b[i].status);
		printf("Operating System:  %s\n\n\n",b[i].os);
	}
}
lc:
		int check2;
		
	printf("If you want to enter price again press 1 else press 2\n");
	fflush(stdin);
	check2=check2*0;
	scanf("%d",&check2);
	if(check2==1)
	{
		goto lb;
	}
	else if(check2!=2)
	{
		printf("Please enter valid number\n");
		goto lc;
	}
	
}
void searchByMaxAmount(lptp a[])
{
	lb:
	lptp swap[20];
	float maxamnt;
	maxamnt=maxamnt*0;
	lptp c[20];
	int count=0;
	printf("Enter maximum amount greater than 0\n");
	scanf("%f",&maxamnt);
	fflush(stdin);
	if(maxamnt<1){
		goto lb;
	}
	for(int i=0;i<=19;i++)
	{
		if(a[i].price<=maxamnt)
		{
		c[count]=a[i];
		count++;
		}
	}
	if(count==0)
	{
		printf("no laptop found with price less than %.2f\n",maxamnt);
	}
	if(count>0)
	{
	for(int k=0;k<=count-2;k++)
{
	for(int i=0;i<=count-2;i++)
	{
		if(c[i].price<c[i+1].price)
		{
		  swap[i]=c[i];
		  c[i]=c[i+1];
		  c[i+1]=swap[i];	
		}
	}	
	}
	for(int i=0;i<=count-1;i++)
	{
		printf("Laptop No. %d\n",i+1);
		printf("Price:\tRs %.2f\n",c[i].price);
		printf("Model:\t%s\n",c[i].model);
		printf("Category:  %s\n",c[i].category);
		printf("Series:\t%s\n",c[i].series);
		printf("CPU Model:  %s\n",c[i].spec.mdl);
		printf("CPU Clock:  %s\n",c[i].spec.clock);
		printf("CPU Generation:  %d\n",c[i].spec.generation);
		printf("Release Date:  %d-%d-%d\n",c[i].release.day,c[i].release.month,c[i].release.year);
		printf("GPU:\t%s\n",c[i].gpu);
		printf("Storage:\t%s\n",c[i].storage);
		printf("Memory:\t%s\n",c[i].memory);
		printf("Screen Info:  %s\n",c[i].screen);
		printf("I/O Ports:  %s\n",c[i].ioport);
		printf("Keyboard Info:  %s\n",c[i].keyboard);
		printf("Communication:  %s\n",c[i].communication);
		printf("Status:\t%c\n",c[i].status);
		printf("Operating System:  %s\n\n\n",c[i].os);
	}
}
lc:
		int check2;
	printf("If you want to enter price again press 1 else press 2\n");
	fflush(stdin);
	check2=check2*0;
	scanf("%d",&check2);
	if(check2==1)
	{
		goto lb;
	}
	else if(check2!=2)
	{
		printf("Please enter valid number\n");
		goto lc;
	}
}
void selectSeries(lptp a[])
{
	lb:
	int num,count;
	num=num*0;
	printf("Select Series\n");
	printf("Press 1 for: Zenbook Series\n");
	printf("Press 2 for: VivoBook Series\n");
	printf("Press 3 for: ASUS Laptop Series\n");
	printf("Press 4 for: Commercial Series\n");
	printf("Press 5 for: ROG (Republic Of Gamers) Series\n");
	printf("Press 6 for: TUF (The Ultimate Force) Series\n");
	printf("Press 7 for: Chromebook Series\n");
	scanf("%d",&num);
	fflush(stdin);
	        if(num==1)
	        {
			char zen[20]="ZENBOOK";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(zen,a[i].series);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(num==2)
	{

			char vivo[9]="VIVOBOOK";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(vivo,a[i].series);
				if(check==0)
				{
					count++;
					printf("Laptop No. %d\n",count);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
	    	}
	}
	else if(num==3)
	{

			char asus1[20]="ASUS LAPTOP SERIES";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(asus1,a[i].series);
				if(check==0)
				{
					count++;
					printf("Laptop No. %d\n",count);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
	    	}
	}
	else if(num==4)
	{

			char commercial[20]="COMMERCIAL SERIES";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(commercial,a[i].series);
				if(check==0)
				{
					count++;
					printf("Laptop No. %d\n",count);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
	    	}
	}
	else if(num==5)
	{

			char rog[30]="ROG (REPUBLIC OF GAMERS)";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(rog,a[i].series);
				if(check==0)
				{
					count++;
					printf("Laptop No. %d\n",count);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
	    	}
	}
	else if(num==6)
	{

			char tuf[30]="TUF (THE ULTIMATE FORCE)";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(tuf,a[i].series);
				if(check==0)
				{
					count++;
					printf("Laptop No. %d\n",count);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
	    	}
	}
	else if(num==7)
	{

			char chrome[30]="CHROMEBOOK SERIES";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(chrome,a[i].series);
				if(check==0)
				{
					count++;
					printf("Laptop No. %d\n",count);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
	    	}
	}
	else
		{
			printf("Please Enter correct number\n");
			goto lb;
		}
}
void selectCategory(lptp a[])
{
	lb:
	int num,count;
	num=num*0;
	printf("Select Category\n");
	printf("Press 1 for: Portable Laptops\n");
	printf("Press 2 for: Everyday Computing Laptops\n");
	printf("Press 3 for: Bussiness Use Laptops\n");
	printf("Press 4 for: High End Laptops\n");
	printf("Press 5 for: Chrome OS Laptops\n");
	fflush(stdin);
	scanf("%d",&num);
	        if(num==1)
	        {
			char port[20]="PORTABLE";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(port,a[i].category);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("Category:  %s\n",a[i].category);
					printf("Series:\t%s\n",a[i].series);
					printf("Model:\t%s\n",a[i].model);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}                                       
		else if(num==2)
	        {
			char every[20]="EVERYDAY COMPUTING";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(every,a[i].category);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("Category:  %s\n",a[i].category);
					printf("Series:\t%s\n",a[i].series);
					printf("Model:\t%s\n",a[i].model);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(num==3)
	        {
			char bussiness[20]="BUSINESS USE";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(bussiness,a[i].category);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("Category:  %s\n",a[i].category);
					printf("Series:\t%s\n",a[i].series);
					printf("Model:\t%s\n",a[i].model);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(num==4)
	        {
			char high[20]="HIGH END";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(high,a[i].category);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("Category:  %s\n",a[i].category);
					printf("Series:\t%s\n",a[i].series);
					printf("Model:\t%s\n",a[i].model);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(num==5)
	        {
			char chrome[20]="CHROME OS";
			count=0;
			for(int i=0;i<=20;i++)
			{
				int check=strcmp(chrome,a[i].category);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("Category:  %s\n",a[i].category);
					printf("Series:\t%s\n",a[i].series);
					printf("Model:\t%s\n",a[i].model);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else
		{
			printf("Please Enter correct number\n");
			goto lb;
		}
}
void searchByCPUModel(lptp a[])
{
	lb:
	printf("Enter CPU model\nuse only small letters\n");
	char mdl1[50];
	int check;
	int check1,count=0;
	fflush(stdin);
	gets(mdl1);
	for(int i=0;i<=19;i++)
	{
		if(strcmp(mdl1,a[i].spec.mdl)==0)
		{
			count++;
		printf("Laptop #%d\n",count);	
		printf("CPU Model:  %s\n",a[i].spec.mdl);
		printf("Laptop Model:\t%s\n",a[i].model);
		printf("Category:  %s\n",a[i].category);
		printf("Series:\t%s\n",a[i].series);
		printf("CPU Clock:  %s\n",a[i].spec.clock);
		printf("CPU Generation:  %d\n",a[i].spec.generation);
		printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
		printf("GPU:\t%s\n",a[i].gpu);
		printf("Storage:\t%s\n",a[i].storage);
		printf("Memory:\t%s\n",a[i].memory);
		printf("Screen Info:  %s\n",a[i].screen);
		printf("Price:\tRs %.2f\n",a[i].price);
		printf("I/O Ports:  %s\n",a[i].ioport);
		printf("Keyboard Info:  %s\n",a[i].keyboard);
		printf("Communication:  %s\n",a[i].communication);
		printf("Status:\t%c\n",a[i].status);
		printf("Operating System:  %s\n\n\n",a[i].os);
		}
	}
	if(count==0)
	{
		printf("model not found\n");
	}
	lc:
	printf("if you want to search another model press 1 else press 2\n");
	fflush(stdin);
	check1=check1*0;
	scanf("%d",&check1);
	if(check1==1)
	{
		goto lb;
	}
	else if(check1!=2)
	{
		printf("Please enter valid number\n");
		goto lc;
	}

}
void searchByCPUGeneration(lptp a[])
{
	lb:
	printf("enter CPU generation\n");
	int gen;
	int check;
	int check1,count=0;
	scanf("%d",&gen);
	for(int i=0;i<=19;i++)
	{
		
		if(a[i].spec.generation==gen)
		{
			count++;
		printf("Laptop #%d\n",count);	
		printf("CPU Generation:  %d\n",a[i].spec.generation);
		printf("CPU Model:  %s\n",a[i].spec.mdl);
		printf("Laptop Model:\t%s\n",a[i].model);
		printf("Category:  %s\n",a[i].category);
		printf("Series:\t%s\n",a[i].series);
		printf("CPU Clock:  %s\n",a[i].spec.clock);
		printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
		printf("GPU:\t%s\n",a[i].gpu);
		printf("Storage:\t%s\n",a[i].storage);
		printf("Memory:\t%s\n",a[i].memory);
		printf("Screen Info:  %s\n",a[i].screen);
		printf("Price:\tRs %.2f\n",a[i].price);
		printf("I/O Ports:  %s\n",a[i].ioport);
		printf("Keyboard Info:  %s\n",a[i].keyboard);
		printf("Communication:  %s\n",a[i].communication);
		printf("Status:\t%c\n",a[i].status);
		printf("Operating System:  %s\n\n\n",a[i].os);
		}
	}
	if(count==0)
	{
		printf("record not found\n");
	}
	lc:
	printf("if you want to search again press 1 else press 2\n");
	scanf("%d",&check1);
	fflush(stdin);
	if(check1==1)
	{
		goto lb;
	}
	if(check1!=2)
	{
		printf("Please enter valid number\n");
		goto lc;
	}
}
void availableModels(lptp a[])
{
	int count=0;
			for(int i=0;i<=19;i++)
			{
				
				if(a[i].status=='A')
				{
					count++;
					printf("Laptop No. %d\n",count);
					printf("Category:  %s\n",a[i].category);
					printf("Series:\t%s\n",a[i].series);
					printf("Model:\t%s\n",a[i].model);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
}
void selectGPUModel(lptp a[])
{
	char ch[2];
	int count;
	lb:
	printf("Select GPU Model\n");
	printf("Press A for: NVIDIA GTX 1050TI\n");
	printf("Press B for: NVIDIA MX250\n");
	printf("Press C for: NVIDIA GTX 1070\n");
	printf("Press D for: NVIDIA GTX 1080\n");
	printf("Press E for: NVIDIA MX130\n");
	printf("Press F for: NVIDIA RTX 2070\n");
	printf("Press G for: NVIDIA RTX 2080\n");
	printf("Press H for: NVIDIA GTX 950M\n");
	printf("Press I for: INTEGRATED GPU\n");
	fflush(stdin);
	gets(ch);
	        if(strcmp(ch,"a")==0 || strcmp(ch,"A")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA GTX 1050TI",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(strcmp(ch,"b")==0 || strcmp(ch,"B")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA MX250",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(strcmp(ch,"c")==0 || strcmp(ch,"C")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA GTX 1070",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(strcmp(ch,"d")==0 || strcmp(ch,"D")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA GTX 1080",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(strcmp(ch,"e")==0 || strcmp(ch,"E")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA MX130",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(strcmp(ch,"f")==0 || strcmp(ch,"F")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA RTX 2070",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(strcmp(ch,"g")==0 || strcmp(ch,"G")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA RTX 2080",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if(strcmp(ch,"h")==0 || strcmp(ch,"H")==0)
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("NVIDIA GTX 950M",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
		else if((strcmp(ch,"i")==0 || strcmp(ch,"I")==0))
	        {
			count=0;
			for(int i=0;i<=19;i++)
			{
				int check=strcmp("INTEGRATED",a[i].gpu);
				if(check==0){
					count++;
					printf("Laptop No. %d\n",count);
					printf("GPU:\t%s\n",a[i].gpu);
					printf("Series:\t%s\n",a[i].series);
					printf("Price:\tRs %.2f\n",a[i].price);
					printf("Model:\t%s\n",a[i].model);
					printf("Category:  %s\n",a[i].category);
					printf("CPU Model:  %s\n",a[i].spec.mdl);
					printf("CPU Clock:  %s\n",a[i].spec.clock);
					printf("CPU Generation:  %d\n",a[i].spec.generation);
					printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
					printf("Storage:\t%s\n",a[i].storage);
					printf("Memory:\t%s\n",a[i].memory);
					printf("Screen Info:  %s\n",a[i].screen);
					printf("I/O Ports:  %s\n",a[i].ioport);
					printf("Keyboard Info:  %s\n",a[i].keyboard);
					printf("Communication:  %s\n",a[i].communication);
					printf("Status:\t%c\n",a[i].status);
					printf("Operating System:  %s\n\n\n",a[i].os);
					
				}
			}
		}
	else
		{
			printf("Please Enter valid choice\n\n\n");
			goto lb;
		}
}
void sortBySeries(lptp a[])
{
	lptp swap[20];
	for(int k=0;k<=18;k++)
{
	for(int i=0;i<=18;i++)
	{
		if(strcmp(a[i].series,a[i+1].series)==1)
		{
		  swap[i]=a[i];
		  a[i]=a[i+1];
		  a[i+1]=swap[i];	
		}
	}
}
for(int i=0;i<=19;i++)
	{
		printf("Laptop No. %d\n",i+1);
		printf("Series:\t%s\n",a[i].series);
		printf("Price:\tRs %.2f\n",a[i].price);
		printf("Model:\t%s\n",a[i].model);
		printf("Category:  %s\n",a[i].category);
		printf("CPU Model:  %s\n",a[i].spec.mdl);
		printf("CPU Clock:  %s\n",a[i].spec.clock);
		printf("CPU Generation:  %d\n",a[i].spec.generation);
		printf("Release Date:  %d-%d-%d\n",a[i].release.day,a[i].release.month,a[i].release.year);
		printf("GPU:\t%s\n",a[i].gpu);
		printf("Storage:\t%s\n",a[i].storage);
		printf("Memory:\t%s\n",a[i].memory);
		printf("Screen Info:  %s\n",a[i].screen);
		printf("I/O Ports:  %s\n",a[i].ioport);
		printf("Keyboard Info:  %s\n",a[i].keyboard);
		printf("Communication:  %s\n",a[i].communication);
		printf("Status:\t%c\n",a[i].status);
		printf("Operating System:  %s\n\n\n",a[i].os);
	}
}
