/*****+--------*--*---*-----*--*--**-*--***-*--*****************************
 *
 *  Lab #:05
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: Takes in the height and weight of a dog as well as athe target weight and generates a plan used to change the weight over 6 months 
 *
 ******+--------*--*---*-----*--*--**-*--***-*--****************************/
#define INCHTOMETER 0.0254
#define LBSTOKG 0.45359237
#include <stdio.h>

void input(float *height, float *weightOne, float *weightTwo);
void printOutput(float weightOne, float weightTwo, float weightChangeThree, float weightChangeSix, float weightFinal, float bmiOne, float bmiTwo, float additionalChange);
void calculateValues(float *height, float *weightOne, float *weightTwo, float *weightChangeThree, float *weightChangeSix, float *weightFinal, float *bmiOne, float *bmiTwo, float *additionalChange);

int main(void)
{
  float height; // Represents the height in inches input by the user
  float weightOne; // Represents the target weight in pounds input by the user
  float weightTwo; // Represents the target weight in pounds input by the user
  float weightChangeThree; // Represents the change in weight after 3 months (kg)
  float weightChangeSix; // Represents the change in weight after 6 months (kg)
  float weightFinal; // Represents the final weight (kg)
  float bmiOne; // Represents the initial BMI
  float bmiTwo; // Represents the final BMI
  float additionalChange; // Represents the additional change required to reach target weight (lbs)

  input(&height, &weightOne, &weightTwo);
  calculateValues(&height, &weightOne, &weightTwo, &weightChangeThree, &weightChangeSix, &weightFinal, &bmiOne, &bmiTwo, &additionalChange);
  printOutput(weightOne, weightTwo, weightChangeThree, weightChangeSix, weightFinal, bmiOne, bmiTwo, additionalChange);

  return (0);
}

/*****+-*-----***---*-*-*------*---*-*--***-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function: input
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float* height - The address of the height variable in the main function
 *    2. float* weightOne - The address of the initial weight variable in the main function (lbs)
 *    3. float* weightTwo - The address of the target weight variable in the main function (lbs)
 *
 *  Function Description: Takes in input from the user and assigns the values to the variables in the main function 
 *
 ******+-*-----***---*-*-*------*---*-*--***-*--****************************/

void input(float *height, float *weightOne, float *weightTwo)
{
  printf("Enter height [in] -> ");
  scanf("%f", height);
  printf("Enter weight #1 [lbs] -> ");
  scanf("%f", weightOne);
  printf("Enter weight #2 [lbs] -> ");
  scanf("%f", weightTwo);
}

/*****+-*-----***---*-*-*------*---*-*--***-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function:
 *
 *  Function Return Type:
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float* height - The address of the height variable in the main function
 *    2. float* weightOne - The address of the initial weight variable in the main function (lbs)
 *    3. float* weightTwo - The address of the target weight variable in the main function (lbs)
 *    4. float* weightChangeThree - The address of the variable storing the weight change after three months (kg)
 *    5. float* weightChangeSix - The address of the variable storing the weight change after six months (kg)
 *    6. float* weightFinal - The address of the variable storing the final weight after the diet plan (kg)
 *    7. float* bmiOne - The address of the variable storing the initial BMI at the start of the diet plan
 *    8. float* bmiTwo - The address of the variable storing the final BMI at the end of the diet plan
 *    9. float* additionalChange - The address of the variable storing the required change in order to reach the desired weight (lbs)
 *
 *
 *  Function Description: Calculates the weight change after 3/6 months, as well as the BMI at the start/end and required remaining change
 *
 ******+-*-----***---*-*-*------*---*-*--***-*--****************************/

void calculateValues(float *height, float *weightOne, float *weightTwo, float *weightChangeThree, float *weightChangeSix, 
float *weightFinal, float *bmiOne, float *bmiTwo, float *additionalChange)
{
  float valueToMultiply; // Represents the number to determine whether or not the weight will increase or decrease (multiplication factor per month`)
  valueToMultiply = ((int)(*weightOne / *weightTwo + 2) % (int)(*weightOne / *weightTwo + 1) * 0.99) + ((int)(*weightTwo / *weightOne + 2) % (int)(*weightTwo / *weightOne + 1) * 1.01);
  
  printf("%f", valueToMultiply);
  
  *height *= INCHTOMETER;
  *weightOne *= LBSTOKG;
  *weightTwo *= LBSTOKG;

  *bmiOne = (*weightOne) / (*height * *height);

  *weightChangeThree = *weightOne;
  *weightChangeThree *= valueToMultiply;
  *weightChangeThree *= valueToMultiply;
  *weightChangeThree *= valueToMultiply;

  *weightChangeSix = *weightChangeThree;
  *weightChangeThree -= *weightOne; // This is the final modification of weightChangeThree

  *weightChangeSix *= valueToMultiply;
  *weightChangeSix *= valueToMultiply;
  *weightChangeSix *= valueToMultiply;

  *weightFinal = *weightChangeSix;
  *weightChangeSix -= *weightOne + *weightChangeThree;

  *bmiTwo = (*weightFinal) / (*height * *height);
  *additionalChange = (*weightTwo - *weightFinal) / LBSTOKG;
}

/*****+-*------**---*-*-*------*---*-*--***-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function: printOutput
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float weightOne - The weight at the start of the diet plan (lbs)
 *    2. float weightTwo - The desired weight for the end of the diet plan (lbs)
 *    3. float weightChangeThree - The weight change after 3 months (kg)
 *    4. float weightChangeSix - The weight change after 6 months (kg)
 *    5. float weightFinal - The weight at the end of the dietary plan (kg)
 *    6. float bmiOne - The BMI at the start of the diet plan
 *    7. float bmiTwo - The BMI at the end of the diet plan 
 *    8. float additionalChange - The additional change required in order to reach weight goal (lbs)
 *
 *  Function Description: Prints out the required functional output 
 *
 ******+-*------**---*-*-*------*---*-*--***-*--****************************/

void printOutput(float weightOne, float weightTwo, float weightChangeThree, float weightChangeSix, float weightFinal, float bmiOne, float bmiTwo, float additionalChange)
{
  printf("\n-=-=-=-=-=-=-=-=-=- Weight [kg] -=- BMI -=-=-");
  printf("\nInitial weight:%13.2f %11.2f", weightOne, bmiOne);
  printf("\nThree month change:%+9.2f           -", weightChangeThree);
  printf("\nSix month change:%+11.2f           -", weightChangeSix);
  printf("\nFinal weight:%15.2f %11.2f", weightFinal, bmiTwo);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nAdditional change needed to reach goal:%+6.2f [lbs]\n", additionalChange);
}