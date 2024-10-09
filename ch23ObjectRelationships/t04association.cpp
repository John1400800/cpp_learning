#include <cstdlib>
#include <vector>
#include <string>
#include <string_view>
#include <iostream>

class Patient;

class Doctor {
    std::string name_{};
    std::vector<std::reference_wrapper<const Patient>> patient_{};
public:
    Doctor(std::string_view name)
        : name_{name}
    { }

    void addPatient(Patient&);

    friend std::ostream& operator<<(std::ostream&, const Doctor&);

    const std::string& getName() const {
        return name_;
    }
};

class Patient {
    std::string name_{};
    std::vector<std::reference_wrapper<const Doctor>> doctor_{};

    void addDoctor(const Doctor& doctor) {
        doctor_.push_back(doctor);
    }
public:
    Patient(std::string_view name)
        : name_{name}
    { }

    friend std::ostream& operator<<(std::ostream&, const Patient&);

    const std::string& getName() const {
        return name_;
    }

    friend void Doctor::addPatient(Patient&);
};

void Doctor::addPatient(Patient& patient) {
    patient_.push_back(patient);
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
    if (doctor.patient_.empty())
        return out << doctor.name_ << " has no patient right now";
    out << doctor.name_ << " is seeing patients: ";
    for (const auto& patient : doctor.patient_)
        out << patient.get().getName() << ' ';
    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    if (patient.doctor_.empty())
        return out << patient.name_ << " has no doctors right now";
    out << patient.name_ << " is seeing doctors: ";
    for (const auto& doctor : patient.doctor_)
        out << doctor.get().getName() << ' ';
    return out;
}

int main() {
    Patient  dave{ "Dave" };
    Patient frank{ "Frank" };
    Patient betsy{ "Betsy" };
    Doctor  james{ "James" };
    Doctor  scott{ "Scott" };
    james.addPatient(dave);
    scott.addPatient(dave);
    scott.addPatient(betsy);
    std::cout << james << '\n';
    std::cout << scott << '\n';
    std::cout <<  dave << '\n';
    std::cout << frank << '\n';
    std::cout << betsy << '\n';
    return EXIT_SUCCESS;
}
