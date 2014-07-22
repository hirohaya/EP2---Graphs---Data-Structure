#include "file.h"

/*Reads the file containing the graph's information to set the size of graph vector. In the end
 Rewind the stream to further operations.*/
int get_size(FILE *pFile){

  int n;
  int max;
  	
  	max = 0;

	while(!feof(pFile)){
	    if(fscanf(pFile, "%d", &n) == 1)
		if(max < n)
		    max = n;
	}
	rewind(pFile);
	return max+1;
}

