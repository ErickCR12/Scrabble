#ifndef COLLECTOR_HPP
#define COLLECTOR_HPP

#include "Node.hpp"

using namespace std;
class Node; // Forward Declaration

/// @brief Class responsible for recycling the memory released in List.
class Collector{

    static Collector* collector; //!< @brief Self referencing attribute (Singleton pattern).
    Node* firstReference; //!< @brief First reference of pointer to be reused.

private:

    //! @brief Private constructor, following the Singleton Pattern.
    Collector(){
        this->firstReference = nullptr;
    }

public:
    // These methods will be implemented as members by the class Node.h

    /// @brief It is responsible for creating a single instance of Collector.
    /// @brief ** Implements the Singleton design pattern.
    /// @return An instance of Collector.
    static Collector* getCollector();

    /// @brief It is responsible for adding the pointer to the list to be recycled.
    /// @param memory Memory address to be recycled
    void addMemoryReference(void* memory);

    /// @brief Returns a recycled memory address.
    /// @brief If there is none, it returns null.
    /// @return A memory address available
    Node* getMemoryReference();

    /// @brief Method responsible for displaying the recycled memory locations stored in the collector list.
    void printCollector();
};

Collector* Collector::collector = nullptr;
Collector* Collector::getCollector() {
    if(!collector) collector = new Collector();
    return collector;
}

#endif COLLECTOR_HPP