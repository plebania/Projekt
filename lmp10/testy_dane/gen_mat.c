#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

double x2(double x){
	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= pow(x,2) + r;
}

double mx2(double x){
	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= -0.17 * pow(x,2) + r;
}

double sin_app(double x){

	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= sin(x) + r;
	return f_x;
}

double cos_app(double x){

	double r= (double)(rand()%100 - 50) / 100. ;
	printf("%lf\n", r);
	double f_x= cos(x) + r;
	return f_x;
}

double tan_app(double x){

	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= tan(x) + r;
	return f_x;
}

double atan_app(double x){

	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= atan(x) + r;
	return f_x;
}

double prosta_mal(double x){
	
	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= -2 * x + r;
	return f_x;

}

double prosta_ros(double x){
	
	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= 0.56 * x + r;
	return f_x;

}

double wiel7(double x){
	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= 17 * pow(x, 7) - 7 * pow(x, 6) + 0.76 * pow(x, 5) - 8 * pow(x,4) + 0.98 * pow(x, 3) - 232 * pow(x, 2) + 7 *x - 10;
	return f_x;
}

double wiel11(double x){
	double r= (double)(rand()%100 - 50) / 100. ;
	double f_x= 7.42 * pow(x, 11) - 232 * pow(x,10) + 8.76 * pow(x, 9) - 4.7 * pow(x, 8) - 17 * pow(x, 7) - 7 * pow(x, 6) + 0.76 * pow(x, 5) - 8 * pow(x,4) + 0.98 * pow(x, 3) - 232 * pow(x, 2) + 7 *x - 10;
	return f_x;
}

int main(int argc, char **argv){

	srand(time(NULL));
	
	FILE *in= argc > 4 ? fopen(argv[4], "w") : stdout;
	int n = argc > 1 ? atoi(argv[1]) : 100;
	double f = argc > 2 ? atof(argv[2]) : 0. ;
	double t = argc > 3 ? atof(argv[3]) : 6.3;
	char * func = argc > 5 ? argv[5] : "sin";

	printf("%s: gonna generate %d points from %lf to %lf in file:\"%s\" based on func: %s\n", 
																							argv[0], n, f, t, argv[4], func);

	double delta= (t-f) / n;

	if(strcmp(func, "sin") == 0){
		for(int i= 0; i<n; i++){
			fprintf(in, "%lf %lf\n", f + i*delta, sin_app(f+i*delta));
		}
	}else if(strcmp(func, "cos") == 0){
		for(int i= 0; i<n; i++){
			fprintf(in, "%lf %lf\n", f + i*delta, cos_app(f+i*delta));
		}
	}else if(strcmp(func, "tan") == 0){
		for(int i= 0; i<n; i++){
			fprintf(in, "%lf %lf\n", f + i*delta, tan_app(f+i*delta));
		}
	}else if(strcmp(func, "atan") == 0){
		for(int i= 0; i<n; i++){
			fprintf(in, "%lf %lf\n", f + i*delta, atan_app(f+i*delta));
		}
	}else if(strcmp(func, "pm") == 0){
		for(int i= 0; i<n; i++)
			fprintf(in, "%lf %lf\n", f + i*delta, prosta_mal(f+i*delta));
	}else if(strcmp(func, "pr") == 0){
		for(int i=0; i<n; i++)
			fprintf(in, "%lf %lf\n", f+i*delta, prosta_ros(f+i*delta));
	}else if(strcmp(func, "x2")){
		for(int i=0; i<n; i++)
			fprintf(in, "%lf %lf\n", f+i*delta, x2(f+i*delta));
	}else if(strcmp(func, "mx2")){
     for(int i=0; i<n; i++)
		 	fprintf(in, "%lf %lf\n", f+i*delta, mx2(f+i*delta));
	}else if(strcmp(func, "wiel_7")){
     for(int i=0; i<n; i++)
		 	fprintf(in, "%lf %lf\n", f+i*delta, wiel7(f+i*delta));
	}else if(strcmp(func, "wiel_11")){
     for(int i=0; i<n; i++)
		 	fprintf(in, "%lf %lf\n", f+i*delta, wiel11(f+i*delta));
	}else{
		printf("Podaj funkcje [sin, cos, tan, atan]");
		return 1;
	}

	return 0;
}
