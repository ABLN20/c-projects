// DocumentComponent.h
#pragma once
#include <vector>
#include <string>
#include <iostream>

class DocumentComponent {
public:
    virtual ~DocumentComponent() = default;
    virtual void add(DocumentComponent* component) {}  // Accept raw pointers
    virtual void display() const = 0;
};

// Implement the Text, Image, Table, and CompositeDocument Classes

class Text : public DocumentComponent {
    std::string style;
public:
    // Code here
    Text(const std::string& style) : style(style) {}

    void display() const 
    {
        std::cout << style << " Text Component\n";
    }
};

// Image Component
class Image : public DocumentComponent {
    std::string style;
public:
    Image(const std::string& style) : style(style) {}

    void display() const {
        std::cout << style << " Image Component\n";
    }
};

// Table Component
class Table : public DocumentComponent {
    std::string style;
public:
    Table(const std::string& style) : style(style) {}

    void display() const 
    {
        std::cout << style << " Table Component\n";
    }
};

class CompositeDocument : public DocumentComponent {
    std::vector<DocumentComponent*> children;  
public:
    // Implement Add() and Display()
    // Code Here
    void add(DocumentComponent* component)
    {
        children.push_back(component);
    }

    void display() const 
    {
        for(const auto& child : children)
        {
            child->display();
        }
    }

    ~CompositeDocument()
    {
        for(auto& child : children)
        {
            delete child;
        }
    }
};
