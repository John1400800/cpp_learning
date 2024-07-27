class Employee {
private:
    std::string m_name{};
public:
    void setName(std::string_view name) {
        m_name = name;
    }
/* Returning a std::string_view would require a temporary std::string_view
 * to be created and returned every time the function was called */
    const std::string& getName() const {
        return m_name;
    }
}
