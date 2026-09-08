#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string &val) {
  if(tail_ == NULL || tail_->last==ARRSIZE){
    Item* item = new Item;
    item->prev = tail_;

    if (tail_ != NULL) {
      tail_->next = item;
    }
    else {
      head_ = item; 
    }
    tail_ = item; 
  }
  tail_->val[tail_->last] = val;
  ++tail_->last;
  ++size_;
}

void ULListStr::push_front(const std::string& val) {
  if(head_==NULL || head_->first == 0) {
    Item* item = new Item;
    item->first=ARRSIZE;
    item->last=ARRSIZE;
    item->next =head_;

    if(head_ != NULL){
      head_->prev = item;
    }
    else{
      tail_= item;
    }
    head_ = item;
  }
  --head_->first;
  head_->val[head_->first] = val;
  ++size_;

}
void ULListStr::pop_back() {
  if(empty()){
    return;
  }

  --tail_->last;
  tail_->val[tail_->last].clear();
  --size_;

  if(tail_->first == tail_->last){
    Item* oldTail = tail_;
    tail_ = tail_->prev;

    if(tail_ != NULL){
      tail_->next = NULL;
    }
    else{
      head_= NULL;
    }
    delete oldTail;
  }
}
void ULListStr::pop_front(){
  if(empty()) {
    return; 
  }

  head_->val[head_->first].clear();
  ++head_->first;
  --size_; 
  if(head_->first == head_->last){
    Item* oldHead = head_;
    head_ = head_->next;

    if(head_ != NULL){
      head_->prev = NULL;
    }
    else{
      tail_ = NULL;
    }
    delete oldHead;
  }
}
std::string const& ULListStr::back() const {
  return tail_->val[tail_->last -1];
}
std::string const& ULListStr::front() const {
  return head_->val[head_->first];
}
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(loc >= size_){
    return NULL;
  }
 Item* current = head_;
 while(current != NULL){
  size_t itemSize = current->last - current->first;
  if(loc <itemSize){
    return &(current->val[current->first +loc]);
  }
  loc -= itemSize;
  current = current ->next;
 }
 return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
