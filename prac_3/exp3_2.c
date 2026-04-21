#include<stdio.h>
int main(){


int a,b,c;


scanf("%d %d %d",&a,&b,&c);


if ( a > b  && b > c){
printf("large is %d",a);
}else if ( b > a && b > c){
printf("large is %d",b);
}else{
printf("large is %d",c);
}
}


