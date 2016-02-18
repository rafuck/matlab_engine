#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "engine.h"

int main(){
	Engine *ep;
	mxArray *mX = NULL, *mY = NULL;
	const size_t N = 1024;
	
	if (!(ep = engOpen(NULL))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}

	mX = mxCreateDoubleMatrix(1, N, mxREAL);
	mY = mxCreateDoubleMatrix(1, N, mxREAL);

	double *x = (double *)mxGetPr(mX);
	double *y = (double *)mxGetPr(mY);
	for (size_t i=0; i<N; ++i){
		x[i] = 2.0*M_PI*i/N;
		y[i] = sin(x[i]);
	}
	
	engPutVariable(ep, "x", mX);
	engPutVariable(ep, "y", mY);

	engEvalString(ep, "h = figure;");
	engEvalString(ep, "plot(x, y); hold on;");
	engEvalString(ep, "plot([0 0],ylim,'k'); plot(xlim,[0 0],'k');");
	engEvalString(ep, "title('y = sin(x)');");
	engEvalString(ep, "xlabel('x');");
	engEvalString(ep, "ylabel('y');");
	engEvalString(ep, "grid on; grid minor; box off;");
	engEvalString(ep, "print(h,'-dpng','sin.png');");
	engEvalString(ep, "close all;");
	
	mxDestroyArray(mX);
	mxDestroyArray(mY);

	printf("Ok. Press ENTER to exit\n");
	getchar();

	engClose(ep);
	
	return EXIT_SUCCESS;
}
