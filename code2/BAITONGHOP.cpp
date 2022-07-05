#include <stdio.h>
#include <math.h>
#include <string.h>
struct date {
	int ngay;
	int thang;
	int nam;
};

struct player {
	char MS[10];
	char hodem[30];
	char ten[10];
	int soao;
	date DOB;
};

player nhap(player DS[], int &n) {
	printf("Nhap so cau thu: ");
	do{
		scanf("%d", &n);
		if(n<=0||n>50) printf("Nhap lai!\n");
	}while(n<=0||n>50);
	for(int i=0;i<n;i++){
		printf("\n\nNhap du lieu cau thu %d\n",i+1);
		printf("Nhap MS: ");scanf("%s",&DS[i].MS);
		fflush(stdin);
		printf("Nhap Ho dem: ");gets(DS[i].hodem);
		printf("Nhap ten: ");scanf("%s",&DS[i].ten);
		printf("Nhap so ao: ");scanf("%d",&DS[i].soao);
		do {
			printf("Nhap ngay thang/nam/sinh: ");scanf("%d/%d/%d",&DS[i].DOB.ngay,&DS[i].DOB.thang,&DS[i].DOB.nam);
			if(DS[i].DOB.ngay<=0 || DS[i].DOB.thang<=0 || DS[i].DOB.nam<0 ||DS[i].DOB.ngay>31 || DS[i].DOB.thang>12)
				printf("Nhap lai!\n");
		}while(DS[i].DOB.ngay<=0 || DS[i].DOB.thang<=0 || DS[i].DOB.nam<0 ||DS[i].DOB.ngay>31 || DS[i].DOB.thang>12);
	}
}
void in(player DS[], int i) {
	printf("%s\t\t|%15s |%10s |%6d |%5d/%d/%d\t|\n",DS[i].MS,DS[i].hodem,DS[i].ten,DS[i].soao,DS[i].DOB.ngay,DS[i].DOB.thang,DS[i].DOB.nam);
	printf("-------------------------------------------------------------------------\n");		
}
player xuat(player DS[], int i) {
	printf("Ma cau thu      |     Ho dem     |    Ten    | So ao |      Nam sinh    |\n");
	printf("-------------------------------------------------------------------------\n");
	for (int n=0;n<i;n++){
		in(DS,n);
	}
}
player xuattep(player DS[], int n) {
	FILE *fop=fopen("xuat.csv", "w");
	fprintf(fop,"Ma cau thu,Ho dem,Ten,So ao,Nam sinh\n");
	for(int i=0; i<n ; i++) {
		fprintf(fop,"%s,%s,%s,%d,%d/%d/%d\n",DS[i].MS,DS[i].hodem,DS[i].ten,DS[i].soao,DS[i].DOB.ngay,DS[i].DOB.thang,DS[i].DOB.nam);
	}
	fclose(fop);
}
player mintuoi(player DS[], int i) {
	int minnam = DS[0].DOB.nam;
	int j;
	for(int k=0;k<i;k++) {
		if(minnam<DS[k].DOB.nam)
			minnam=DS[k].DOB.nam;
	}
	printf("Ma cau thu      |     Ho dem     |    Ten    | So ao |      Nam sinh    |\n");
	printf("-------------------------------------------------------------------------\n");
	for (j=0;j<i;j++) {
		if(minnam==DS[j].DOB.nam)
			in(DS,j);
	}
}
player nhap1cauthu(player *p) {
		printf("Nhap MS: ");
		scanf("%s", &p->MS);
		fflush(stdin);
		printf("Nhap hodem: ");
		gets(p->hodem);
		printf("Nhap ten: ");
		scanf("%s",&p->ten);
		printf("Nhap so ao:");
		scanf("%d",&p->soao);
		do {
			printf("Nhap ngay/thang/nam: ");
			scanf("%d/%d/%d", &p->DOB.ngay,&p->DOB.thang,&p->DOB.nam);
			if(p->DOB.ngay<=0 || p->DOB.thang<=0 || p->DOB.nam<0 ||p->DOB.ngay>31 || p->DOB.thang>12)
				printf("Nhap lai!: ");
		}while(p->DOB.ngay<=0 || p->DOB.thang<=0 || p->DOB.nam<0 ||p->DOB.ngay>31 || p->DOB.thang>12);
}
player them(player DS[], int &n, player *p) {
	p=&DS[n];
	nhap1cauthu(p);
	n++;
}

// void swap(player &a, player &b){
//  	player tmp = a;
//  	a = b;
//  	b = tmp;
// }

// void giamdan(player DS[], int i) {
// 	for (int j=0;j<i;j++){
// 		if(DS[i].DOB.nam>DS[i+1].DOB.nam)
// 			swap(DS[i], DS[i+1]);
// 		else if(DS[i].DOB.thang>DS[i+1].DOB.thang)
// 			swap(DS[i], DS[i+1]);
// 		else if(DS[i].DOB.ngay>DS[i+1].DOB.ngay)
// 			swap(DS[i], DS[i+1]);
// 	}
// }

player xoacauthu(player DS[], int &n) {
	char z[50];
	int k=0;
	del:
	printf("\nNhap MS muon xoa: ");
	scanf("%s", &z);
	for(int i=0; i<n;i++) {
		if(strcmp(z,DS[i].MS)==0) {
			for(int j=i;j<n;j++){
				strcpy(DS[j].MS,DS[j+1].MS);
				strcpy(DS[j].hodem,DS[j+1].hodem);
				strcpy(DS[j].ten,DS[j+1].ten);
				DS[j].DOB.ngay=DS[j+1].DOB.ngay;
				DS[j].DOB.thang=DS[j+1].DOB.thang;
				DS[j].DOB.nam=DS[j+1].DOB.nam;
			}
			k++;
			n--;
		}
	}
	if(k==0) {
		printf("Khong co MS nay!");
		goto del;
	}
}
player chinhsua(player DS[], int n) {
	char m[50];
	int k=0;
	update:
	printf("\nNhap MS muon sua: ");
	scanf("%s", &m);
	for(int i=0; i<n;i++) {
		if(strcmp(m,DS[i].MS)==0) {
			printf("Nhap id moi: ");scanf("%s",&DS[i].MS);
			fflush(stdin);
			printf("Nhap Ho dem moi: ");gets(DS[i].hodem);
			printf("Nhap ten moi: ");scanf("%s",&DS[i].ten);
			printf("Nhap so ao moi: ");scanf("%d",&DS[i].soao);
			printf("Nhap ngay thang/nam/sinh: ");scanf("%d/%d/%d",&DS[i].DOB.ngay,&DS[i].DOB.thang,&DS[i].DOB.nam);
			k++;
			break;
		}
	}
	if(k==0) {
		printf("Khong co MS nay!");
		goto update;
	}
}
int main() {
	player DS[100];
	int i=0;
	player *p=NULL;
	p=&DS[0];
	nhap(DS,i);
	printf("        				*CHUONG TRINH QUAN LY CAU THU\n");
	printf("				*************************MENU**************************\n");
	printf("				**  1. Hien thi danh sach cau thu                    **\n");
	printf("				**  2. Xuat danh sach cau thu ra file csv.           **\n");
	printf("				**  3. Them mot cau thu moi.                         **\n");
	printf("				**  4. Xoa mot cau thu.                              **\n");
	printf("				**  5. Cap nhat thong tin cau thu.                   **\n");
	printf("				**  6. Cap nhat (lua) danh sach.                     **\n");
	printf("				**  7. Sap xep cac danh sach theo cac tuy chon.      **\n");
	printf("				**  8. Thoat.      									 **\n");
	printf("				*************************MENU**************************\n");
	Nhap:
	printf("Nhap tuy chon: ");
	int n;
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		printf("\tXuat danh sach\n");
		xuat(DS,i);
		goto Nhap;
	case 2:
		printf("\tXuat danh sach ra file\n");
		xuattep(DS,i);
		goto Nhap;
	case 3:
		printf("\n\n\t\tNhap them 1 cau thu \n");
		them(DS,i,p);
		goto Nhap;
	case 4:
		printf("\n\n\t\tXoa 1 cau thu \n");
		xoacauthu(DS,i);
		goto Nhap;
	case 5:
		printf("\n\n\t\tChinh sua 1 cau thu \n");
		chinhsua(DS,i);
		goto Nhap;
	case 6:
		goto Nhap;
	case 7:
		int j;
		printf("Nhap lua chon: ");
		scanf("%d",&j);
		goto Nhap;
	case 8:
		printf("\n\t\t---------Thoat---------");
		break;
	default:
		goto Nhap;
	}
	//printf("\n\t\tTuoi nho nhat\n");
	//mintuoi(DS,i);
	//printf("\n\t\t\t\tSap xep giam dan\n");
	//giamdan(DS,i);
	return 0;
} 