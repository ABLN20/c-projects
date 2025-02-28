// NewComponentFactory.cpp
#include "ComponentFactory.h"
#include "DocumentComponent.h"
#include <iostream>

NewComponentFactory::NewComponentFactory() {
    std::cout << "NewComponentFactory created.\n";
}

DocumentComponent* NewComponentFactory::createText() {
    return new Text("New Text:");
}

// Implement createImage() and CreateTable()

// Code here

// Create Image
DocumentComponent* NewComponentFactory::createImage() {
    return new Image("New Image:");
}

// Create Table
DocumentComponent* NewComponentFactory::createTable() {
    return new Table("New Table:");
}