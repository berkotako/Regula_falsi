#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap_x(float *p1,float *p2);

int main(int argc, char *argv[]) {
	float x_1,x_2,x_new,x_1F,x_2F,x_newF,Epsilon,control_x,control_Fx;
	float *x_1P, *x_2P;
	int n,i,b,counter=0;
	
	printf("ussu giriniz: ");
    scanf("%d",&n);
    int A[n+1];
    
    for(i=0;i<=n;i++){
        printf("X^%d. terimi giriniz: \n",i);
        scanf("%d",&A[i]);
    }
    for(i=0;i<=n;i++){
        printf("X^%d kat sayi: %d\n",i,A[i]);
    }
    printf("\nX_1: ");
    scanf("%f",&x_1);
	printf("\nX_2: ");
    scanf("%f",&x_2);
	printf("\nEpsilon giriniz: ");
    scanf("%f",&Epsilon);
    
	x_1P=&x_1;
    x_2P=&x_2;
    
    //x_1'in daha k���k olmas� gerekti�i i�in kontrol sa�lan�rsa swapping yap�lacak.
    if(x_2<x_1){
    	swap_x(x_1P,x_2P);
	}
    
//verilen x_0 ile polinomun de�erini bulur.
    float fonk_hesap(int us,float x_0){
    	float sonuc = 0;
 	for(b=0;b<=us;b++){
    	sonuc = sonuc + A[b]*pow(x_0,b);
 	}
return sonuc;
}
//ilk de�er atama...
x_1F=fonk_hesap(n,x_1);
x_2F=fonk_hesap(n,x_2);
control_x=fabs(x_1-x_2);
control_Fx=fabs(x_1F-x_2F);

while(control_x >=Epsilon && control_Fx >=Epsilon && counter < 10){
	while(x_1F*x_2F<0 && counter < 10 )  {
    x_new=((x_1*x_2F)-(x_2*x_1F))/(x_2F-x_1F);
    x_newF=fonk_hesap(n,x_new);
    

    if(x_1F*x_newF<0){
        x_2=x_new;
    }
    if(x_newF*x_2F<0){
        x_1=x_new;
    }
    x_1F=fonk_hesap(n,x_1);
    x_2F=fonk_hesap(n,x_2);
    control_Fx=fabs(x_2F-x_1F);
    control_x =fabs(x_2-x_1);
    ++counter;
    
	}
    if(x_1F*x_2F>=0){
    	break;
	}
	++counter;
}
//De�erler ayn� i�aretli ise k�k yoktur.
if(x_1F*x_2F>0){
    	printf("Aralikta kok bulunmuyor.");
	}
//Tam k�k olmas� durumu F(x)=0
else if (x_1F*x_2F==0){
	//Hangileri k�k ?
	if(x_1F==0){
		printf("Tam kok : %f",x_1);
	}
else if (x_2F==0){
		printf("Tam kok : %f",x_2);
	}
}
else{
		printf("Yaklasik kok: %f",x_new);
	}
	return 0;
}
//Swapping fonksiyon
void swap_x(float *x_1P,float *x_2P){
		int T;
		T = *x_1P;
    	*x_1P = *x_2P;
    	*x_2P=T;
}

