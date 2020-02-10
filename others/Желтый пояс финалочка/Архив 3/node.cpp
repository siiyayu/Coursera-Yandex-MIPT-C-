#include "node.h"

template<class T>
bool Compare(Comparison cmp, T& lhs, T& rhs) {
    switch (cmp) {
        case Comparison::Less :
            return lhs < rhs;
        case Comparison::LessOrEqual :
            return lhs <= rhs;
        case Comparison::Greater :
            return lhs > rhs;
        case Comparison::GreaterOrEqual :
            return lhs >= rhs;
        case Comparison::Equal :
            return lhs == rhs;
        case Comparison::NotEqual :
            return lhs != rhs;
    }
}

bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(_cmp, date, _date);
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    return Compare(_cmp, event, _event);
}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    if (_op == LogicalOperation::And) {
        return _lhs->Evaluate(date, event) && _rhs->Evaluate(date, event);
    } else {
        return _lhs->Evaluate(date, event) || _rhs->Evaluate(date, event);
    }
}