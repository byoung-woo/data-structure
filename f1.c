#include <stdio.h>

int main() {
	int i, outcou, highin=0;
	int str[5]= {1, 34,24,12, 5}, out[5];

	for (outcou=0; outcou<5; outcou++){
		for(i=0;i<5;i++)
			if(str[i]>str[highin])
				highin=i;
		out[outcou]=str[highin];
		str[highin]=-1;
	}
	for()
}
