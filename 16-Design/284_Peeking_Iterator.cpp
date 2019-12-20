/*
Given an Iterator class interface with methods: next() and hasNext(), design and
implement a PeekingIterator that support the peek() operation -- it essentially
peek() at the element that will be returned by the next call to next().

Example:
Assume that the iterator is initialized to the beginning of the list: [1,2,3].
Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after
that still return 2.
You call next() the final time and it returns 3, the last element.
Calling hasNext() after that should return false.

Hint:
Think of "looking ahead". You want to cache the next element.
Is one variable sufficient? Why or why not?
Test your design with call order of peek() before next() vs next() before
peek().
For a clean implementation, check out Google's guava library source code.
Follow up : How would you extend your design to be generic and work with all
types, not just integer?
*/

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _flag = false;
    }

    int peek() {
        if (!_flag) _value = Iterator::next();
        _flag = true;
        return _value;
    }

    int next() {
        if (!_flag) return Iterator::next();
        _flag = false;
        return _value;
    }

    bool hasNext() const {
        return _flag || Iterator::hasNext();
    }

private:
    int _value;
    bool _flag;
};
