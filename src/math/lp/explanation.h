/*++
Copyright (c) 2017 Microsoft Corporation

Module Name:

    <name>

Abstract:

    <abstract>

Author:
    Nikolaj Bjorner (nbjorner)
    Lev Nachmanson (levnach)

Revision History:


--*/
#pragma once
#include <unordered_set>
#include "math/lp/lp_utils.h"
#include "util/hashtable.h"

namespace lp {
class explanation {
    int_hashtable<int_hash, default_eq<int> > m_set;

public:
    explanation() {}
    template <typename T>
    explanation(const T& t) { for ( unsigned c : t) add(c); }
    
    void clear() { m_set.reset(); }
    int_hashtable<int_hash, default_eq<int>>::iterator begin() const { return m_set.begin(); }
    int_hashtable<int_hash, default_eq<int>>::iterator end() const { return m_set.end(); }

    void add(unsigned j) {
        m_set.insert(j);
    }

    void push_back(unsigned j) {
        add(j);
    }

    template <typename T>
    void add(const T& e) { for (unsigned j: e) add(j); }
    
    bool empty() const {  return m_set.empty();  }
    size_t size() const { return m_set.size(); }
};
}
