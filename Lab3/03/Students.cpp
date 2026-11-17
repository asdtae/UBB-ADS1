#include "Students.h"

// Structs
struct Student {
    string firstName;
    string lastName;
    double grade = 0;
};

struct Class {
    uint32_t nrOfStudents = 0;
    vector<Student> students;
};

struct DataSet {
    uint32_t nrOfClasses = 0;
    vector<Class> classes;
};

// Create
static Student* CreateStudent(const string &firstName, const string &lastName, const double grade) {
    auto* s = new Student;
    s->firstName = firstName;
    s->lastName = lastName;
    s->grade = grade;
    return s;
}

// STD I/O
static Class* CreateClass(const uint32_t nrOfStudents) {
    auto* c = new Class;
    c->nrOfStudents = nrOfStudents;

    uint32_t nameLen;
    string firstName, lastName;
    double grade;

    for (uint32_t i = 0; i<nrOfStudents; i++) {
        cin >> nameLen >> lastName >> firstName >> grade;
        const Student* s = CreateStudent(firstName,lastName,grade);
        c->students.push_back(*s);
    }

    return c;
}

static DataSet* CreateDataSet(const uint32_t nrOfClasses) {
    auto* d = new DataSet;
    d->nrOfClasses = nrOfClasses;

    uint32_t nrOfStudents;

    for (uint32_t i = 0; i<nrOfClasses; i++) {
        cin >> nrOfStudents;
        const Class* c = CreateClass(nrOfStudents);
        d->classes.push_back(*c);
    }

    return d;
}

DataSet* Create(const uint32_t nrOfClasses) {
    auto* d = CreateDataSet(nrOfClasses);
    return d;
}

// FILE I/O
static Class* CreateClass(ifstream &f, const uint32_t nrOfStudents) {
    auto* c = new Class;
    c->nrOfStudents = nrOfStudents;

    uint32_t nameLen;
    string firstName, lastName;
    double grade;

    for (uint32_t i = 0; i<nrOfStudents; i++) {
        f >> nameLen >> lastName >> firstName >> grade;
        const Student* s = CreateStudent(firstName,lastName,grade);
        c->students.push_back(*s);
    }

    return c;
}

static DataSet* CreateDataSet(ifstream &f, const uint32_t nrOfClasses) {
    auto* d = new DataSet;
    d->nrOfClasses = nrOfClasses;

    uint32_t nrOfStudents;

    for (uint32_t i = 0; i<nrOfClasses; i++) {
        f >> nrOfStudents;
        const Class* c = CreateClass(f, nrOfStudents);
        d->classes.push_back(*c);
    }

    return d;
}

DataSet* Create(const char *inp) {
    ifstream f(inp);
    uint32_t nrOfClasses;

    f >> nrOfClasses;
    auto* d = CreateDataSet(f, nrOfClasses);
    f.close();

    return d;
}

// Sort
static Class* Sort(Class* c) {
    auto* sortedClass = new Class;
    sortedClass->nrOfStudents = c->nrOfStudents;

    for (uint32_t i = 0; i<sortedClass->nrOfStudents; i++) {
        double maxi = 0;
        uint32_t poz = 0;

        for (uint32_t j = 0; j<c->nrOfStudents; j++) {
            if (c->students[j].grade > maxi) {
                maxi = c->students[j].grade;
                poz = j;
            }
        }

        sortedClass->students.push_back(*CreateStudent(c->students[poz].firstName,c->students[poz].lastName,c->students[poz].grade));
        c->students[poz].grade = 0;
    }

    return sortedClass;
}

// Search
static bool T(const Student* s, uint32_t &above, const string &firstName, const string &lastName) {
    static double lastGrade = s->grade;

    if (s->grade < lastGrade) above++;
    else lastGrade = s->grade;

    if (above >= 3 || (s->firstName == firstName && s->lastName == lastName)) return true;
    return false;
}

static Class* SearchClass(Class* c, const string &str, bool &top3) {
    // get name
    const char* tok = strtok(strdup(str.c_str())," ");
    const string firstName = tok;
    tok = strtok(nullptr," ");
    const string lastName = tok;

    // rendez
    Class* newC = Sort(c);

    // lookup
    uint32_t i = 0, above = 0;
    while (i < newC->nrOfStudents && !T(&newC->students[i],above,firstName,lastName)) {
        i++;
    }

    if (above <= 2) top3 = true;
    else top3 = false;

    return newC;
}

bool Search(DataSet* d, const string &str) {
    const uint32_t nrOfClasses = d->nrOfClasses;
    bool top3 = false;

    // for multi class use, implement start class param <-> useless for
    // use a diff method for top3 ret
    for (uint32_t i = 0; i<nrOfClasses; i++) {
        const Class* newC = SearchClass(&d->classes[i],str,top3);
        d->classes[i] = *newC; // TODO: itt van az ertekadasnal a problema

        if (top3) return true;
    }

    return false;
}

// Print
static void PrintStudent(const Student* s) {
    cout << s->lastName << ' ' << s->firstName << '\n' << s->grade << '\n';
}

static void PrintClass(const Class* c) {
    const uint32_t nrOfStudents = c->nrOfStudents;
    for (uint32_t i = 0; i<nrOfStudents; i++) {
        PrintStudent(&c->students[i]);
    }
}

void Print(const DataSet* d) {
    const uint32_t nrOfClasses = d->nrOfClasses;
    for (uint32_t i = 0; i<nrOfClasses; i++) {
        PrintClass(&d->classes[i]);
        cout << '\n';
    }
}