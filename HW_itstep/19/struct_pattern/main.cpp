/* 1. Спроектировать приложение учета занятий в учебном заведении. Описать три
предмета, каждый из которых может быть двух видов: лекция или практика.
2. Создать UML диаграмму классов для приложения. */


#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------
//---------------------------------------Предмет---------------------------------------
//-------------------------------------------------------------------------------------

class AbstractLesson
{
private:
    string teacher = "UNKNOWN";
    string lesson_place = "UNKNOWN";
    string lesson_name = "UNKNOWN";

public:
    AbstractLesson() = default;
    AbstractLesson(string teacher) : teacher(teacher) {}
    AbstractLesson(string teacher, string lesson_place) : AbstractLesson(teacher) { this->lesson_place = lesson_place; }

    virtual void setTeacher(string teacher) { this->teacher = teacher; }

    virtual void setLessonPlace(string lesson_place) { this->lesson_place = lesson_place; }

    virtual void setLessonName(string lesson_name) { this->lesson_name = lesson_name; }

    virtual string getTeacher() const { return teacher; }

    virtual string getLessonPlace() const { return lesson_place; }

    virtual string getLessonName() const { return lesson_name; }

    virtual ~AbstractLesson() = 0;
};
AbstractLesson::~AbstractLesson() { cout << "Hope that was last lesson today..." << endl; }

class CyberSecurityLesson : public AbstractLesson
{

public:
    CyberSecurityLesson() : AbstractLesson("Cybertron 3000", "426") { this->setLessonName("cybersecurity"); }
    /* some classy realization */
    ~CyberSecurityLesson() = default;
};

class DesigningLesson : public AbstractLesson
{
public:
    DesigningLesson() : AbstractLesson("Designerbot 696", "766") { this->setLessonName("designing"); }
    /* some classy realization */
    ~DesigningLesson() = default;
};

class ProgrammingLesson : public AbstractLesson
{
public:
    ProgrammingLesson() : AbstractLesson("Programmator the void", "3/4") { this->setLessonName("programming"); }
    /* some classy realization */
    ~ProgrammingLesson() = default;
};

//-------------------------------------------------------------------------------------
//---------------------------------------Вид_предмета----------------------------------
//-------------------------------------------------------------------------------------

class AbstractLessonType
{
    AbstractLesson *Lesson;

public:
    virtual void visitLesson() = 0;
    virtual void skipLesson() = 0;
    virtual void editLessonParams() { cout << "Permission denied" << endl; }
    virtual void listenToTeacher() = 0;

    AbstractLesson *getLesson() const { return Lesson; }

    void setLesson(AbstractLesson *Lesson) { this->Lesson = Lesson; }

    virtual ~AbstractLessonType() = default;
};

class TheoreticLesson : public AbstractLessonType
{
    void listenToTeacher() override
    {
        cout << getLesson()->getTeacher() + " said \"bla-bla\", but you aren't understand " + getLesson()->getLessonName() + " language" << endl;
    }

public:
    void skipLesson() override { cout << "You will't attend on a theory of " + getLesson()->getLessonName() + " lesson" << endl; }

    void visitLesson() override
    {
        cout << "You will attend on a " + getLesson()->getLessonName() + " lesson" << endl;
        this->listenToTeacher();
    }
};

class PraciceLesson : public AbstractLessonType
{
    void listenToTeacher() override
    {
        cout << getLesson()->getTeacher() + " make some " + getLesson()->getLessonName() + " things" << endl;
        if (getLesson()->getLessonName() == "programming")
        {
            cout << getLesson()->getTeacher() + " gonna find, u can never hide " << endl;
        }
    }

public:
    void skipLesson() override { cout << "You will't attend on a practice of" + getLesson()->getLessonName() + " lesson" << endl; }

    void visitLesson() override
    {
        cout << "You will attend on a " + getLesson()->getLessonName() + " lesson" << endl;
        this->listenToTeacher();
    }
};
//-------------------------------------------------------------------------------------

int main()
{
    CyberSecurityLesson *cybles = new CyberSecurityLesson();
    DesigningLesson *desles = new DesigningLesson();
    ProgrammingLesson *progles = new ProgrammingLesson();
    AbstractLessonType *lestype = new TheoreticLesson();

    lestype->setLesson(cybles);
    lestype->skipLesson();
    lestype->setLesson(progles);
    lestype->visitLesson();
    delete lestype;

    lestype = new PraciceLesson();
    lestype->setLesson(desles);
    lestype->visitLesson();
    delete lestype;

    lestype = new PraciceLesson();
    lestype->setLesson(progles);
    lestype->skipLesson();

    delete lestype;
    delete cybles;
    delete desles;
    delete progles;
}