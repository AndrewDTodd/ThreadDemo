//
//  LinkedList.h
//  ThreadProject
//
//  Created by Andrew Todd on 4/15/19.
//  Copyright © 2019 Andrew Todd. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

template<typename Type>
class Node
{
    //template<typename Type>
    //friend class LinkedList<Type>;
public:
    Node<Type>* m_Prev = nullptr;
    Node<Type>* m_Next = nullptr;
public:
    Type* m_Element = nullptr;
    Node()
    {
        this->m_Next = nullptr;
        this->m_Prev = nullptr;
        this->m_Element = nullptr;
    }
    ~Node()
    {
        this->m_Next = nullptr;
        this->m_Prev = nullptr;
        this->m_Element = nullptr;
    }
};

template<typename Type>
class LinkedList
{
public:
    Node<Type> m_root;
    
    size_t m_listLength = 0;
    
    LinkedList()
    {
        
    }
    LinkedList(Type* elements, const size_t& arraySize)
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (this->m_root.m_Next == nullptr)
            {
                this->AddFirst(&elements[i]);
            }
            
            else
            {
                this->PrependNode(&elements[i]);
            }
        }
    }
    LinkedList(LinkedList<Type>&& list)
    :m_root(list.m_root), m_listLength(list.m_listLength)
    {
        list.m_root = nullptr;
        list.m_listLength = 0;
        list.~LinkedList();
    }
    LinkedList(const LinkedList<Type>& list)
    {
        this->m_root = list.m_root;
        this->m_listLength = list.m_listLength;
    }
    
    ~LinkedList()
    {
        if (this->m_listLength != 0)
        {
            this->emptyListDeleteDynam();
        }
    }
    
    void AddFirst(Type* element)
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->m_Element = element;
        newNode->m_Next = &this->m_root;
        newNode->m_Prev = &this->m_root;
        this->m_root.m_Next = newNode;
        this->m_root.m_Prev = newNode;
        newNode = nullptr;
        this->m_listLength++;
    }
    void AddFirstDynam(Type&& element)
    {
        Node<Type>* newNode = new Node<Type>;
        this->m_root.m_Next = newNode;
        this->m_root.m_Prev = newNode;
        newNode->m_Element = new Type(element);
        newNode->m_Next = &this->m_root;
        newNode->m_Prev = &this->m_root;
        newNode = nullptr;
        this->m_listLength++;
    }
    void AddFirstDynam(const Type& element)
    {
        Node<Type>* newNode = new Node<Type>;
        this->m_root.m_Next = newNode;
        this->m_root.m_Prev = newNode;
        newNode->m_Element = new Type(element);
        newNode->m_Next = &this->m_root;
        newNode->m_Prev = &this->m_root;
        newNode = nullptr;
        this->m_listLength++;
    }
    
    void PrependNode(Type* element)
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->m_Element = element;
        newNode->m_Next = this->m_root.m_Next;
        newNode->m_Prev = &this->m_root;
        this->m_root.m_Next->m_Prev = newNode;
        this->m_root.m_Next = newNode;
        newNode = nullptr;
        this->m_listLength++;
    }
    void PrependNodeDynam(Type&& element)
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->m_Next = this->m_root.m_Next;
        newNode->m_Prev = &this->m_root;
        this->m_root.m_Next->m_Prev = newNode;
        this->m_root.m_Next = newNode;
        newNode->m_Element = new Type(element);
        newNode = nullptr;
        this->m_listLength++;
    }
    void PrependNodeDynam(const Type& element)
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->m_Next = this->m_root.m_Next;
        newNode->m_Prev = &this->m_root;
        this->m_root.m_Next->m_Prev = newNode;
        this->m_root.m_Next = newNode;
        newNode->m_Element = new Type(element);
        newNode = nullptr;
        this->m_listLength++;
    }
    
    void AppendNode(Type* element)
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->m_Element = element;
        newNode->m_Prev = this->m_root.m_Prev;
        newNode->m_Next = &this->m_root;
        this->m_root.m_Prev->m_Next = newNode;
        this->m_root.m_Prev = newNode;
        newNode = nullptr;
        this->m_listLength++;
    }
    void AppendNodeDynam(Type&& element)
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->m_Prev = this->m_root.m_Prev;
        newNode->m_Next = &this->m_root;
        this->m_root.m_Prev->m_Next = newNode;
        this->m_root.m_Prev = newNode;
        newNode->m_Element = new Type(element);
        newNode = nullptr;
        this->m_listLength++;
    }
    void AppendNodeDynam(const Type& element)
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->m_Prev = this->m_root.m_Prev;
        newNode->m_Next = &this->m_root;
        this->m_root.m_Prev->m_Next = newNode;
        this->m_root.m_Prev = newNode;
        newNode->m_Element = new Type(element);
        newNode = nullptr;
        this->m_listLength++;
    }
    
    void InsertNode(Type* element, const size_t& index)
    {
        Node<Type>* newNode = new Node<Type>;
        if (this->m_root.m_Next == nullptr)
        {
            std::cout << "test" << std::endl;
            newNode->m_Element = element;
            this->m_root.m_Next = newNode;
            this->m_root.m_Prev = newNode;
            newNode->m_Prev = &this->m_root;
            newNode->m_Next = &this->m_root;
            newNode = nullptr;
            this->m_listLength++;
            return;
        }
        
        else
        {
            size_t count = -1;
            Node<Type>* prev = &this->m_root;
            Node<Type>* current = &this->m_root;
            while (current)
            {
                if (count == index)
                {
                    std::cout << "count" << count << "index" << index << std::endl;
                    std::cout << "current adress: " << current << " " << "current object: " << *current->element << std::endl;
                    newNode->m_Element = element;
                    prev->m_Next = newNode;
                    current->m_Prev = newNode;
                    newNode->m_Next = current;
                    newNode->m_Prev = prev;
                    newNode = nullptr;
                    prev = nullptr;
                    current = nullptr;
                    this->m_listLength++;
                    return;
                }
                
                if (index <= this->m_listLength / 2)
                {
                    prev = current;
                    current = prev->m_Next;
                }
                else
                {
                    prev = current;
                    current = prev->m_Prev;
                }
                count++;
            }
        }
    }
    void InsertNodeDynam(Type&& element, const size_t& index)
    {
        Node<Type>* newNode = new Node<Type>;
        if (this->m_root.m_Next == nullptr)
        {
            this->m_root.m_Next = newNode;
            this->m_root.m_Prev = newNode;
            newNode->m_Prev = &this->m_root;
            newNode->m_Next = &this->m_root;
            newNode->m_Element = new Type(element);
            newNode = nullptr;
            this->m_listLength++;
            return;
        }
        
        else
        {
            if (index <= this->m_listLength / 2)
            {
                Node<Type>* prev = &this->m_root->m_Next;
                Node<Type>* current = &this->m_root->m_Next;
                
                size_t count = 0;
            }
            else
            {
                Node<Type>* prev = &this->m_root->m_Prev;
                Node<Type>* current = &this->m_root->m_Prev;
                
                size_t count = this->m_listLength;
            }
            while (current)
            {
                if (count == index)
                {
                    std::cout << "count " << count << " index " << index << std::endl;
                    std::cout << "current adress: " << current << " " << "current object: " << *current->m_Element << std::endl;
                    std::cout << "prev adress: " << prev << " " << "prev object: " << *prev->m_Element << std::endl;
                    prev->m_Next = newNode;
                    current->m_Prev = newNode;
                    newNode->m_Next = current;
                    newNode->m_Prev = prev;
                    newNode->m_Element = new Type(element);
                    newNode = nullptr;
                    prev = nullptr;
                    current = nullptr;
                    this->m_listLength++;
                    return;
                }
                
                if (index <= this->m_listLength / 2)
                {
                    prev = current;
                    current = prev->m_Next;
                    
                    count++;
                }
                else
                {
                    prev = current;
                    current = prev->m_Prev;
                    
                    count--;
                }
            }
        }
    }
    void InsertNodeDynam(const Type& element, const size_t& index)
    {
        Node<Type>* newNode = new Node<Type>;
        if (this->m_root.m_Next == nullptr)
        {
            this->m_root.m_Next = newNode;
            this->m_root.m_Prev = newNode;
            newNode->m_Prev = this->m_root;
            newNode->m_Next = this->m_root;
            newNode->m_Element = new Type(element);
            newNode = nullptr;
            this->m_listLength++;
            return;
        }
        
        else
        {
            size_t count = 0;
            Node<Type>* prev = this->m_root;
            Node<Type>* current = this->m_root;
            while (current)
            {
                if (count == index)
                {
                    prev->m_Next = newNode;
                    current->m_Prev = newNode;
                    newNode->m_Next = current;
                    newNode->m_Prev = prev;
                    newNode->m_Element = new Type(element);
                    newNode = nullptr;
                    prev = nullptr;
                    current = nullptr;
                    this->m_listLength++;
                    return;
                }
                
                if (index <= this->m_listLength / 2)
                {
                    prev = current;
                    current = prev->m_Next;
                }
                else
                {
                    prev = current;
                    current = prev->m_Prev;
                }
                count++;
            }
        }
    }
    
    void removeFirst()
    {
        Node<Type>* node = this->m_root.m_Next;
        if (node->m_Next)
        {
            this->m_root.m_Next = node->m_Next;
            this->m_root.m_Next->m_Prev = &this->m_root;
        }
        else
        {
            this->m_root.m_Next = nullptr;
            this->m_root.m_Prev = nullptr;
        }
        node->m_Next = nullptr;
        node->m_Prev = nullptr;
        node->m_Element = nullptr;
        delete node;
        node = nullptr;
        this->m_listLength--;
    }
    void removeFirstDeleteDynam()
    {
        Node<Type>* node = this->m_root.m_Next;
        if (node->m_Next)
        {
            this->m_root.m_Next = node->m_Next;
            this->m_root.m_Next->m_Prev = &this->m_root;
        }
        else
        {
            this->m_root.m_Next = nullptr;
        }
        node->m_Next = nullptr;
        node->m_Prev = nullptr;
        delete node->element;
        node->m_Element = nullptr;
        delete node;
        node = nullptr;
        this->m_listLength--;
    }
    
    void removeLast()
    {
        Node<Type>* node = this->m_root.m_Prev;
        this->m_root.m_Prev = node->m_Prev;
        this->m_root.m_Prev->m_Next = this->m_root;
        node->m_Next = nullptr;
        node->m_Prev = nullptr;
        node->m_Element = nullptr;
        delete node;
        node = nullptr;
        this->m_listLength--;
    }
    void removeLastDeleteDynam()
    {
        Node<Type>* node = this->m_root.m_Prev;
        this->m_root.m_Prev = node->m_Prev;
        this->m_root.m_Prev->m_Next = this->m_root;
        node->m_Next = nullptr;
        node->m_Prev = nullptr;
        delete node->element;
        node->m_Element = nullptr;
        delete node;
        node = nullptr;
        this->m_listLength--;
    }
    
    void removeNode(const size_t& index)
    {
        size_t count = 0;
        Node<Type>* prev = this->m_root;
        Node<Type>* current = this->m_root;
        while (current)
        {
            if (count == index)
            {
                if (index <= this->m_listLength / 2)
                {
                    prev->m_Next = current->m_Next;
                    current->m_Next->m_Prev = prev;
                    current->m_Next = nullptr;
                    current->m_Prev = nullptr;
                    current->m_Element = nullptr;
                    delete current;
                    current = nullptr;
                    prev = nullptr;
                    this->m_listLength--;
                    return;
                }
                
                else
                {
                    prev->m_Prev = current->m_Prev;
                    current->m_Prev->m_Next = prev;
                    current->m_Next = nullptr;
                    current->m_Prev = nullptr;
                    current->m_Element = nullptr;
                    delete current;
                    current = nullptr;
                    prev = nullptr;
                    this->m_listLength--;
                    return;
                }
            }
            
            if (index <= this->m_listLength / 2)
            {
                prev = current;
                current = prev->m_Next;
            }
            else
            {
                prev = current;
                current = prev->m_Prev;
            }
            count++;
        }
    }
    void removeNodeDeleteDynam(const size_t& index)
    {
        size_t count = 0;
        Node<Type>* prev = this->m_root;
        Node<Type>* current = this->m_root;
        while (current)
        {
            if (count == index)
            {
                if (index <= this->m_listLength / 2)
                {
                    prev->m_Next = current->m_Next;
                    current->m_Next->m_Prev = prev;
                    current->m_Next = nullptr;
                    current->m_Prev = nullptr;
                    delete current->element;
                    current->m_Element = nullptr;
                    delete current;
                    current = nullptr;
                    prev = nullptr;
                    this->m_listLength--;
                    return;
                }
                
                else
                {
                    prev->m_Prev = current->m_Prev;
                    current->m_Prev->m_Next = prev;
                    current->m_Next = nullptr;
                    current->m_Prev = nullptr;
                    delete current->element;
                    current->m_Element = nullptr;
                    delete current;
                    current = nullptr;
                    prev = nullptr;
                    this->m_listLength--;
                    return;
                }
            }
            
            if (index <= this->m_listLength / 2)
            {
                prev = current;
                current = prev->m_Next;
            }
            else
            {
                prev = current;
                current = prev->m_Prev;
            }
            count++;
        }
    }
    
    void emptyList()
    {
        if (this->m_listLength == 0)
        {
            return;
        }
        Node<Type>* currentNode = this->m_root.m_Prev;
        for (int i = 0; i < this->m_listLength; i++)
        {
            this->m_root.m_Prev = currentNode->m_Prev;
            delete currentNode;
            currentNode = this->m_root.m_Prev;
        }
        
        this->m_listLength = 0;
        this->m_root.m_Next = nullptr;
        this->m_root.m_Prev = nullptr;
    }
    void emptyListDeleteDynam()
    {
        if (this->m_listLength == 0)
        {
            return;
        }
        Node<Type>* currentNode = this->m_root.m_Prev;
        while(currentNode != &this->m_root)
        {
            this->m_root.m_Prev = currentNode->m_Prev;
            if (currentNode->m_Element)
            {
                delete currentNode->m_Element;
                this->m_listLength--;
            }
            delete currentNode;
            currentNode = this->m_root.m_Prev;
        }
        
        this->m_root.m_Next = nullptr;
        this->m_root.m_Prev = nullptr;
    }
    
    template<typename type>
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList<type>& list)
    {
        if (list.m_listLength == 0)
        {
            stream << "List empty" << "\n";
            return stream;
        }
        Node<type>* current = list.m_root.m_Next;
        for (int i = 0; i < list.m_listLength; i++)
        {
            stream << "Node" << "[" << i << "]" << "\n" << *current->m_Element << "\n";
            
            current = current->m_Next;
        }
        
        stream << "\n";
        return stream;
    }
    
    Node<type>* searchForward(const type& item, bool* itemFound)
    {
        Node<type>* current = this->m_root.m_Next;
        for (int i = 0; i < this->m_listLength; i++)
        {
            if(*itemFound == true)
                return nullptr;
            
            if(*current->m_Element == item)
            {
#ifdef DEBUG
                std::cout << "index: " << i << std::endl;
#endif
                *itemFound = true;
                return current;
            }
            
            current = current->m_Next;
        }
    }
    Node<type>* searchBackward(const type& item, bool* itemFound)
    {
        Node<type>* current = this->m_root.m_Prev;
        for(int i = 0; i < this->m_listLength; i++)
        {
            if(*itemFound == true)
                return nullptr;
            if(*current->m_Element == item)
            {
#ifdef DEBUG
                std::cout << "index: " << i << std::endl;
#endif
                *itemFound = true;
                return current;
            }
            
            current = current->m_Prev;
        }
    }
};

#endif /* LinkedList_h */
