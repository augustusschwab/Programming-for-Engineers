// Augustus Schwab
// HW 5 - ME EN 5250
// Due: 10/21/15
// Problem 4 - Grading System
// 
// This program will compute a students overall grade from 
// his or her grades for a midterm, a final, and homework.

#include <iostream>
#include <vector>
#include <algorithm>

struct StudentGrades { 
	StudentGrades() { } 
	double midterm = 0; 
	double final = 0; 
	std::vector<double> homework; 
};

std::istream& operator>>(std::istream& input, StudentGrades& student_grades){
	student_grades.homework.clear();
	int size = 0;
	double hw = 0;
	input >> student_grades.midterm >> student_grades.final >> size;
	for (int i = 0; i < size; ++i) {
		input >> hw;
		student_grades.homework.push_back(hw);
	}
	return input;
}

class Grader
{
public:
    std::vector<StudentGrades> NewClass;
	Grader() { }
	// the weights are self-explanatory
	// min_grade and max_grade are the minimum/maximum possible grades
	// any grades outside of the range [min_grade, max_grade] are invalid
	Grader(double midterm_weight, double homework_weight, double final_weight,
		double min_grade, double max_grade) {
		MidWeight = midterm_weight;
		HwWeight = homework_weight;
		FinalWeight = final_weight;
		MinGrade = min_grade;
		MaxGrade = max_grade;
	}
	Grader(std::vector<StudentGrades> new_class) {
		NewClass = new_class;
	}
	
	void add_student_grades(const StudentGrades& student_grades) {
		NewClass.push_back(student_grades);
	}
	
	double get_overall_grade_for_student(size_t student_of_interest)
	{
		// throw an exception if student_of_interest is out of bounds
		// call check_grades()
		// call the private get_overall_grade_for_student()
		int bound = NewClass.size();
		int student = student_of_interest;
		if (student > bound || student< 0) {
			throw "Student number is out of range";
		}
		check_grades(NewClass[student_of_interest]);
		double grade = get_overall_grade_for_student(NewClass[student_of_interest]);
		return grade;

	}
private:
	double MidWeight = 0;
	double HwWeight = 0;
	double FinalWeight = 0;
	double MinGrade = 0;
	double MaxGrade = 0;

		double get_overall_grade_for_student(StudentGrades& student_grades)
	{
		std::sort(student_grades.homework.begin(), student_grades.homework.end());
		double median = student_grades.homework[student_grades.homework.size() / 2];
		/*double result = 0;
		int size = student_grades.homework.size();
		for (int i = 0; i < size; ++i) {
			result += median * student_grades.homework[i];
		}*/
		double overall = (MidWeight * student_grades.midterm) + (FinalWeight 
			* student_grades.final) + (median * HwWeight);
		
		return overall;
	}
	void check_grades(const StudentGrades& student_grades) const
	{
		// check the following conditions in the listed order,
		// and throw an exception
		// 1. if the list of homework is empty, or
		// 2. if the midterm grade is out of range or
		// 3. if the final grade is out of range or
		// 4. if any of the homework grades is out of range
		if (student_grades.homework.empty()) {
			throw "There are no homework grades";
		}
		if (student_grades.midterm > MaxGrade || student_grades.midterm < MinGrade) {
			throw "Midterm grade is out of range";
		}
		if (student_grades.final > MaxGrade || student_grades.final < MinGrade) {
			throw "Final grade is out of range";
		}
		int size = student_grades.homework.size();
		for (int i = 0; i < size; ++i) {
			if (student_grades.homework[i] > MaxGrade || student_grades.homework[i] < MinGrade) {
				throw "Homework grade is out of range";
			}
		}
	}
};


int main() {
	int num_cases = 0;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');


	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		double MidWeight, FinalWeight, HwWeight, Min, Max;
		std::cin >> MidWeight >> FinalWeight >> HwWeight >>
			Min >> Max;
		Grader NewClass(MidWeight, HwWeight, FinalWeight, Min, Max);

		int NumStudents, StudentInterest;
		std::cin >> NumStudents >> StudentInterest;
		
		try {
			StudentGrades Student;
			
			for (int j = 0; j < NumStudents; ++j) {
				std::cin >> Student;
				NewClass.add_student_grades(Student);
			}
			std::cout << "Overall grade for student " << StudentInterest
				<< ": " << "\n" << NewClass.get_overall_grade_for_student(StudentInterest)
				<< "\n";
		}
		catch (char* error) {
			std::cout << "Error encountered when processing student " <<
				StudentInterest << ": " << "\n" << error << "\n";
		}
		

	}
	return 0;
}