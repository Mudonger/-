/*
ͷ�ļ���
    ���Ա������ʵ��
    �����Գ�����linearList����ȷ��ʵ��ADT�����з���
    ʹ��STL�㷨�򻯴���
    ����������
*/
#ifndef arrayList_
#define arrayList_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

using namespace std;

template<class T>
class arrayList : public linearList<T> 
{
   public:
       // ���죨������
      arrayList(int initialCapacity = 10);
      // ���죨���ƣ�
      arrayList(const arrayList<T>&);
      // ������ɾ����
      ~arrayList() {delete [] element;}

      /*ADT ����*/
      // �գ�
      bool empty() const {return listSize == 0;}
      // ����
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;

      /*����ķ���*/
      // ����
      int capacity() const {return arrayLength;}
      
      // ������
      class iterator;
      iterator begin() {return iterator(element);}
      iterator end() {return iterator(element + listSize);}

      // ˳���ĵ�����
      class iterator
      {
      public:
          // ˫�������
          typedef bidirectional_iterator_tag iterator_category;
          typedef T value_type;
          typedef ptrdiff_t difference_type;
          typedef T* pointer;
          typedef T& reference;

          // ����
          iterator(T* thePosition = 0) { position = thePosition; }

          // ����
          T& operator*() const { return *position; }
          T* operator->() const { return &*position; }

          // ǰ��
          iterator& operator++()
          {
              ++position;
              return *this;
          }
          // ����
          iterator operator++(int)
          {
              iterator old = *this;
              ++position;
              return old;
          }

          // ǰ��
          iterator& operator--()
          {
              --position; return *this;
          }
          // ���
          iterator operator--(int)
          {
              iterator old = *this;
              --position;
              return old;
          }

          // ��ȼ��
          bool operator!=(const iterator right) const
          {
              return position != right.position;
          }
          bool operator==(const iterator right) const
          {
              return position == right.position;
          }
      protected:
          T* position;
      };

protected:
    // arrayList��������Ա
    // �������
    void checkIndex(int theIndex) const;
    T* element;           // ˳����е�Ԫ��
    int arrayLength;      // ˳���ĳ���
    int listSize;         // ˳����Ԫ�ظ���
};
// ���죨������
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}
// ���죨���ƣ�
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}
// �������������
template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

}
// ��ȡ
template<class T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}
// ����
template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    // ����
    if (theIndex == listSize)
        // û���ҵ��򷵻�-1
        return -1;
    else
        return theIndex;
}
// ɾ��
template<class T>
void arrayList<T>::erase(int theIndex)
{
    // �������
    checkIndex(theIndex);
    // ���������ȫ����ǰ�ƶ�һλ
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    // ����ط��ĵ������������Ҿ��úܹ��졭�����Ǻ�����
    element[--listSize].~T();
}
// ����
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    // �������������
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
   // ���ռ��Ƿ����
   if (listSize == arrayLength)
      {
        // ����
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
      }

   // ȫ������ƶ�һ��
   copy_backward(element + theIndex, element + listSize, element + listSize + 1);
   
   element[theIndex] = theElement;

   listSize++;
}
// ����������������˼��ž��ǽ����ֵ�����������Ȼ�󡭡��õ����������
template<class T>
void arrayList<T>::output(ostream& out) const
{
   copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// ���� <<
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
    x.output(out); return out;
}

#endif
