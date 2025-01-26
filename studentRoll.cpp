#include <string>
#include "studentRoll.h"
using namespace std;

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  // STUB
  Node* newNode = new Node();
  newNode -> s = new Student(s);
  newNode -> next = NULL;

  if(head == NULL){
    head = newNode;
    tail = newNode;
  }
  else{
    tail->next = newNode;
    tail = newNode;
  }
}

std::string StudentRoll::toString() const {
  //return "stub";
  if (head==NULL){
    return "[]";
  }
  string result = "[";
  Node* temp = head;
  while(temp!=nullptr){
    result += "[";
    result += temp->s->getName();
    result += ",";
    result += to_string(temp->s->getPerm());
    result += "]";
  
  if(temp->next!= NULL){
    result += ",";
  }
  temp = temp -> next;
}
result += "]";
return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = tail = NULL;
  Node* temp = orig.head;
  while (temp!=NULL){
    this->insertAtTail(*temp->s);
    temp = temp->next;
  }
}

StudentRoll::~StudentRoll() {
  // STUB
  Node* current = head;
  while(current != nullptr){
    Node* NodeToDelete = current;
    current = current -> next;
    delete NodeToDelete -> s;
    delete NodeToDelete;
  }
  head = nullptr;
  tail = nullptr;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
    Node* now = head;
    while(now!= NULL){
      Node* temp = now;
      now = now -> next;
      delete temp ->s;
      delete temp;
      
    }
    head= tail = NULL;

    Node* rNow = right.head;
    while(rNow != NULL){
      this->insertAtTail(*(rNow->s));
      rNow = rNow->next;
    }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





