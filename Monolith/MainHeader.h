#ifndef MAINHEADER_H
#define MAINHEADER_H

class Windows{
	public:
		/// <summary>Pass it two integers (W and H) to resize the console window.</summary>
		void WindowSize(int, int);
		/// <summary>Adds 100 new lines to create the effect of clearing the console </summary>
		void ClearScreen();
		/// <summary>Displays a message and promts the user for imput. <para/>Checks that the input is number.<para/> If it is actually a number then it returns it as an integer.<para /> For double numbers use ValidateNumberDouble instead. </summary>
		int ValidateNumber(std::string);
		/// <summary>Displays a message and promts the user for imput.<para/>Checks that the input is number.<para/> If it is actually a number then it returns it as an double.<para /> For integer numbers use ValidateNumber instead. </summary>
		double ValidateNumberDouble(std::string);
};
class Mathematics{
	public:
		/// <summary> Add two (double) numbers and return the result. </summary>
		double Add(double,double);
		/// <summary> Subtract two (double) numbers and return the result. </summary>
		double Substract(double,double);
		/// <summary> Multiply two (double) numbers and return the result. </summary>
		double Multiply(double,double);
		/// <summary> Divide two (double) numbers and return the result. </summary>
		double Divide(double,double);
		/// <summary>Pass it a result variable (double), asks for input. <para/>Adds the input to the result until the user adds cero. <para/> Returns its result parameter. </summary>
		double RecursiveAdd(double);
		/// <summary>Pass it a result variable (double), asks for input. <para/>Substracts the input to the result until the user substracts cero. <para/> Returns its result parameter. </summary>
		double RecursiveSubstract(double);
		/// <summary>Pass it a result variable (double), asks for input. <para/>Multiply the input times the result until the user multiplies cero. <para/> Returns its result parameter. </summary>
		double RecursiveMultiply(double);
		/// <summary>Pass it a result variable (double), asks for input. <para/>Divide the result with the imput until the user divides by one.<para/> Returns its result parameter. </summary>
		double RecursiveDivide(double);
		/// <summary> Pass it an integral for the size of the vector. Pass it an empty Vector. <para/> It then asks for the values of each place. <para/>Finally it returns the total sum of all the vector spaces. </summary>
		double VectorTotal(int, std::vector<double>);
		/// <summary> Takes the three variables from a cuadratic equation <para/>and returns the first root. <para/>For use with QuadraticFormulaX2. </summary>
		double QuadraticFormulaX1(double,double,double);
		/// <summary> Takes the three variables from a cuadratic equation<para/> and returns the second root. <para/>For use with QadraticFormulaX1. </summary>
		double QuadraticFormulaX2(double,double,double);
};
class VolumenFigura {
	public:
		double PrismaRectangular(double,double,double);
		double PrismaTriangular(double,double,double);
};
class Tiempo {
public:
	std::string DiferenciaHora(double, double, double, double);
};
class Arrays {
	public: 
		void SumaDosArrays(int[],int[],int[],int);
		void SumaTotalDescuento();
};

#endif // !MAINHEADER_H
