// OldComponentFactory.cpp
#include "ComponentFactory.h"
#include "DocumentComponent.h"
#include <iostream>

OldComponentFactory::OldComponentFactory() {
    std::cout << "OldComponentFactory created.\n";
}

DocumentComponent* OldComponentFactory::createText() {
    return new Text("Old Text:");
}

// Implement createImage() and CreateTable()

// Code here

// Create Image
DocumentComponent* OldComponentFactory::createImage() {
    return new Image("Old Image:");
}

// Create Table
DocumentComponent* OldComponentFactory::createTable() {
    return new Table("Old Table:");
}