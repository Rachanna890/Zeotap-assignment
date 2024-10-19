#include <iostream>
#include <string>
#include <memory>
#include <map>

using namespace std;

// Node structure for AST
struct Node {
    string type;        // "operator" (AND/OR) or "operand" (conditions)
    string value;       // Condition value (for operand nodes)
    shared_ptr<Node> left;  // Left child node
    shared_ptr<Node> right; // Right child node

    Node(string t, string v = "") : type(t), value(v), left(nullptr), right(nullptr) {}
};

// Create rule from string (For simplicity, we assume this is pre-parsed)
shared_ptr<Node> create_rule(string rule_str) {
    if (rule_str == "age > 30 AND department = 'Sales'") {
        auto root = make_shared<Node>("AND");
        root->left = make_shared<Node>("operand", "age > 30");
        root->right = make_shared<Node>("operand", "department = 'Sales'");
        return root;
    }
    // Add more rule parsing as needed
    return nullptr;
}

// Combine two rules into one AST
shared_ptr<Node> combine_rules(shared_ptr<Node> rule1, shared_ptr<Node> rule2) {
    auto root = make_shared<Node>("OR");
    root->left = rule1;
    root->right = rule2;
    return root;
}

// Evaluate the rule with given user data
bool evaluate_rule(shared_ptr<Node> node, map<string, string> data) {
    if (node->type == "AND") {
        return evaluate_rule(node->left, data) && evaluate_rule(node->right, data);
    } else if (node->type == "OR") {
        return evaluate_rule(node->left, data) || evaluate_rule(node->right, data);
    } else if (node->type == "operand") {
        if (node->value == "age > 30") {
            return stoi(data["age"]) > 30;
        } else if (node->value == "department = 'Sales'") {
            return data["department"] == "Sales";
        }
        // Add more conditions as needed
    }
    return false;
}

int main() {
    // Example: Create a rule
    shared_ptr<Node> rule1 = create_rule("age > 30 AND department = 'Sales'");
    shared_ptr<Node> rule2 = create_rule("age < 25 AND department = 'Marketing'");
    
    // Combine rules
    shared_ptr<Node> combined_rule = combine_rules(rule1, rule2);
    
    // Test with user data
    map<string, string> user_data = { {"age", "35"}, {"department", "Sales"} };
    if (evaluate_rule(combined_rule, user_data)) {
        cout << "User is eligible." << endl;
    } else {
        cout << "User is not eligible." << endl;
    }

    return 0;
}
