// We need to add and remove an element in O(1) 
// thus we need to use linked list over an array because 
// to shift the element after deletion, we need O(n) time
// with the linked list we can assign two pointers at head and tail
// and just adjust head and tail accordingly

// for checking whether the element is in the cache already or not
// we use hashtable, (unordered_map), where we store the address and the value
// this lookup becomes O(1) as well; (instead of traversal in O(n))

#include<bits/stdc++.h>
int _capacity;
list<int> _keys;
unordered_map<int, pair<int, list<int>::iterator>> _map;

// front denotes the recent and back denotes the least recent in this code

LRUCache::LRUCache(int capacity) 
{
    _map.clear(); // need to clear the global variables
    _keys.clear(); // ________ ,, _____________________
    _capacity = capacity;
}

int LRUCache::get(int key) 
{
    if(_map.find(key) != _map.end()) // if element exists in the  map
    {
         _keys.erase(_map[key].second); // remove the element
        _keys.push_front(key); // put it in front of it 
        _map[key].second = _keys.begin(); // set the new node postion of that element in the map
        return _map[key].first; // return the value;
    }
    else
        return -1;
}

void LRUCache::set(int key, int value) 
{
    if(_map.find(key) != _map.end())
        {
            _keys.erase(_map[key].second); // remove it
            _keys.push_front(key); // put it in the beginning
            _map[key] = {value, _keys.begin()}; // update the map for value and position
        }
    else
    {
        // check the capacity
        if(_keys.size() >= _capacity) // if exceeded
        {
            _map.erase(_keys.back()); // remove the least recent element from the map
            _keys.pop_back();              // and from the list
        }
        // insert in the beginning regardless (if capacity is full we remove and then add otherwise just add)
        _keys.push_front(key);               // insert the new key in the beginning of the list and update it
        _map[key] = {value, _keys.begin()};  // in the  map as well
    }

}