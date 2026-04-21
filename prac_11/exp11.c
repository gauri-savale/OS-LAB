#include<stdio.h>
int main(){
int n,i,j;
printf("Enter no of pages");
scanf("%d",&n);

int pages[n];
printf("enter page refernce :");
for(i=0;i<n;i++){
scanf("%d",&pages[i]);
}
int frames;
printf("Enter no of frames");
scanf("%d",&frames);
int frame[frames];
int page_faults=0;
int index = 0;
int found;
for(i=0;i<n;i++){
frame[i] = -1;
}
printf("\npage\tframe\n");
for(i=0;i<n;i++){
found = 0;
for(j=0;j<frames;j++){
if(frame[j] == pages[i]){
found =1;
break;
}
}
if(found == 0){
frame[index] = pages[i];
index = (index+ 1) % frames;
page_faults++;
}

printf("%d\t",pages[i]);
for(j=0;j<frames;j++){
if(frame[j] != -1){
printf("%d ",frame[j]);
}
else{
printf("- ");
}
}
printf("\n");
}
printf("Total page fautls = %d\n",page_faults);
}

