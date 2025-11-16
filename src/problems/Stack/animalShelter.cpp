#include <iostream>
#include <vector>
#include "../../DataStructures/LinkedList.cpp"

enum AniType {cat, dog};
using namespace std;

struct Animal{
    int age;
    AniType type;

    void printAnimal(){
        cout<<"Age, type: "<<age<<(type == cat ? "C" : "D")<<endl;
    }

    bool operator==(Animal secondAnimal){
        return ((age == secondAnimal.age) && (type = secondAnimal.type));
    }
};

class SortedLinkedList : public LinkedList<Animal>{
    public:
    void insertAnimal(node<Animal> *ani){
        node<Animal> *iter = root, *tmp;
        if (iter == nullptr || ani->val.age > iter->val.age){
            ani->next = iter;
            root = ani;
            return;
        }
        while(iter->next != nullptr && ani->val.age < iter->next->val.age){
            iter = iter->next;
        }
        
        tmp = iter->next;
        iter->next = ani;
        ani->next = tmp;
    }
};

class AnimalShelter {
    private:
        SortedLinkedList dogs, cats;

    public:
        void enqueue(Animal ani){
            node<Animal> *newAniNode = dogs.createNode(ani);
            if (ani.type == cat){
                cats.insertAnimal(newAniNode);
            } else {
                dogs.insertAnimal(newAniNode);
            }

        }

        AnimalShelter(){}
        
        Animal dequeAny() {
            Animal val;
            if (dogs.getRoot() == NULL) return cats.getRoot()->val;
            if (cats.getRoot() == NULL) return dogs.getRoot()->val;
            if (dogs.getRoot()->val.age > cats.getRoot()->val.age){
                val = dogs.getRoot()->val;
                dogs.deleteNodeWithVal(val);
            } else {
                val = cats.getRoot()->val;
                cats.deleteNodeWithVal(val);
            }
            return val;
        }

        Animal dequeDog() {
            Animal val;
            val = dogs.getRoot()->val;
            dogs.deleteNodeWithVal(val);
            return val;
        }

        Animal dequeCat() {
            Animal val;
            val = cats.getRoot()->val;
            cats.deleteNodeWithVal(val);
            return val;
        }

        void printLists(){
            dogs.printList();
            cats.printList();
        }

};


int main(int argc, char const *argv[])
{
    Animal a1, a2, a3, a4;
    AnimalShelter shelter;
    cout <<"reaches here"<<endl;
    a1.age = 23, a1.type = cat;
    a2.age = 24, a2.type = cat;
    a3.age = 12, a3.type = dog;
    a4.age = 45, a4.type = dog;
    shelter.enqueue(a1);
    shelter.enqueue(a1);
    shelter.enqueue(a1);
    shelter.enqueue(a1);
    shelter.printLists();
    shelter.dequeAny().printAnimal();
    cout << "reaches here 2" << endl;
    shelter.dequeCat().printAnimal();
    return 0;
}
