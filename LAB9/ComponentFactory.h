// ComponentFactory.h
#pragma once
#include "DocumentComponent.h"

// Abstract Factory Interface
class ComponentFactory {
public:
    virtual ~ComponentFactory() = default;
    virtual DocumentComponent* createText() = 0;
    virtual DocumentComponent* createImage() = 0;
    virtual DocumentComponent* createTable() = 0;
};

// Implement the New and Old create functions and objects

// Old Factory Implementation
class OldComponentFactory : public ComponentFactory {
public:
    // Code Here
    OldComponentFactory();
    DocumentComponent* createText() override;
    DocumentComponent* createImage() override;
    DocumentComponent* createTable() override;
};

// New Factory Implementation
class NewComponentFactory : public ComponentFactory {
public:
    // Code Here
    NewComponentFactory();
    DocumentComponent* createText() override;
    DocumentComponent* createImage() override;
    DocumentComponent* createTable() override;
};
