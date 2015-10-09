#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main(int argc,char *argv[]){
	

	int length=0, arr[100],j=0,i=0;
	pid_t pid;
	char c;
	FILE *fp = NULL;

	length = argc-1;
	if(argc<=1){
		printf("usage : ./a.out 1 2 3 4 5 6 .... N;");
		return 0;
	}

	/* code to convert string to integer*/
	fp = fopen("temp.txt","w+");
	for(i=1;i<argc;i++){
		fprintf(fp,"%s ",argv[i]);
	}
	rewind(fp);
	for(i=0;i<(argc-1);i++){
		fscanf(fp,"%d",&arr[i]);

	}
	fclose(fp);

	/*printf("enter number");
	while(length!=10){
			scanf("%d",&value);
			if(value==0) break;
			arr[length]=value;
			length++;
	}*/

	pid = fork();

	if(pid<0){
		printf("child creation failed");
		exit(0);
	}
 	else if(pid > 0){
 		//char s[100];
		wait(0);
		fp = fopen("temp.txt","r");
		while((c=fgetc(fp))!=EOF){
			printf("%c",c);
		}
	}
	else if(pid == 0){
		fp = fopen("temp.txt","w+");
		// print even
		fprintf(fp,"%s\n","even");
		for(i=0;i<length;i++){
			if(arr[i] % 2 == 0 )
				fprintf(fp," %d ",arr[i]);
		}
		// print odd
		fprintf(fp,"\n%s\n","odd");
		for(i=0;i<length;i++){
			if(arr[i] % 2 != 0 )
				fprintf(fp," %d ",arr[i]);
		}
		fprintf(fp,"\n%s\n","rep");
		// print repititive
		for(i=0;i<length;i++){
			for(j=i+1;j<length;j++){
				if(arr[i] == arr[j] ){
					fprintf(fp," %d ",arr[i]);
				}
			}
		}
		

	}
	fclose(fp);
	return 0;
}