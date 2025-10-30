#include <iostream>
#include <string>
#include <vector>

struct studentType {
    std::string studentFName;
    std::string studentLName;
    int testScore;
    char grade;
};

void input(studentType students[], const int CLASS_SIZE){
    for (int i = 0; i < CLASS_SIZE; i++){
        std::cout << "Data ke-" << i+1 << std::endl;
        std::cout << "First Name : ";
        std::cin >> students[i].studentFName;
        std::cout << "Last Name : ";
        std::cin >> students[i].studentLName;
        std::cout << "Test Score : ";
        std::cin >> students[i].testScore;
        std::cout << std::endl;
    }
    
}

void AssignGrade(studentType students[], const int CLASS_SIZE){
    for (int i = 0; i < CLASS_SIZE; i++){
        if (students[i].testScore <= 45) students[i].grade = 'E';
        else if (students[i].testScore <= 50 ) students[i].grade = 'D';
        else if (students[i].testScore <= 60) students[i].grade = 'C';
        else if (students[i].testScore <= 75) students[i].grade = 'B';
        else if (students[i].testScore <= 100) students[i].grade = 'A';
    }
}

int highScore(studentType students[], std::vector<int> &indexMax, const int CLASS_SIZE){
    int testMax = students[0].testScore;
    indexMax.push_back(0);

    for (int i = 1; i < CLASS_SIZE; i++){
        if (testMax < students[i].testScore) {
            testMax = students[i].testScore;
            indexMax.clear();
            indexMax.push_back(i); 
        } else if (testMax == students[i].testScore) indexMax.push_back(i);
    }

    return testMax;
}

void printStudents(const studentType students[], const int CLASS_SIZE){
        std::cout << "Students : " << std::endl;
        for (int i = 0; i < CLASS_SIZE; i++){
            std::cout << students[i].studentLName << ", " << students[i].studentFName << std::endl
                      << "test score = " << students[i].testScore << std::endl
                      << "grade = " << students[i].grade << std::endl;
        }
        std::cout << "\n";
}

void printWinner(const studentType students[], const std::vector<int> indexMax, int highest_score){
    std::cout << "Highest test score = " << highest_score << std::endl;
    if (indexMax.size() == 1) std::cout << "Student with the highest test score: ";
    else std::cout << "Students with the highest test score: ";
    std::cout << "\n";
    for (int i = 0; i < indexMax.size(); i++){
        int j = indexMax[i];
        std::cout << students[j].studentFName << ' ' << students[j].studentLName;
        if (i != indexMax.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(){
    const int CLASS_SIZE = 20; // ini adalah deklarasi variabel konstan yang disesuaikan dengan soal
    studentType students[CLASS_SIZE]; // deklarasi variabel struct berupa array bernama students

    input(students, CLASS_SIZE); // proses input dari user
    AssignGrade(students, CLASS_SIZE); // meng-assign grade dari data input ke masing masing data student

    std::vector<int> indexMax; // deklarasi vector untuk siswa dengan test score tertinggi. Kenapa vector?
                               // karena vector dapat menutupi kekurangan array, yaitu vector bersifat dinamis.
    int highest_score = highScore(students, indexMax, CLASS_SIZE); // mengambil nilai highest score dari fungsi highScore()

    printStudents(students, CLASS_SIZE); // print students

    printWinner(students, indexMax, highest_score); // print student yang punya nilai tertinggi, memungkinkan lebih dari satu.

    return 0;
}

