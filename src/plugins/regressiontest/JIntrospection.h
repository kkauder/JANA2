// Copyright 2020, Jefferson Science Associates, LLC.
// Subject to the terms in the LICENSE file found in the top-level directory.

#ifndef _JIntrospection_h_wth
#define _JIntrospection_h_wth

#include <string>
#include <vector>
#include <tuple>
#include <mutex>

#include <JANA/JEvent.h>


class JIntrospection {
    bool m_enabled = true;
    const JEvent* m_event;
    bool m_indexes_built = false;
    std::map<std::pair<std::string, std::string>, std::pair<int, const JFactory*>> m_factory_index;

public:
    JIntrospection(const JEvent* event);
    void PrintEvent();
    void PrintFactories();
    void PrintFactory(int factory_idx);
    void PrintJObjects(int factory_idx);
    void PrintJObject(int factory_idx, int object_idx);
    void PrintAncestors(int factory_idx);
    void PrintAssociations(int factory_idx, int object_idx);
    static void PrintHelp();

    uint64_t DoReplLoop(uint64_t current_evt_nr);

private:
    std::string StringifyEvent();
    std::string StringifyFactories();
    std::string StringifyFactory(int factory_idx);
    std::string StringifyJObjects(int factory_idx);
    std::string StringifyJObject(int factory_idx, int object_idx);
    std::string StringifyAncestors(int factory_idx);
    std::string StringifyAssociations(int factory_idx, int object_idx);

    void BuildIndices();

    std::pair<std::string, std::vector<int>> Parse(std::string);
};


#endif // _JIntrospection_h_