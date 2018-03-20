
C++ London University Iterators Exercise
========================================

For this exercise you have been provided with a simplified, stripped-down
`simple_vector` class. Its `iterator` type is `vector_iterator<T>`.

Your task is to fill in `vector_iterator<T>` so that it (eventually) meets the
requirements of a standard library Random Access Iterator.

Exercise 1 - Basic Iterator Requirements
----------------------------------------

Update `vector_iterator<T>` to meet the basic Iterator requirements, namely:

 * Add member typedefs
   - `value_type`
   - `difference_type`
   - `reference`
   - `pointer`
   - `iterator_category`
   

 * Add a dereference operator (`operator*()`)
 
 * Add a pre-increment opreator (`operator++()`), returning `vector_iterator<T>&`
 
The formal requirements can be found at [http://en.cppreference.com/w/cpp/concept/Iterator].


Exercise 2 -- Input Iterator Requirements
-----------------------------------------

Update `vector_iterator<T>` to meet the Input Iterator requirements, namely:

 * `vector_iterator<T>` should be equality comparable (`operator==()` and `operator!=()`)
 
 * The dereference operator should return a reference to the contained element
 
 * Add a member access operator (`operator->()`)
 
 * Add a post-increment operator (`operator++(int)`), which increments the iterator
   but returns an iterator to the original element
   
 * The member typedef `iterator_category` must be set appropriately

   
The formal requirements can be found at [http://en.cppreference.com/w/cpp/concept/InputIterator].
   
Exercise 3 -- Forward Iterator Requirements
-------------------------------------------

Update `vector_iterator<T>` to meet the Forward Iterator requirements, namely:

 * `vector_iterator<T>` should be default constructible
 
 * The member typedef `reference` must be `T&`
 
 * The post-increment operator must return a new `vector_iterator<T>` instance
 
 * The member typedef `iterator_category` must be updated appropriately
 
The formal requirements can be found at [http://en.cppreference.com/w/cpp/concept/ForwardIterator].

Exercise 4 -- Bidirectional Iterator Requirements
-------------------------------------------------

Update `vector_iterator<T>` to meet the Bidirectional Iterator requirements, namely:

 * Add a pre-decrement operator, with the appropriate return type
 
 * Add a post-decrement operator, with the appropriate return type
 
 * The member typedef `iterator_category` must be updated appropriately
 
The formal requirements can be forund at [http://en.cppreference.com/w/cpp/concept/BidirectionalIterator].

Exercise 5 -- Random Access Iterator Requirements
-------------------------------------------------

Given the requirements at [on cppreference](http://en.cppreference.com/w/cpp/concept/RandomAccessIterator),
update `vector_iterator<T>` so that it is a valid Random Access Iterator.

 
