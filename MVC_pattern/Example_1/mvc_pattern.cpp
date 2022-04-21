#include <iostream>
#include <string>

class StudentModel
{
public :
    StudentModel() = default;
    std::string getName()
    {
        return thisName;
    }
    void setName(const std::string& name)
    {
        thisName = name;
    }
    int getRollNo()
    {
        return thisRollNo; 
    }
    void setRollNo(int roll)
    {
        thisRollNo = roll;
    }
private :
    std::string thisName;
    int thisRollNo;
};

class StudentView
{
public :
    StudentView() = default;
    void printStudentDetails(const std::string& name, int rollNo)
    {
        std::cout << "============================================\n" << 
        "Student Detail\n" <<
        "============================================\n" <<
        "Name : " << name << '\n' <<
        "Roll : " << rollNo << '\n' << 
        "============================================\n\n";
    }
};

class StudentController
{
public :
    StudentController(StudentModel* model, StudentView* view)
        : thisModel{model} , thisView{view}
    {

    }
    void setStudentName(const std::string& name)
    {
        thisModel->setName(name);
    }
    std::string getStudentName()
    {
        return thisModel->getName();
    }
    void setStudentRollNo(int roll)
    {
        thisModel->setRollNo(roll);
    }
    int getStudentRollNo()
    {
        return thisModel->getRollNo();
    }
    void updateView()
    {
        thisView->printStudentDetails(getStudentName(),getStudentRollNo());
    }
private :
    StudentModel* thisModel;
    StudentView* thisView;
};

int main()
{
    StudentModel* model = new StudentModel();
    model->setName("Nayem Islam");
    model->setRollNo(2019331092);

    StudentView* view = new StudentView();

    StudentController* controller = new StudentController(model,view);
    controller->updateView();
    controller->setStudentName("Naimur Sakib");
    controller->updateView();
    return 0;
}