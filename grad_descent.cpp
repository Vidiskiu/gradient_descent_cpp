#include <iostream>
#include <math.h>

using namespace std;

const int dim = 1;//Dimension
double x[dim] = {-0.1};//Initial guess
double grad[dim];//Saving gradient values
double stepsize = 0.9;//"optimum" step size after checking

double findGrad(){
    double result = 0;

    for(int i=0;i<dim;i++)
    {
        result = result + (grad[i]*grad[i]);
    }
    return sqrt(result);//Finding the magnitude of the gradient
}

int main(){
    //f(x) = -2(x)^2+x the equation
    int counter = 0;//counting iterations
    double precision = 1.e-6;//Desired precision

    grad[0] = -4*x[0]+1;//Derivative of the equation
    double gradient = findGrad();//Finding the gradient using the function
    while(gradient>precision){//Loop to maintain process
        grad[0] = -4*x[0]+1;//Saving new gradient for each x values
        for(int i=0;i<dim;i++){
            x[i] = x[i] + stepsize*grad[i];//New x finding using stepsize.
            counter++;//Incrementing iteration counter
            gradient = findGrad();//updating gradient value
            cout<<"Iteration "<<counter<<", x0 = "<<x[0]<<", Gradient = "<<gradient<<", Stepsize : "<<stepsize<<endl;//Showing result
        }
        stepsize = stepsize*9/10;
    }

    cout<<"Result : "<<x[0];
}
