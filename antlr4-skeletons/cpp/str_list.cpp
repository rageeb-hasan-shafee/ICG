#pragma once;
#include<string>
#include<vector>

class str_list {
private:
    std::vector<std::string> variables;

public:
    // Constructor
    str_list() = default;

    // getters and setters
    const std::vector<std::string>& get_variables() const {
        return variables;
    }
    void set_variables(const std::vector<std::string>& vars) {
        variables = vars;
    }

    // Add a string to the list
    void add(const std::string& str) {
        variables.emplace_back(str);
    }

    // Get the size of the list
    std::string size() const {
        return std::to_string(variables.size());
    }

    // Clear the list
    void clear() {
        variables.clear();
    }

    // std::string get_list_as_string() const {
    //     std::string result;
    //     for (const auto& var : variables) {
    //         if (!result.empty()) {
    //             result += ",";
    //         }
    //         result += var;
    //     }
    //     return result;
    // }
    std::string get_list_as_string() const {
        std::string result;
        bool first = true;
    
        for (const auto& var : variables) {
            if (!first) {
                // If current item is a function definition (has curly brace)
                if (var.find('{') != std::string::npos) {
                    result += "\n"; // Add newline before function definitions
                }
                // If current item is a declaration (ends with semicolon)
                else if (var.find(';') != std::string::npos) {
                    // Don't add comma if it's already part of a declaration
                    if (result[result.length()-1] != ',') {
                        result += " ";
                    }
                }
                // For variable lists within declarations
                else {
                    result += ","; // Keep commas between variables in declarations
                }
            }
            result += var;
            first = false;
        }
        return result;
    }

};
