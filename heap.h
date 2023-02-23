#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int scale_;
  PComparator comp_;


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
    scale_ = m;
    comp_ = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
    data_.push_back(item);
    std::size_t index = data_.size() - 1;
    while (index != 0) {
        std::size_t parent_index = (index - 1) / scale_;
        T& current = data_[index];
        T& parent = data_[parent_index];
        if (comp_(parent, current)) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;
    }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("oops");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  // for (size_t i = 0; i < data_.size(); i++){
  //     std::cout << "index " << i << ": "<< data_[i] << " ";
  // }
  // std::cout << std::endl;
  return data_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("oops");
  }

  // TO BE COMPLETETED
		//swap top with last element and pop_back
		int last = data_.size() - 1;
    std::swap(data_[0],data_[last]);
    //std::cout << "last: " << data_[last]<< std::endl;
		//std::cout << "pop size: " << data_.size() << std::endl; 
    data_.pop_back();

		std::size_t index = 0;
		std::size_t final = data_.size() - 1;
    //std::cout << "final value: " << data_[0] << std::endl;
    if (data_.size() < 2){
        return;
    }
    while(index <= final){
    //std::cout << "index: " << data_[index]<< std::endl;
    std::size_t max_index = index*scale_ + 1;

    
    if (final >= max_index + scale_ - 1){
        
        //std::cout << final << " " << max_index<< std::endl;
        size_t j = max_index;
        for (size_t i = j + 1; i < scale_ + j; i++){
          //std::cout << scale_ + max_index << std::endl;
          if (comp_(data_[i],data_[max_index])){
            max_index = i;
          }
        }
        
    
        T& current = data_[index];
        //std::cout << final << " " << max_index<< std::endl;
        T& max_child = data_[max_index];
        if (comp_(current, max_child)){
            break;
        }
        std::swap(current, max_child);

        index = max_index;
    }

    else if (final < max_index + scale_ - 1){
        int numChild = final - max_index + 1;
        //std::cout << "child: " << numChild << std::endl;
        for (size_t i = max_index; i < final + 1; i++){
          if (comp_(data_[i], data_[max_index])){
            max_index = i;
          }
        }

        if (numChild < 1){
          break;
        }

        //if 
        
        T& current = data_[index];
        //std::cout << final << " " << max_index<< std::endl;
        T& max_child = data_[max_index];
        if (comp_(current, max_child)){
          break;
        }
        std::swap(current, max_child);
        break;
    }
    else{
        break;
    }
  
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  if (this->size() == 0){
    return true;
  }
  else {
    return false;
  }
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return data_.size();
}



#endif

